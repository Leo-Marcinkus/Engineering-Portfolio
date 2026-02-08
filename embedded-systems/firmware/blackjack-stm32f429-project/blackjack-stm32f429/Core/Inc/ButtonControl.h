#ifndef BUTTONCONTROL_H_
#define BUTTONCONTROL_H_

//Button Functions
void InitializeButton();
void ClearButtonBit();
void EnableButtonInterrupt();
void DisableButtonInterrupt();
void ClearButtonInterrupt();

int ReadPin();

#endif
