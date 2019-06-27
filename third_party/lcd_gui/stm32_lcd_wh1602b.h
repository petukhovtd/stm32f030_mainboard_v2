#ifndef __LCD_WH1602B_H
#define __LCD_WH1602B_H

#include <stm32f4xx.h>

#define     RS_H          GPIOB->BSRR |= GPIO_BSRR_BS_4     //PB4
#define     RS_L          GPIOB->BSRR |= GPIO_BSRR_BR_4

#define     EN_H          GPIOB->BSRR |= GPIO_BSRR_BS_5     //PB5
#define     EN_L          GPIOB->BSRR |= GPIO_BSRR_BR_5

#define     D0_H          GPIOB->BSRR |= GPIO_BSRR_BS_7     //PB7
#define     D0_L          GPIOB->BSRR |= GPIO_BSRR_BR_7

#define     D1_H          GPIOB->BSRR |= GPIO_BSRR_BS_8     //PB8
#define     D1_L          GPIOB->BSRR |= GPIO_BSRR_BR_8

#define     D2_H          GPIOE->BSRR |= GPIO_BSRR_BS_2     //PE2
#define     D2_L          GPIOE->BSRR |= GPIO_BSRR_BR_2

#define     D3_H          GPIOE->BSRR |= GPIO_BSRR_BS_4     //PE4
#define     D3_L          GPIOE->BSRR |= GPIO_BSRR_BR_4

#define     D4_H          GPIOE->BSRR |= GPIO_BSRR_BS_5     //PE5
#define     D4_L          GPIOE->BSRR |= GPIO_BSRR_BR_5

#define     D5_H          GPIOE->BSRR |= GPIO_BSRR_BS_6     //PE6
#define     D5_L          GPIOE->BSRR |= GPIO_BSRR_BR_6

#define     D6_H          GPIOC->BSRR |= GPIO_BSRR_BS_13     //PC13
#define     D6_L          GPIOC->BSRR |= GPIO_BSRR_BR_13

#define     D7_H          GPIOC->BSRR |= GPIO_BSRR_BS_15     //PC15
#define     D7_L          GPIOC->BSRR |= GPIO_BSRR_BR_15

void LCDInit( void );

void LCDInit8bit( void );

void LCDClear( void );

void LCDClearManualDelay( uint32_t delay);

void LCDCursorBlink( uint8_t State );

void LCDCursorPositionYX( uint8_t Y, uint8_t X );

void LCDPrint( uint8_t *str );


#endif
