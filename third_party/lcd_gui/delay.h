#ifndef __DELAY_H
#define __DELAY_H

#include <stdint.h>

uint32_t delay;

// add to main
// SysTick_Config(168);
// NVIC_EnableIRQ(SysTick_IRQn);
// add Delay_tic() to SysTick_Handler

void Delay_ms(uint32_t ms)
{
	delay = ms*1000;
	while(delay);
}

void Delay_us(uint32_t us)
{
	delay = us;
	while(delay);
}

void Delay_tic(void)
{
	if(delay > 0){
		delay --;
	}
}

#endif
