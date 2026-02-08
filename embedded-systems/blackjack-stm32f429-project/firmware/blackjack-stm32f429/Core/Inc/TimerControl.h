#ifndef TIMERCONTROL_H_
#define TIMERCONTROL_H_
#include <stdint.h>

void StartTimerB();
void StopTimerB();

void StopClock();

void EnableTimerInterrupt();
void DisableTimerInterrupt();
void ClearTimerInterruptB();

void IntializeTimerB();

uint16_t TimerCounter();
void ResetTimerCounter();


#endif
