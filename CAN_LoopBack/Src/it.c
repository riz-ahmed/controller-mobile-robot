/*
 * it.c
 *
 *  Created on: 02-Jun-2020
 *      Author: RizAhmed
 */

#include "main.h"


void SysTick_Handler (void)
{
	HAL_IncTick();
	HAL_SYSTICK_IRQHandler();
}



