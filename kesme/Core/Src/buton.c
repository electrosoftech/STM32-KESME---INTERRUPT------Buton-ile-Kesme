/*
 * buton.c
 *
 *  Created on: Mar 18, 2022
 *      Author: MUHAMMEDERKAMOKUMUŞ
 */


#include "stm32f4xx_hal.h"
#include "buton.h"

void butonKesme(void){

	__HAL_RCC_SYSCFG_CLK_ENABLE();

	SYSCFG->EXTICR[0] = SYSCFG_EXTICR1_EXTI0_PA;
	SET_BIT(EXTI->IMR , EXTI_IMR_IM0);
	SET_BIT(EXTI->RTSR , EXTI_RTSR_TR0);

	NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void){

	SET_BIT(EXTI->PR , EXTI_PR_PR0);
	HAL_GPIO_TogglePin(GPIOD, GPIO_PIN_12 | GPIO_PIN_13 |GPIO_PIN_14 |GPIO_PIN_15);

}
