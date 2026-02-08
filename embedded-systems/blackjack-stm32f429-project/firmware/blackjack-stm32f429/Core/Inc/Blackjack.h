#ifndef BLACKJACK_H_
#define BLACKJACK_H_

extern uint16_t volatile balance;

int getRandomNumber();
void assignRandomNumber();

void drawBlackJackSetup();

void drawDealerCards();
void generateDealerCards();
void generateCheatGameDealerCards();

void drawFirstPlayerCards();
void generateFirstPlayerCards();

void drawExit();
void drawPlay();

void displayBalance();

void drawReset();

void LCD_Touch_InBlackJack();

void runHit();
void runStand();

void appDelay();

void runWin();
void runLose();
void runTie();

void cheatCodeGame();


#endif
