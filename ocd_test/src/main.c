/*
 * main.c
 */

#include "stm32f10x_conf.h"

//GPIO_InitTypeDef GPIO_InitStructure;

void delay(void) {
	volatile unsigned int i;

	for (i = 0; i < 200000; i++)
		;
}

int main(void) {
	// I/O port C clock enable
	RCC->APB2ENR = RCC_APB2ENR_IOPCEN;
	// Set PC_12 to output
	GPIOC->CRH &= ~(GPIO_CRH_MODE13 | GPIO_CRH_CNF13);
	GPIOC->CRH |= GPIO_CRH_MODE13;

	while (1) {
		GPIOC->BSRR = (1 << 13);
		delay();
		GPIOC->BRR = (1 << 13);
		delay();
	}
}


/*	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13;
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
 GPIO_Init(GPIOC, &GPIO_InitStructure);

 while (1) {
 int i;
 //		GPIO_SetBits(GPIOC, 0x00000000);
 //		for(i = 0; i < 1000; i++);
 GPIO_SetBits(GPIOC, GPIO_Pin_13);
 //		for(i = 0; i < 100000000; i++);
 }
 }
 */
