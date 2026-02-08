#ifndef GAMEDRIVER_H_
#define GAMEDRIVER_H_

extern int volatile cheatCodeFlag;

void displayHomeScreen();
void LCD_Touch_HomeScreen();

int updateIsHome();

//Blackjack
void displayBlackjack();

void InitializeTimer(void);

#define OneSecond 12500
#define TwoSeconds 25000

#endif
