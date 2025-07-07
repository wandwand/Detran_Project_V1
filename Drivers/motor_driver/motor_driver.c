/**
 * @file    motor_driver.c
 * @brief   Driver de controle de motor DC com controle PWM unidirecional e reverso.
 * @date    Jul 6, 2025
 * @author  wande
 */


#include "motor_driver.h"

extern TIM_HandleTypeDef htim3;
extern UART_HandleTypeDef huart1;

#define PWM_MAX 625

// Variáveis de controle de estado
static volatile uint8_t pwm_dir = 0;     /**< 1 = frente (FWD), 2 = ré (REV) */
static volatile uint8_t pwm_active = 0;  /**< Flag que indica se a rampa PWM está ativa */
static volatile uint16_t pwm_value = 0;  /**< Valor atual do duty cycle PWM */

/**
 * @brief  Inicia o PWM no sentido frente (FWD).
 * @note   Apenas inicia se nenhum outro ciclo estiver em andamento.
 * @retval Nenhum
 */

void start_pwm_fwd(void)
{
    if (pwm_active) return;
    pwm_dir = 1;
    pwm_active = 1;
    HAL_UART_Transmit(&huart1, (uint8_t*)"Iniciando FWD...\r\n", 18, HAL_MAX_DELAY);
}

/**
 * @brief  Inicia o PWM no sentido reverso (REV).
 * @note   Apenas inicia se nenhum outro ciclo estiver em andamento.
 * @retval Nenhum
 */

void start_pwm_rev(void)
{
    if (pwm_active) return;
    pwm_dir = 2;
    pwm_active = 1;
    HAL_UART_Transmit(&huart1, (uint8_t*)"Iniciando REV...\r\n", 18, HAL_MAX_DELAY);
}

/**
 * @brief  Para o PWM e zera o duty cycle.
 * @retval Nenhum
 */

void stop_pwm(void)
{
    pwm_active = 0;
    pwm_dir = 0;
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
    HAL_UART_Transmit(&huart1, (uint8_t*)"Motor parado.\r\n", 16, HAL_MAX_DELAY);
}

/**
 * @brief  Executa uma rampa de PWM de 0 até PWM_MAX.
 * @note   Direção e pinos de controle devem estar configurados antes da chamada.
 * @retval Nenhum
 */

void pwm_ramp_task(void)
{
    if (!pwm_active) return;

    // Ajusta direção de sentido...
    if (pwm_dir == 1) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
    } else {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
    }

    for (uint16_t i = 0; i <= PWM_MAX ; i++) {
            __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, i);
            HAL_Delay(1);
        }
    // **Garanta 100% de duty a partir daqui:**
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, PWM_MAX);

    char msg[32];
    snprintf(msg, sizeof(msg), "%s concluído.\r\n",
             (pwm_dir == 1) ? "FWD" : "REV");
    HAL_UART_Transmit(&huart1, (uint8_t*)msg, strlen(msg), HAL_MAX_DELAY);

    pwm_active = 0;
}
