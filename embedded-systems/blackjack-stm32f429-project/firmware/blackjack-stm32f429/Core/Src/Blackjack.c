#include "GameDriver.h"
#include "LCD_Driver.h"
#include "Blackjack.h"
#include "Cashier.h"
#include "ApplicationCode.h"
#include <stdio.h>
#include <string.h>
#include "stm32f4xx_hal.h"

static RNG_HandleTypeDef RNG_Struct = {0};
static int volatile isPlaying = 0; //Are they playing
static int volatile resultScreen = 0; //On result screen or not

uint16_t volatile balance = 100; //Current balance definition

static int volatile setValue;
static char volatile cardChar;
static int volatile cardValue;
static int volatile faceCard;

static int volatile dealerCardOne;
static int volatile dealerCardTwo;

static int volatile playerCardOne;
static int volatile playerCardTwo;

static int volatile playerCardTotal;

static int volatile hitNumber;
static int volatile hitCardOne;
static int volatile hitCardTwo;
static int volatile hitCardThree;
static int volatile hitCardFour;
static int volatile hitCardFive;

int getRandomNumber() {

	RNG_Struct.Instance = RNG;
	HAL_RNG_Init(&RNG_Struct);

	uint32_t randomNumber = HAL_RNG_GetRandomNumber(&RNG_Struct);

	return randomNumber;

}

void assignRandomNumber() {

	//Gets assigned a value 0-12
	uint32_t mod = getRandomNumber();
	setValue = (int)(mod %13u) + 1;

	switch (setValue) {
		case 1:
	        cardValue = 11;
	        cardChar = 'A';
	        faceCard = 4;
	        break;
	    case 2:
	        cardValue = 2;
	        faceCard = 0;
	        break;
	    case 3:
	    	cardValue = 3;
	    	faceCard = 0;
	    	break;
	    case 4:
	    	cardValue = 4;
	    	faceCard = 0;
	    	break;
	    case 5:
	    	cardValue = 5;
	    	faceCard = 0;
	    	break;
	    case 6:
	    	cardValue = 6;
	    	faceCard = 0;
	    	break;
	    case 7:
	    	cardValue = 7;
	    	faceCard = 0;
	    	break;
	    case 8:
	    	cardValue = 8;
	    	faceCard = 0;
	    	break;
	    case 9:
	    	cardValue = 9;
	    	faceCard = 0;
	    	break;
	    case 10:
	    	cardValue = 10;
	    	faceCard = 0;
	    	break;
	    case 11:
	    	cardValue = 10;
	    	cardChar = 'J';
	    	faceCard = 1;
	    	break;
	    case 12:
	    	cardValue = 10;
	    	cardChar = 'Q';
	    	faceCard = 2;
	    	break;
	    case 13:
	    	cardValue = 10;
	    	cardChar = 'K';
	    	faceCard = 3;
	    	break;
	}

}

void appDelay(void) {

	for (int i = 0; i <= 7500; i++) {

		//Volatile prevents the j from being ignored by the compiler
		volatile int j = 0;
		j++;

	}

}


void drawExit() {

	LCD_Draw_Rectangle(150, 10, 75, 50, LCD_COLOR_DARKRED);
	LCD_Draw_String(155, 25, "Home");

}

void drawPlay() {

	LCD_Draw_Rectangle(150, 65, 75, 50, LCD_COLOR_LIGHTGREEN);
	LCD_Draw_String(155, 80, "Play");

}

void drawStand() {

	LCD_Draw_Rectangle(150, 65, 75, 50, LCD_COLOR_LIGHTGREEN);
	LCD_Draw_String(155, 70, "Stay");

}

void drawHit() {

	LCD_Draw_Rectangle(150, 155, 75, 50, LCD_COLOR_DARKRED);
	LCD_Draw_String(155, 160, "Hit");

}

void drawReset() {

	LCD_Draw_Rectangle(115, 10, 120, 50, LCD_COLOR_DARKCYAN);
	LCD_Draw_String(120, 25, "Reset");

}

void displayBalance() {

	//Display balance
	LCD_Draw_String(10, 290, "$");

	//Actual balance
	LCD_DisplayNumber(22, 290, balance);

}

void drawDealerCards() {

	LCD_Draw_Rectangle(10, 10, 100, 30, LCD_COLOR_BLACK);
	LCD_Draw_String(15, 15, "Dealer");

	LCD_Draw_Rectangle(10, 45, 40, 60, LCD_COLOR_BLUE);
	LCD_Draw_Rectangle(55, 45, 40, 60, LCD_COLOR_BLUE);

}

void drawFirstPlayerCards() {

	LCD_Draw_Rectangle(10, 120, 150, 30, LCD_COLOR_BLACK);
	LCD_Draw_String(15, 125, "Your Hand");

	LCD_Draw_Rectangle(10, 155, 40, 60, LCD_COLOR_BLUE);
	LCD_Draw_Rectangle(55, 155, 40, 60, LCD_COLOR_BLUE);

}

void generateDealerCards() {

		assignRandomNumber();
		dealerCardOne = cardValue;

		if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

			LCD_DisplayChar(15, 75, cardChar);

		} else if (faceCard == 0) {

			LCD_DisplayNumber(15, 75, cardValue);

		}

		appDelay();

		assignRandomNumber();
		dealerCardTwo = cardValue;

		if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

			LCD_DisplayChar(60, 75, cardChar);

		} else if (faceCard == 0) {

			LCD_DisplayNumber(60, 75, cardValue);

		}

}

void generateCheatGameDealerCards() {

		assignRandomNumber();
		dealerCardOne = cardValue;

		if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

			LCD_DisplayChar(15, 75, cardChar);

		} else if (faceCard == 0) {

			LCD_DisplayNumber(15, 75, cardValue);

		}

		appDelay();

		assignRandomNumber();
		dealerCardTwo = cardValue;

		if (dealerCardOne + dealerCardTwo == 21) {

			faceCard = 0;
			cardValue = 9;
			dealerCardTwo = 9;

		}

		if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

			LCD_DisplayChar(60, 75, cardChar);

		} else if (faceCard == 0) {

			LCD_DisplayNumber(60, 75, cardValue);

		}

}

void generateFirstPlayerCards() {

	assignRandomNumber();
	playerCardOne = cardValue;

	if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

		LCD_DisplayChar(15, 185, cardChar);

	} else if (faceCard == 0) {

		LCD_DisplayNumber(15, 185, cardValue);

	}

	appDelay();

	assignRandomNumber();
	playerCardTwo = cardValue;

	if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

		LCD_DisplayChar(60, 185, cardChar);

	} else if (faceCard == 0) {

		LCD_DisplayNumber(60, 185, cardValue);

	}

}

void cheatCodeGame() {

	drawDealerCards();
	drawFirstPlayerCards();

	displayBalance();
	drawHit();
	drawStand();

	playerCardOne = 11;
	LCD_DisplayChar(15, 185, 'A');
	playerCardTwo = 10;
	LCD_DisplayChar(60, 185, 'J');

	runStand();

	cheatCodeFlag = 0;
	printf("Cheat Code Flag Disabled\n");

}

void drawBlackJackSetup() {

	drawDealerCards();
	drawFirstPlayerCards();

	if (isPlaying == 0) {

		drawExit();
		drawPlay();
		displayBalance();


	} else {

		displayBalance();
		drawHit();
		drawStand();
		generateFirstPlayerCards();

		if (playerCardOne + playerCardTwo == 21) {

			runStand();

		}

		if (playerCardOne + playerCardTwo > 21) {

			runStand();

		}


	}

}

void runWin() {

	isPlaying = 0;
	resultScreen = 1;

	LCD_Draw_Rectangle(159, 269, 80, 50, LCD_COLOR_GREEN);
	LCD_Draw_String(164, 284, "WIN!");
	balance += 200;

	drawReset();

}

void runLose() {

	isPlaying = 0;
	resultScreen = 1;

	LCD_Draw_Rectangle(159, 269, 80, 50, LCD_COLOR_DARKRED);
	LCD_Draw_String(164, 284, "LOSE");

	drawReset();

}

void runTie() {

	isPlaying = 0;
	resultScreen = 1;

	LCD_Draw_Rectangle(159, 269, 80, 50, LCD_COLOR_DARKRED);
	LCD_Draw_String(164, 284, "Tie");
	balance += 100;

	drawReset();

}

void runStand() {

	if (cheatCodeFlag == 1) {

		generateCheatGameDealerCards();

	} else {

		generateDealerCards();

	}


	playerCardTotal = playerCardOne + playerCardTwo + hitCardOne + hitCardTwo + hitCardThree + hitCardFour + hitCardFive;


	if ( (dealerCardOne + dealerCardTwo) > 21 ) {

		runWin();

	}

	if ( (playerCardTotal) > 21 ) {

		runLose();

	}

	if ( (playerCardTotal) > (dealerCardOne + dealerCardTwo) ) {

		runWin();

	}

	if ( (playerCardTotal) < (dealerCardOne + dealerCardTwo) ) {

		runLose();

	}

	if ( (playerCardTotal) == (dealerCardOne + dealerCardTwo) ) {

		runTie();

	}

}

void runHit() {

	hitNumber += 1;

	switch (hitNumber) {

		case 1:
			assignRandomNumber();
			hitCardOne = cardValue;
			LCD_Draw_Rectangle(100, 155, 40, 60, LCD_COLOR_BLUE);

			if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

				LCD_DisplayChar(105, 185, cardChar);

			} else if (faceCard == 0) {

				LCD_DisplayNumber(105, 185, cardValue);

			}

			if ( (playerCardOne + playerCardTwo + hitCardOne) > 21) {

				generateDealerCards();
				runLose();

			} else if ( (playerCardOne + playerCardTwo + hitCardOne) == 21) {

				runStand();

			}

			break;

		case 2:
			assignRandomNumber();
			hitCardTwo = cardValue;
			LCD_Draw_Rectangle(10, 220, 40, 60, LCD_COLOR_BLUE);

			if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

				LCD_DisplayChar(15, 250, cardChar);

			} else if (faceCard == 0) {

				LCD_DisplayNumber(15, 250, cardValue);

			}

			if ( (playerCardOne + playerCardTwo + hitCardOne + hitCardTwo) > 21) {

				generateDealerCards();
				runLose();

			} else if ( (playerCardOne + playerCardTwo + hitCardOne + hitCardTwo) == 21) {

				runStand();

			}

			break;

		case 3:
			assignRandomNumber();
			hitCardThree = cardValue;
			LCD_Draw_Rectangle(55, 220, 40, 60, LCD_COLOR_BLUE);

			if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

				LCD_DisplayChar(60, 250, cardChar);

			} else if (faceCard == 0) {

				LCD_DisplayNumber(60, 250, cardValue);

			}

			if ( (playerCardOne + playerCardTwo + hitCardOne + hitCardTwo + hitCardThree) > 21) {

				generateDealerCards();
				runLose();

			} else if ( (playerCardOne + playerCardTwo + hitCardOne + hitCardTwo + hitCardThree) == 21) {

				runStand();

			}

			break;

		case 4:
			assignRandomNumber();
			hitCardFour = cardValue;
			LCD_Draw_Rectangle(100, 220, 40, 60, LCD_COLOR_BLUE);

			if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

				LCD_DisplayChar(105, 250, cardChar);

			} else if (faceCard == 0) {

				LCD_DisplayNumber(105, 250, cardValue);

			}

			if ( (playerCardOne + playerCardTwo + hitCardOne + hitCardTwo + hitCardThree + hitCardFour) > 21) {

				generateDealerCards();
				runLose();

			} else if ( (playerCardOne + playerCardTwo + hitCardOne + hitCardTwo + hitCardThree + hitCardFour) == 21) {

				runStand();

			}

			break;

		case 5:
			assignRandomNumber();
			hitCardFive = cardValue;
			LCD_Draw_Rectangle(145, 220, 40, 60, LCD_COLOR_BLUE);

			if (faceCard == 4 || faceCard == 3 || faceCard == 2 || faceCard == 1) {

				LCD_DisplayChar(150, 250, cardChar);

			} else if (faceCard == 0) {

				LCD_DisplayNumber(150, 250, cardValue);

			}

			if ( (playerCardOne + playerCardTwo + hitCardOne + hitCardTwo + hitCardThree + hitCardFour + hitCardFive) > 21) {

				generateDealerCards();
				runLose();

			} else if ( (playerCardOne + playerCardTwo + hitCardOne + hitCardTwo + hitCardThree + hitCardFour + hitCardFive) == 21) {

				runStand();

			}

			break;

	}

}


void LCD_Touch_InBlackJack(void) {

	//Initializing
    STMPE811_TouchData StaticTouchData = {0};

    while (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {

    	//Waits until touch is lifted to register (This fixed double pressing and activating the home button right after pressing Reset)

    }

    while (1) {

    	if (resultScreen == 1) {

    		//Wait for press
    	    STMPE811_TouchData StaticTouchDataTwo = {0};
    	    if (returnTouchStateAndLocation(&StaticTouchDataTwo) == STMPE811_State_Pressed) {

    	    	uint16_t touchFieldX = StaticTouchDataTwo.x;
    	    	uint16_t touchFieldY = StaticTouchDataTwo.y;

    	    	//Converting the touch field coordinates to the drawing field coordinates
    	    	uint16_t drawFieldX = 240 - touchFieldX; //The flipped X value
    	    	uint16_t drawFieldY = touchFieldY;

    	    	//Reset button touch region
    	    	if ( (drawFieldX >= 150) && (drawFieldX <= 225) && (drawFieldY >= 10)  && (drawFieldY <= 60) ) {

    	    		while (returnTouchStateAndLocation(&StaticTouchDataTwo) == STMPE811_State_Pressed) {

    	    			//Waits for touch release

    	    		}

    	    		//Delay in case of debounce (Helped with issue double pressing button behind Reset)
    	    		HAL_Delay(150);

    	    		//Resetting the table
    	    		LCD_Clear(LCD_COLOR_WHITE);
    	    		isPlaying = 0;
    	    		resultScreen = 0;
    	    		displayBlackjack(); //Go back to default setup
    	    		return;

    	    	}
    	    }

    	        continue; //This keeps you inside the result screen until Reset is pressed
    	}

        while (returnTouchStateAndLocation(&StaticTouchData) != STMPE811_State_Pressed) {

        	//Waits for the press

        }

        //Converting the touch field coordinates to the drawing field coordinates
        uint16_t touchFieldX  = StaticTouchData.x;
        uint16_t touchFieldY  = StaticTouchData.y;

        uint16_t drawFieldX = 240 - touchFieldX; //The flipped X value
        uint16_t drawFieldY = touchFieldY; //Y stays the same

        //Printing what was touched and where. This was extremely useful for figuring out this weird display
        printf("Touch Field Value( %u , %u ) Draw Field Value( %u , %u ) isPlaying=%d\n", touchFieldX, touchFieldY, drawFieldX, drawFieldY, isPlaying);

        //All buttons share the same X value in the Drawing field so it was easiest to bunch them together
        int xButtonPositionValue = (drawFieldX >= 150) && (drawFieldX <= 225);

        if (isPlaying == 0) {

        	//Play button
            if (xButtonPositionValue && drawFieldY >= 65 && drawFieldY <= 115) {

            	if (balance < 100) {

            		LCD_Clear(LCD_COLOR_WHITE);
            		displayHomeScreen();

            		return;

            	}

                LCD_Clear(LCD_COLOR_WHITE);
                isPlaying = 1;
                hitNumber = 0;

                hitCardOne = 0;
                hitCardTwo = 0;
                hitCardThree = 0;
                hitCardFour = 0;
                hitCardFive = 0;

                dealerCardOne = 0;
                dealerCardTwo = 0;

                playerCardOne = 0;
                playerCardTwo = 0;
                playerCardTotal = 0;

                balance -= 100;


                if (cheatCodeFlag == 1) {

                	cheatCodeGame();
                	printf("Cheat Code Game Running\n");

                } else {

                	drawBlackJackSetup();

                }

                while (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {

                	//Waits for touch release

                }

                //Delay in case of debounce
                HAL_Delay(150);

                break;
            }

            //Home button
            if (xButtonPositionValue && drawFieldY >= 10 && drawFieldY <= 60) {

                LCD_Clear(LCD_COLOR_WHITE);
                isPlaying = 0;
                displayHomeScreen();

                while (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {

                	//Waits for touch release

                }

                //Delay in case of debounce
                HAL_Delay(150);

                break;
            }

        //For the Stand and Hit buttons
        } else {

            //Stand button
            if (xButtonPositionValue && drawFieldY >= 65 && drawFieldY <= 115) {

                runStand();

                while (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {

                	//Waits for touch release

                }

                //Delay in case of debounce
                HAL_Delay(150);

                break;
            }

            //Hit button
            if (xButtonPositionValue && drawFieldY >= 155 && drawFieldY <= 205) {

                runHit();
                while (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {

                	//Waits for touch release

                }

                //Delay in case of debounce
                HAL_Delay(150);

                break;
            }
        }


        while (returnTouchStateAndLocation(&StaticTouchData) == STMPE811_State_Pressed) {

        	//Waits for touch release in case nothing lined up with the if statements

        }
    }

}

//STM32F429I-DISC1 Screen Bounds
//Touch x is 0 to 240 (Flipped for the touch field)
//Touch y is 0 to 320







