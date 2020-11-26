#ifndef __MAIN__H__
#define __MAIN__H__

#include "pic18f4550_config.h"
#include "defines.h"

void delay(uint32_t);
void definitions();
void __interrupt(low_priority) lowPriority();
void __interrupt() highPriority();
void entryInterrupt();
void outputInterrupt();
void numToArray(uint8_t, uint8_t[]);
void setLed(volatile uint8_t*, uint8_t, uint8_t, uint8_t const);
void toggleTwoBits(volatile uint8_t*, uint8_t, uint8_t);
void turnOff(volatile uint8_t*, uint8_t);
void shiftLeftOff(volatile uint8_t*, uint8_t, uint8_t);

#endif