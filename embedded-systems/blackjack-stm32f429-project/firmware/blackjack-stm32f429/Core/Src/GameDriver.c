#include "GameDriver.h"
#include "LCD_Driver.h"
#include "Blackjack.h"
#include "Cashier.h"
#include "TimerControl.h"
#include "ButtonControl.h"
#include "ApplicationCode.h"
#include <stdio.h>
#include "stm32f4xx_hal.h"

static int volatile isHome = 0; //Is it on the home screen
static int volatile NumberOfOneSecondPress = 0; //How many times 1 second press happened
static int volatile NumberOfTwoSecondPress = 0; //How many times 2 second press happened
static int volatile NumberOfQuickPress = 0; //How many times it was just pressed and released
static int volatile TimerCount = 0; //Utilizes TimerCounter(); from TimerControl.C
int volatile cheatCodeFlag = 0; //Cheat code flag (0 is off)

int updateIsHome() {

	return isHome;

}

void InitializeTimer(void) {

	IntializeTimerB();
	InitializeButton();

}

void EXTI0_IRQHandler(void) {

    DisableButtonInterrupt();

    ClearButtonInterrupt();
    ClearButtonBit();

    //Only process cheat code logic while on home screen
    if (isHome != 0) {

    	EnableButtonInterrupt();
        return;

    }

    if (ReadPin() == 1) {

        ResetTimerCounter();
        TimerCount = 0;
        StartTimerB();

        EnableButtonInterrupt();
        return;

    }

    //ReadPin()= 0 means button was released
    TimerCount = TimerCounter();
    StopTimerB();
    //printf("TimerCount = %d\n", TimerCount);

    // Classify the press based on elapsed counts
    if ((TimerCount >= OneSecond) && (TimerCount < TwoSeconds)) {

        NumberOfOneSecondPress++;
        printf("One Second Press\n");

    } else if (TimerCount >= TwoSeconds) {

        NumberOfTwoSecondPress++;
        printf("Two Second Press\n");

    } else if (TimerCount < OneSecond) {

        NumberOfQuickPress++;
        printf("Quick Press\n");

    }

    //Reset timer state for next press
    TimerCount = 0;
    ResetTimerCounter();

    //Enabling cheat code based on the presses
    if ((NumberOfOneSecondPress == 1) && (NumberOfTwoSecondPress == 1) && (NumberOfQuickPress == 1)) {

        cheatCodeFlag = 1;
        printf("Cheat Code Enabled\n");
        NumberOfOneSecondPress = 0;
        NumberOfTwoSecondPress = 0;
        NumberOfQuickPress = 0;

    }

    //Resets counts if buttons are pressed out of order
    if (NumberOfOneSecondPress > 1 || NumberOfTwoSecondPress > 1 || NumberOfQuickPress    > 1) {

        NumberOfOneSecondPress = 0;
        NumberOfTwoSecondPress = 0;
        NumberOfQuickPress = 0;

    }

    if ((NumberOfQuickPress > 0) && ((NumberOfOneSecondPress < 1) || (NumberOfTwoSecondPress < 1))) {

        NumberOfOneSecondPress = 0;
        NumberOfTwoSecondPress = 0;
        NumberOfQuickPress = 0;

    }

    if ((NumberOfTwoSecondPress > 0) && (NumberOfOneSecondPress < 1)) {

        NumberOfOneSecondPress = 0;
        NumberOfTwoSecondPress = 0;
        NumberOfQuickPress = 0;

    }

    EnableButtonInterrupt();

}




void displayHomeScreen() {

	isHome = 0;

	//Welcome
	LCD_Draw_Rectangle(20, 20, 200, 40, LCD_COLOR_BLUE);
	//LCD_Rectangle_Fill(20, 20, 200, 200, LCD_COLOR_DARKRED);

	LCD_SetTextColor(LCD_COLOR_BLUE);
	LCD_SetFont(&Font16x24);
	LCD_DisplayChar(65, 30, 'W');
	LCD_DisplayChar(80, 30, 'E');
	LCD_DisplayChar(95, 30, 'L');
	LCD_DisplayChar(108, 30, 'C');
	LCD_DisplayChar(125, 30, 'O');
	LCD_DisplayChar(143, 30, 'M');
	LCD_DisplayChar(160, 30, 'E');

	//Blackjack
	LCD_Draw_Rectangle(20, 120, 200, 40, LCD_COLOR_BLACK);

	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);
	LCD_DisplayChar(55, 130, 'B');
	LCD_DisplayChar(70, 130, 'L');
	LCD_DisplayChar(80, 130, 'A');
	LCD_DisplayChar(98, 130, 'C');
	LCD_DisplayChar(115, 130, 'K');
	LCD_DisplayChar(133, 130, 'J');
	LCD_DisplayChar(145, 130, 'A');
	LCD_DisplayChar(160, 130, 'C');
	LCD_DisplayChar(180, 130, 'K');

	//Display balance
	LCD_Draw_Rectangle(20, 270, 200, 40, LCD_COLOR_DARKRED);
	LCD_SetTextColor(LCD_COLOR_DARKRED);
	LCD_SetFont(&Font16x24);
	LCD_DisplayChar(25, 280, 'B');
	LCD_DisplayChar(40, 280, 'A');
	LCD_DisplayChar(55, 280, 'L');
	LCD_DisplayChar(70, 280, 'A');
	LCD_DisplayChar(85, 280, 'N');
	LCD_DisplayChar(100, 280, 'C');
	LCD_DisplayChar(115, 280, 'E');
	LCD_DisplayChar(125, 280, ':');

	//Actual balance
	LCD_DisplayNumber(135, 280, balance);

}

void displayBlackjack() {

	if (balance == 0) {

		LCD_Clear(LCD_COLOR_WHITE);
		displayHomeScreen();

		LCD_Draw_Rectangle(20, 200, 200, 40, LCD_COLOR_DARKRED);
		LCD_Draw_String(25, 210, "NO MONEY");

		return;

	}

	drawBlackJackSetup();
	isHome = 1;

}

void LCD_Touch_HomeScreen(void) {
	STMPE811_TouchData StaticTouchData;
	while (1) {

		/* If touch pressed */
		if (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {

			/* Touch valid */

			if ( (StaticTouchData.x > 20) && (StaticTouchData.x < 220) ) {

				if ( (StaticTouchData.y > 120) && (StaticTouchData.y < 160) ) {

					LCD_Clear(LCD_COLOR_WHITE);
					displayBlackjack();

					break;

				}

			}

			printf("\nX: %03d\nY: %03d\n", StaticTouchData.x, StaticTouchData.y);

		}

	}

}



