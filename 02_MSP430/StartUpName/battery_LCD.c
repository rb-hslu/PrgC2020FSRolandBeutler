/*
 * battery_LCD.c
 *
 *  Created on: Apr 25, 2020
 *      Author: roli
 */
#include "main.h"
#include "hal_LCD.h"
#include "battery_LCD.h"

/*
 * shows battery status on LCD display:
 * N out of 6 bars and frame
 */
void displayBatteryStatusOnLCD(unsigned int batteryValue0to6)
{
            switch(batteryValue0to6){

                case 0:
                LCDM13 = 0x01;
                LCDM12 = 0x10;
                break;

                case 1:
                LCDM13 = 0x03;
                LCDM12 = 0x10;
                break;

                case 2:
                LCDM13 = 0x03;
                LCDM12 = 0x30;
                break;

                case 3:
                LCDM13 = 0x07;
                LCDM12 = 0x30;
                break;

                case 4:
                LCDM13 = 0x07;
                LCDM12 = 0x70;
                break;

                case 5:
                LCDM13 = 0x0F;
                LCDM12 = 0x70;
                break;

                case 6:
                LCDM13 = 0x0F;
                LCDM12 = 0xF0;
                break;

                default:
                LCDM13 = 0x01;
                LCDM12 = 0x10;
                break;


            }

}

