1. Especificação dos Componentes Utilizados
   - 1x STM32G0F6P6;
   - FTDI232;
   - STLINK V2;
   - 1x Potenciometro 10k;
   - 3x resistores 330 Ohms;
   - 3x LED's;
   - 1x Protoboard;
   - Jumpers macho-macho;
   - Jumpers macho-femea;
   - Jumpers femea-femea;
2.Softwares Uilizados
   - STM32CubeIDE;
   - Putty;
3. Esquematicos e conexões
   - STM32G030F6P6;
   - "Motor DC" (LED's e Potenciômetro);
   - FTDI232  <--> STM32G0F6P6 (Comunicação UART):
          GND <--> GND
          Vcc <--> 3.3V
          Rx  <--> Tx
          Tx  <--> Rx
   - STLINK V2  <--> STM32G0F6P6 (Gravar o firmware):
          SWDIO <--> DIO
          GND   <--> GND
          SWCLK <--> CLK
          3.3V  <--> VPP(3.3V)
4. Guia prático de como executar(Hands-on)
5. Guia de comandos
6. Layout das configurações, fluxo de comandos.
7. Explicar a utilização de cada componente
   

