#ifndef __DEFINES__H__
#define __DEFINES__H__

#define HIGH    1
#define LOW     0
#define FALSE   0
#define TRUE    1
#define OFF     0
#define ON      1
#define OUT     0
#define IN      1
#define DOWN   'd'
#define UP     'u'

#define PIN_MUX 0b00000001
#define CLK1 0b000000010
#define CLK2 0b000000100
#define LED_ENTRADA LATE0
#define LED_SAIDA LATE1
#define SIZE_BIN_ARRAY 8
#define MSB_BIT_LAT 0b10000000

typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef char int8_t;

#endif