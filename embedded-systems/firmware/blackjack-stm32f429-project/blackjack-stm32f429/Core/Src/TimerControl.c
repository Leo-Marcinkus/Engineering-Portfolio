#include "TimerControl.h"
#include "stm32f4xx_hal.h"
#include <stdint.h>

static TIM_HandleTypeDef TimerB;

void IntializeTimerB() {

	//6.25 MHz
	//Tout = 50s
	__HAL_RCC_TIM6_CLK_ENABLE();

	TimerB.Instance = TIM6;
	TimerB.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE; //
	TimerB.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1; //
	TimerB.Init.CounterMode = TIM_COUNTERMODE_UP; //
	TimerB.Init.Period = 45000; //Referenced as ARR in lecture //65k
	TimerB.Init.Prescaler = 6943; //Integer Value //10k

	//New Frequency
	//1.667 KHz

	HAL_TIM_Base_Init(&TimerB);
	EnableTimerInterrupt();


}

void StartTimerB() {

	HAL_TIM_Base_Start_IT(&TimerB);

}

void StopTimerB() {

	HAL_TIM_Base_Stop_IT(&TimerB);

}


void StopClock() {

	__HAL_RCC_TIM6_CLK_DISABLE();

}

uint16_t TimerCounter() {

	return __HAL_TIM_GET_COUNTER(&TimerB);

}

void ResetTimerCounter() {

	__HAL_TIM_SET_COUNTER(&TimerB, 0);

}

void EnableTimerInterrupt() {

	NVIC_EnableIRQ(TIM6_DAC_IRQn);

}

void DisableTimerInterrupt() {

	NVIC_DisableIRQ(TIM6_DAC_IRQn);

}

void ClearTimerInterruptB() {

	__HAL_TIM_CLEAR_FLAG(&TimerB, TIM_FLAG_UPDATE);
	NVIC_ClearPendingIRQ(TIM6_DAC_IRQn);


}
