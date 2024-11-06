Projeto de Introdução a Computação

Sistema de Segurança residencial de alarme com senha, integrado com um arduíno
e um lcd para comunicação pessoa-dispositivo.
Para a execução, deve-se usar:
1. 1 Arduino
2. 1 Protoboard
3. 1 Teclado Matricial 4x3
4. 1 Tela LCD (I2C)
5. 1 Sensor PIR
6. 1 Buzzer

  Usaremos a protoboard para fazer as ligações com o Buzzer e o Sensor PIR,
Além de unir as ligações no GND e 5V.
  A tela LCD, com o auxílio da biblioteca LiquidCrystal I2C.h, será ligada 
com apenas 4 ligações: SDA → A4 (analógica); SCL →A5(analógica); GND → GND;
VCC → 5V.
  Para o teclado usaremos 7 portas digitais e 7 ligações: linhas 1, 2, 3 e 4
(portas digitais 13, 12, 11 e 10) e colunas 1, 2 e 3 (portas digitais 9, 8 e 7).
  O Buzzer é ligado com uma resistência de 1000Ω, onde a parte negativa é
ligada ao GND e a postitiva é ligada à porta analógica A0. Para o Sensor PIR
é utilizado uma porta analógica A3, o GND e o 5V.

Projeto no Tinkercad:
https://www.tinkercad.com/things/6rm2wCiIoAv-projeto-ic
