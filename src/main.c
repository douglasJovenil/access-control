#include "main.h"

uint8_t led_value[] = {0b00000000, 0b10000000, 0b11000000,
                       0b11100000, 0b11110000, 0b11111000,
                       0b11111100, 0b11111110, 0b11111111};
uint8_t index = 0;

void main() {
  definitions();
  while (TRUE) {
    if (index == 8) {
      LED_ENTRADA = HIGH;
      LED_SAIDA = HIGH;
      INT0IE = FALSE;
      INT1IE = FALSE;
      for (int i = 0; i < 5; i++) toggleTwoBits(&LATC, CLK2, 250);
      turnOff(&LATC, CLK2);
      LED_SAIDA = LOW;
      shiftLeftOff(&LATC, CLK1, 500);
      LED_ENTRADA = LOW;
      index = 0;
      INT0IE = TRUE;
      INT1IE = TRUE;
      LED_SAIDA = HIGH;
    }
  }
}

void __interrupt() highPriority() {
  if (INT0IF && INT0IE) entryInterrupt();
}

void __interrupt(low_priority) lowPriority() {
  if (INT1IF && INT1IE) outputInterrupt();
}

void entryInterrupt() {
  ;
  if (index < 8) index++;
  setLed(&LATC, CLK1, led_value[index], TRUE);
  INT0IF = FALSE;
}

void outputInterrupt() {
  if (index > 0) index--;
  setLed(&LATC, CLK1, led_value[index], TRUE);
  INT1IF = FALSE;
}

void numToArray(uint8_t num, uint8_t array[]) {
  for (int i = SIZE_BIN_ARRAY - 1; i >= 0; i--) {
    array[i] = (num > 0) ? (num % 2) : 0;
    num /= 2;
  }
}

void setLed(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t value,
            uint8_t const OPTION) {
  uint8_t bin_value[SIZE_BIN_ARRAY];
  numToArray(value, bin_value);

  for (uint8_t i = 0; i < SIZE_BIN_ARRAY; i++) {
    *LAT = (OPTION) ? (PIN_MUX & bin_value[i]) : (PIN_MUX & (~bin_value[i]));
    *LAT |= pin_clk;
    *LAT = (OPTION) ? (PIN_MUX & bin_value[i]) : (PIN_MUX & (~bin_value[i]));
  }
}

void toggleTwoBits(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time) {
  uint8_t aux_value = 0b00000011;
  for (uint8_t i = 0; i < 2; i++) {
    setLed(LAT, pin_clk, aux_value, TRUE);
    aux_value = ~aux_value;
    for (uint32_t i = 0; i < time; i++) __delay_ms(1);
  }
}

void shiftLeftOff(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time) {
  uint8_t aux_value = 1;
  for (uint8_t i = 0; i < SIZE_BIN_ARRAY; i++) {
    setLed(LAT, pin_clk, aux_value, FALSE);
    aux_value |= aux_value << 1;
    for (uint32_t i = 0; i < time; i++) __delay_ms(1);
  }
}

void turnOff(volatile uint8_t *LAT, uint8_t pin_clk) {
  for (uint8_t i = 0; i < SIZE_BIN_ARRAY; i++) setLed(LAT, pin_clk, 0, TRUE);
}

void definitions() {
  TRISB = IN;
  TRISC = OUT;
  TRISD = OUT;
  TRISE0 = OUT;
  TRISE1 = OUT;
  LED_ENTRADA = LOW;
  LED_SAIDA = LOW;

  INT0IF = LOW;
  INT1IF = LOW;

  INTEDG0 = HIGH;
  INTEDG1 = LOW;

  INT0IE = HIGH;
  INT1IE = HIGH;

  INT1IP = LOW;

  IPEN = HIGH;
  GIEH = HIGH;
  GIEL = HIGH;
}

void delay(uint32_t time) {
  for (uint32_t i = 0; i < time; i++) __delay_ms(1);
}