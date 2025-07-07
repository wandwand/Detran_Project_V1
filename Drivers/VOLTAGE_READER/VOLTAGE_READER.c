/*
 * VOLTAGE_READER.c
 *
 *  Created on: Jul 6, 2025
 *      Author: wande
 */

/**
 * @brief  Lê a tensão da entrada analógica e envia via UART.
 * @note   Conversão assume referência de 3.3V e ADC de 12 bits.
 * @retval Nenhum
 */
void read_voltage(void);

#include "voltage_reader.h"

extern ADC_HandleTypeDef hadc1;
extern UART_HandleTypeDef huart1;

void read_voltage() {
    HAL_ADC_PollForConversion(&hadc1, 100);
    uint32_t readValue = HAL_ADC_GetValue(&hadc1);
    uint32_t voltage_mV = (readValue * 3300) / 4095;

    char tx_buf[64];
    int len = snprintf(tx_buf, sizeof(tx_buf),
        "ADC: %4lu | Tensão: %lu.%02lu V\r\n",
        readValue,
        voltage_mV / 1000,
        (voltage_mV % 1000) / 10);

    HAL_UART_Transmit(&huart1, (uint8_t*)tx_buf, len, HAL_MAX_DELAY);
}
