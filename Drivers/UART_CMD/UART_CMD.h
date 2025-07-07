/**
 * @file    UART_CMD.h
 * @brief   Interface para o módulo de processamento de comandos via UART.
 * @date    Jul 6, 2025
 * @author  wande
 */

#ifndef UART_CMD_H
#define UART_CMD_H

#include "main.h"

/**
 * @brief Byte recebido via UART, usado para processar comandos.
 *
 * Deve ser preenchido no callback de recepção (`HAL_UART_RxCpltCallback`)
 * e passado para a função `UART_CMD_Process`.
 */
extern uint8_t uart_rx_byte;

/**
 * @brief Processa um byte recebido via UART e executa comandos reconhecidos.
 *
 * Essa função deve ser chamada dentro da interrupção de recepção de UART.
 * Acumula caracteres até o fim da linha (`\r`) e compara com os comandos válidos.
 *
 * @param byte Byte recebido via UART.
 */
void UART_CMD_Process(uint8_t byte);

#endif /* UART_CMD_H */
