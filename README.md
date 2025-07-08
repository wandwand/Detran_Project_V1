##  1. Especificação dos Componentes Utilizados

| Quantidade | Componente                            | Observações                          |
|------------|---------------------------------------|--------------------------------------|
| 1x         | STM32G030F6P6                         | Microcontrolador principal           |
| 1x         | FTDI232                               | Conversor USB ↔ UART                 |
| 1x         | Cabo USB x USB Mini(Energia + Dados)  | Coonexão do FTDI232 ↔ PC             |
| 1x         | STLINK V2                             | Gravador/debugger via SWD            |
| 1x         | Potenciômetro 10k                     | Simulação de sinal analógico         |
| 3x         | Resistores 330Ω                       | Limitadores de corrente para LEDs    |
| 3x         | LEDs                                  | Simulação de carga (ex: motor DC)    |
| 1x         | Protoboard                            | Montagem rápida                      |
| Diversos   | Jumpers macho-macho                   | Conexões entre módulos               |
| Diversos   | Jumpers macho-fêmea                   | Conexões diversas                    |
| Diversos   | Jumpers fêmea-fêmea                   | Conexões diversas                    |

---

##  2. Softwares Utilizados

| Software       | Finalidade                             |
|----------------|----------------------------------------|
| STM32CubeIDE   | Desenvolvimento e gravação do firmware |
| PuTTY          | Comunicação serial via UART            |
| EASYEDA        | Esquemático do projeto                 |


---

##  3. Esquemáticos e Conexões

###  MCU: `STM32G030F6P6`

###  Simulação de Bateria:
- O potenciômetro de 10kΩ foi utilizado como um divisor de tensão, com o intuito de regular a tensão vista pelo ADC.
Ao regular o potenciômetro, podemos vizualizar uma mudança na tensão entre 0 - 3.3V(tensão da placa) e valores de 0 - 4095,
que representam uma amostragem de 12 bits pelo adc.

###  Simulação de Motor DC:
- LEDs utilizados para simular o controle de um motor DC são A8, A11 e A6. Sendo os dois primeiros de
  direção e o terceiro de movimento(ou pwm). Segue a tabela como referência, usando 1, como LED on e
  0 como LED off:

|A8 Pin  |A11 Pin| A16 Pin| Operação   |
|--------|-------|--------|------------|
| 1      | 0     | 0      | FWD        |
| 1      | 0     | 1      | FWD(Parado)|
| 0      | 1     | 0      | REV        |
| 0      | 1     | 1      | REV(Parado)|

![image](https://github.com/user-attachments/assets/06e14c49-f435-45a1-9f5a-bdb789d71d39)

Fonte: Próprio Autor, Software EASYEDA.

###  FTDI232 ↔ STM32G030F6P6 (Comunicação UART)

| FTDI232 Pin | STM32G030F6P6 Pin |
|-------------|-------------------|
| GND         | GND               |
| VCC         | 3.3V              |
| RX          | TX (ex: PA2)      |
| TX          | RX (ex: PA3)      |

###  STLINK V2 ↔ STM32G030F6P6 (Programação via SWD)

| STLINK V2 Pin | STM32G030F6P6 Pin |
|---------------|-------------------|
| SWDIO         | DIO (ex: PA13)    |
| SWCLK         | CLK (ex: PA14)    |
| GND           | GND               |
| 3.3V/VCC      | 3.3V/VPP          |

---

##  4. Guia Prático de Execução (Hands-on)

1. Monte os componentes conforme a tabela de conexões.
2. Compile e grave o firmware no STM32 usando o STM32CubeIDE.
3. Abra o PuTTY com a porta serial correta e 115200 bps.
4. Envie comandos via UART para interagir com o sistema.
5. Use o potenciômetro para simular a "tensão na bateria" analógica dinâmica.

---

##  5. Guia de Comandos UART

| Comando      | Ação                                                  |
|--------------|-------------------------------------------------------|
| `VBAT`       | Lê a tensão da bateria via ADC                        |
| `HELP`       | Lista os comandos disponíveis                         |
| `FWD`        | Liga os LEDs simulando o motor no sentido convencional|
| `REV`        | Liga os LEDs simulando o motor no sentido contrârio   |
| `STOP`       | Desliga o LED do PWM                                  |

---

##  6. Layout das Configurações e Fluxo de Comando

- **Timer 3, Canal 1**: Geração de PWM para acionamento dos LEDs.
- **ADC**: Leitura analógica do potenciômetro.
- **UART**: Comunicação com o terminal serial.


---

##  7. Utilização de Cada Componente

| Componente         | Finalidade                                                |
|--------------------|-----------------------------------------------------------|
| STM32G030F6P6      | Executa o firmware principal                              |
| FTDI232            | Interface USB ↔ UART para comandos e telemetria           |
| STLINK V2          | Programação e depuração do microcontrolador               |
| Potenciômetro 10k  | Geração de sinal analógico para o ADC                     |
| LEDs               | Simulam funcionamento de um motor                         |
| Resistores 330Ω    | Proteção dos LEDs contra sobrecorrente                    |
| Protoboard         | Montagem sem necessidade de solda                         |
| Jumpers diversos   | Conexões entre componentes e módulos                      |


---
##  8. Video de apresentação do projeto
https://youtube.com/shorts/Xiu0BaGgNZ0?si=5_VKTWtZ8QYceb8C
