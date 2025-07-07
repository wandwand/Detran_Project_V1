/**
 * @file    motor_driver.h
 * @brief   Interface do driver para controle de motor DC com PWM.
 * @date    Jul 6, 2025
 * @author  wande
 */

#ifndef MOTOR_DRIVER_MOTOR_DRIVER_H_
#define MOTOR_DRIVER_MOTOR_DRIVER_H_

#include "main.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Inicia a rampa PWM no sentido frente (FWD).
 *
 * Ativa a flag de controle e define o sentido para frente.
 * A função `pwm_ramp_task()` deve ser chamada em um loop ou scheduler
 * para que a rampa seja executada.
 */
void start_pwm_fwd(void);

/**
 * @brief Inicia a rampa PWM no sentido reverso (REV).
 *
 * Ativa a flag de controle e define o sentido para ré.
 * A função `pwm_ramp_task()` deve ser chamada em um loop ou scheduler
 * para que a rampa seja executada.
 */
void start_pwm_rev(void);

/**
 * @brief Interrompe o sinal PWM e reseta os parâmetros internos.
 */
void stop_pwm(void);

/**
 * @brief Executa a rampa de PWM de 0 até PWM_MAX com base no sentido configurado.
 *
 * Essa função deve ser chamada ciclicamente no `main()` ou em uma tarefa dedicada,
 * e atua apenas quando a flag de `pwm_active` estiver habilitada por
 * start_pwm_fwd()` ou `start_pwm_rev()`.
 */
void pwm_ramp_task(void);

#ifdef __cplusplus
}
#endif

#endif /* MOTOR_DRIVER_MOTOR_DRIVER_H_ */

