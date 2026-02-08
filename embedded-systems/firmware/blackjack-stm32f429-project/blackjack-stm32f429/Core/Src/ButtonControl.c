#include "ButtonControl.h"
#include "stm32f4xx_hal.h"

void InitializeButton() {

	__HAL_RCC_GPIOA_CLK_ENABLE();

	GPIO_InitTypeDef ButtonConfig;
	ButtonConfig.Pin = GPIO_PIN_0;
	ButtonConfig.Mode = GPIO_MODE_IT_RISING_FALLING;
	ButtonConfig.Pull = GPIO_NOPULL;
	ButtonConfig.Speed = GPIO_SPEED_FREQ_HIGH;

	HAL_GPIO_Init(GPIOA, &ButtonConfig);
	EnableButtonInterrupt();

}

int ReadPin() {

	return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);

}

void ClearButtonBit() {

    NVIC_ClearPendingIRQ(EXTI0_IRQn);

}

void EnableButtonInterrupt() {

	NVIC_EnableIRQ(EXTI0_IRQn);

}

void DisableButtonInterrupt() {

	NVIC_DisableIRQ(EXTI0_IRQn);

}

void ClearButtonInterrupt() {

	__HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_0);


}

