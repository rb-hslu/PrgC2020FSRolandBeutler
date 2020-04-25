/******************************************************************************
 *
 * main.h
 *
 * Out of Box Demo for the MSP-EXP430FR4133
 * Main loop, initialization, and interrupt service routines
 *
 * September 2014
 * E. Chen
 *
 ******************************************************************************/

#ifndef MAIN_H_
#define MAIN_H_

#include "driverlib.h"

#define STARTUP_MODE 0

extern volatile unsigned char * stopWatchRunning;
extern volatile unsigned char * tempSensorRunning;
extern volatile unsigned char * mode;
extern volatile unsigned char * S1buttonDebounce;
extern volatile unsigned char * S2buttonDebounce;

extern Timer_A_initUpModeParam initUpParam_A0;

void Init_GPIO(void);
void Init_Clock(void);
void Init_RTC(void);


#endif /* MAIN_H_ */
