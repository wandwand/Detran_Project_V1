/**
 * @file    UART_CMD.c
 * @brief   Módulo responsável pelo processamento de comandos via UART.
 * @date    Jul 6, 2025
 * @author  wande
 */

#include "uart_cmd.h"
#include "motor_driver.h"
#include "voltage_reader.h"
#include <string.h>

extern UART_HandleTypeDef huart1;

/// Tamanho máximo do buffer de comando UART.
#define UART_CMD_BUF_LEN 32

/// Buffer para armazenar os caracteres do comando recebido.
static char uart_cmd_buf[UART_CMD_BUF_LEN];

/// Índice do próximo caractere no buffer de comando.
static uint8_t uart_cmd_index = 0;

/// Byte de recepção UART (geralmente preenchido por interrupção).
uint8_t uart_rx_byte = 0;

/**
 * @brief Estrutura para mapear um comando UART e sua função associada.
 */
typedef struct {
    const char *cmd;              ///< String do comando reconhecido (ex: "FWD").
    void (*handler)(void);       ///< Função a ser executada ao reconhecer o comando.
} UART_Command;

/// Protótipo da função de ajuda.
static void help_cmd(void);

/// Tabela de comandos UART válidos e suas respectivas funções de tratamento.
static UART_Command cmd_table[] = {
    {"VBAT", read_voltage},  ///< Lê a tensão da bateria.
    {"FWD",  start_pwm_fwd}, ///< Inicia motor no sentido frente.
    {"REV",  start_pwm_rev}, ///< Inicia motor no sentido reverso.
    {"STOP", stop_pwm},      ///< Para o PWM do motor.
    {"HELP", help_cmd}       ///< Mostra comandos disponíveis.
};

/**
 * @brief Processa um byte recebido via UART e interpreta comandos.
 *
 * Essa função deve ser chamada dentro da `HAL_UART_RxCpltCallback`.
 * Acumula os caracteres até que um `\r` (carriage return) seja recebido.
 * Ao receber `\r`, compara o comando com a tabela e executa a função correspondente.
 *
 * @param byte Byte recebido via UART.
 */
void UART_CMD_Process(uint8_t byte)
{
    extern UART_HandleTypeDef huart1;

    if (byte == '\r') {
        uart_cmd_buf[uart_cmd_index] = '\0';

        uint8_t matched = 0;
        for (uint8_t i = 0; i < sizeof(cmd_table) / sizeof(UART_Command); i++) {
            if (strcasecmp(uart_cmd_buf, cmd_table[i].cmd) == 0) {
                cmd_table[i].handler();
                matched = 1;
                break;
            }
        }

        if (!matched) {
            const char *msg = "Comando inválido. Digite 'HELP'\r\n";
            HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);
        }

        uart_cmd_index = 0;
        memset(uart_cmd_buf, 0, sizeof(uart_cmd_buf));
    } else {
        if (uart_cmd_index < UART_CMD_BUF_LEN - 1) {
            uart_cmd_buf[uart_cmd_index++] = byte;
        }
    }
}

/**
 * @brief Imprime lista de comandos disponíveis via UART.
 */
static void help_cmd(void)
{
    extern UART_HandleTypeDef huart1;

    const char *help_str =
        "Comandos disponíveis:\r\n"
        "  VBAT - Ler tensão da bateria\r\n"
        "  FWD  - Frente\r\n"
        "  REV  - Ré\r\n"
        "  STOP - Para\r\n"
        "  HELP - Ajuda\r\n";


    HAL_UART_Transmit(&huart1, (uint8_t*)help_str, strlen(help_str), HAL_MAX_DELAY);
}

/* USER CODE BEGIN 4 */
/**
  * @brief Callback de interrupção de recepção UART.
  *
  * Esta função é chamada automaticamente pela HAL sempre que
  * um byte é recebido via UART1. Ela repassa o byte recebido
  * para o parser de comandos UART (UART_CMD_Process) e reinicia
  * a recepção em modo interrupção para continuar recebendo os
  * próximos comandos.
  *
  * @param huart Ponteiro para a estrutura de controle da UART que gerou a interrupção.
  */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart->Instance == USART1) {
        UART_CMD_Process(uart_rx_byte);
        HAL_UART_Receive_IT(&huart1, &uart_rx_byte, 1);
    }
}


