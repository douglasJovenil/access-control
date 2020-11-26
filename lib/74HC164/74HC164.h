#ifndef __74HC164__H__
#define __74HC164__H__

#include "pic18f4550_config.h"
#include "defines.h"

#define PIN_MUX 0b00000001
#define SIZE_BIN_ARRAY 8
#define TRUE 1
#define FALSE 0
#define MSB_BIT_LAT 0b10000000

static uint8_t aux_value = MSB_BIT_LAT;

void numToArray(uint8_t num, uint8_t array[])
void setLed(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t value, uint8_t const OPTION)
void shiftRightOn(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time)
void shiftRightOnStep(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time)
void shiftLeftOffStep(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time)
void shiftLeftOn(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time)
void shiftLeftOff(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time)
void turnOff(volatile uint8_t *LAT, uint8_t pin_clk)
void toggleFourBits(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time)
void toggleTwoBits(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time)
void toggleAllBits(volatile uint8_t *LAT, uint8_t pin_clk, uint8_t time)

#endif