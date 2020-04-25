//#include <msp430.h>

#include "main.h"
#include "hal_LCD.h"
#include "battery_LCD.h"


// Backup Memory variables to track states through LPM3.5
volatile unsigned char * S1buttonDebounce = &BAKMEM2_L;       // S1 button debounce flag
volatile unsigned char * S2buttonDebounce = &BAKMEM2_H;       // S2 button debounce flag
volatile unsigned char * stopWatchRunning = &BAKMEM3_L;       // Stopwatch running flag
volatile unsigned char * tempSensorRunning = &BAKMEM3_H;      // Temp Sensor running flag
volatile unsigned char * mode = &BAKMEM4_L;                   // mode flag
volatile unsigned int holdCount = 0;
volatile unsigned int batValue = 0;

// TimerA0 UpMode Configuration Parameter
Timer_A_initUpModeParam initUpParam_A0 =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_1,          // SMCLK/1 = 2MHz
        30000,                                  // 15ms debounce period
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR,                       // Clear value
        true                                    // Start Timer
};

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	

	    // Initializations
        Init_GPIO();
        Init_Clock();
        Init_RTC();
        Init_LCD();
        LCDM12 = 0x00;
        LCDM13 = 0x00;
        batValue = 0;

        GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN2);
        GPIO_clearInterrupt(GPIO_PORT_P2, GPIO_PIN6);

        *S1buttonDebounce = *S2buttonDebounce = *stopWatchRunning = *tempSensorRunning = *mode = 0;

        __enable_interrupt();

        clearLCD();
        int j;

        for(j = 0x00 ; j < 0x02; j ++)
        {
            displayScrollText("PRGC ROLAND BEUTLER");
        }


        // Display battery Symbol
        LCDM13 = 0x01;
        LCDM12 = 0x10;


	    // Standard loop

        while(1)
	    {
	        // LCD_E_selectDisplayMemory(LCD_E_BASE, LCD_E_DISPLAYSOURCE_MEMORY);
            RTC_setModulo(RTC_BASE, 2*8191);
            RTC_enableInterrupt(RTC_BASE, RTC_OVERFLOW_INTERRUPT);
            RTC_start(RTC_BASE, RTC_CLOCKSOURCE_XT1CLK);

            displayBatteryStatusOnLCD(batValue);

/*
	        if(* S1buttonDebounce)
	        {
	            if(batValue < 6)
	            {
	            batValue++;
	            }
	            * S1buttonDebounce = 0;

	        }

	        else if(* S2buttonDebounce)
            {
	            if(batValue > 0)
	            {
                batValue--;
	            }
                * S2buttonDebounce = 0;
            }
*/



	    }

	}

	/*
	 * GPIO Initialization
	 */
	void Init_GPIO()
	{
	    // Set all GPIO pins to output low to prevent floating input and reduce power consumption
	    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setOutputLowOnPin(GPIO_PORT_P2, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setOutputLowOnPin(GPIO_PORT_P3, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setOutputLowOnPin(GPIO_PORT_P4, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setOutputLowOnPin(GPIO_PORT_P5, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setOutputLowOnPin(GPIO_PORT_P6, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setOutputLowOnPin(GPIO_PORT_P7, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setOutputLowOnPin(GPIO_PORT_P8, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);

	    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setAsOutputPin(GPIO_PORT_P4, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setAsOutputPin(GPIO_PORT_P5, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setAsOutputPin(GPIO_PORT_P6, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setAsOutputPin(GPIO_PORT_P7, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);
	    GPIO_setAsOutputPin(GPIO_PORT_P8, GPIO_PIN0|GPIO_PIN1|GPIO_PIN2|GPIO_PIN3|GPIO_PIN4|GPIO_PIN5|GPIO_PIN6|GPIO_PIN7);

	    GPIO_setAsInputPin(GPIO_PORT_P1, GPIO_PIN1);

	    // Configure button S1 (P1.2) interrupt
	    GPIO_selectInterruptEdge(GPIO_PORT_P1, GPIO_PIN2, GPIO_HIGH_TO_LOW_TRANSITION);
	    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P1, GPIO_PIN2);
	    GPIO_clearInterrupt(GPIO_PORT_P1, GPIO_PIN2);
	    GPIO_enableInterrupt(GPIO_PORT_P1, GPIO_PIN2);

	    // Configure button S2 (P2.6) interrupt
	    GPIO_selectInterruptEdge(GPIO_PORT_P2, GPIO_PIN6, GPIO_HIGH_TO_LOW_TRANSITION);
	    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P2, GPIO_PIN6);
	    GPIO_clearInterrupt(GPIO_PORT_P2, GPIO_PIN6);
	    GPIO_enableInterrupt(GPIO_PORT_P2, GPIO_PIN6);

	    // Set P4.1 and P4.2 as Secondary Module Function Input, LFXT.
	    GPIO_setAsPeripheralModuleFunctionInputPin(
	           GPIO_PORT_P4,
	           GPIO_PIN1 + GPIO_PIN2,
	           GPIO_PRIMARY_MODULE_FUNCTION
	           );

	    // Disable the GPIO power-on default high-impedance mode
	    // to activate previously configured port settings
	    PMM_unlockLPM5();
	}

	/*
	 * Clock System Initialization
	 */
	void Init_Clock()
	{
	    // Intializes the XT1 crystal oscillator
	    CS_turnOnXT1(CS_XT1_DRIVE_1);
	}

	/*
	 * Real Time Clock counter Initialization
	 */
	void Init_RTC()
	{
	    // Set RTC modulo to 327-1 to trigger interrupt every ~10 ms
	    RTC_setModulo(RTC_BASE, 326);
	    RTC_enableInterrupt(RTC_BASE, RTC_OVERFLOW_INTERRUPT);
	}

	/*
	 * PORT1 Interrupt Service Routine
	 * Handles S1 button press interrupt
	 */
	#pragma vector = PORT1_VECTOR
	__interrupt void PORT1_ISR(void)
	{
	    P1OUT |= BIT0;    // Turn LED1 On
	    switch(__even_in_range(P1IV, P1IV_P1IFG7))
	    {
	        case P1IV_NONE : break;
	        case P1IV_P1IFG0 : break;
	        case P1IV_P1IFG1 : break;
	        case P1IV_P1IFG2 :
	            if ((*S1buttonDebounce) == 0)
	            {

	                *S1buttonDebounce = 1;                        // First high to low transition
	                holdCount = 0;

	                if ( batValue > 0)
	                {
	                    batValue--;
	                }

	                // Start debounce timer
	                Timer_A_initUpMode(TIMER_A0_BASE, &initUpParam_A0);
	            }
	        case P1IV_P1IFG3 : break;
	        case P1IV_P1IFG4 : break;
	        case P1IV_P1IFG5 : break;
	        case P1IV_P1IFG6 : break;
	        case P1IV_P1IFG7 : break;
	    }
	}

	/*
	 * PORT2 Interrupt Service Routine
	 * Handles S2 button press interrupt
	 */
	#pragma vector = PORT2_VECTOR
	__interrupt void PORT2_ISR(void)
	{
	    P4OUT |= BIT0;    // Turn LED2 On
	    switch(__even_in_range(P2IV, P2IV_P2IFG7))
	    {
	        case P2IV_NONE : break;
	        case P2IV_P2IFG0 : break;
	        case P2IV_P2IFG1 : break;
	        case P2IV_P2IFG2 : break;
	        case P2IV_P2IFG3 : break;
	        case P2IV_P2IFG4 : break;
	        case P2IV_P2IFG5 : break;
	        case P2IV_P2IFG6 :
	            if ((*S2buttonDebounce) == 0)
	            {

	                *S2buttonDebounce = 1;                        // First high to low transition
	                holdCount = 0;

	                if ( batValue < 6)
	                {
	                    batValue++;
	                }

	                // Start debounce timer
	                Timer_A_initUpMode(TIMER_A0_BASE, &initUpParam_A0);
	            }

	        case P2IV_P2IFG7 : break;
	    }
	}

	/*
	 * Timer A0 Interrupt Service Routine
	 * Used as button debounce timer
	 */
	#pragma vector = TIMER0_A0_VECTOR
	__interrupt void TIMER0_A0_ISR (void)
	{
	    // Both button S1 & S2 held down
	    if (!(P1IN & BIT2) && !(P2IN & BIT6))
	    {
	        holdCount++;
	        if (holdCount == 40)
	        {
	            // Stop Timer A0
	            Timer_A_stop(TIMER_A0_BASE);


	            __bic_SR_register_on_exit(LPM3_bits);                // exit LPM3
	        }
	    }

	    // Button S1 released
	    if (P1IN & BIT2)
	    {
	        *S1buttonDebounce = 0;                                   // Clear button debounce
	        P1OUT &= ~BIT0;
	    }

	    // Button S2 released
	    if (P2IN & BIT6)
	    {
	        *S2buttonDebounce = 0;                                   // Clear button debounce
	        P4OUT &= ~BIT0;
	    }

	    // Both button S1 & S2 released
	    if ((P1IN & BIT2) && (P2IN & BIT6))
	    {
	                    // exit LPM3
	    }
	}

	/*
	 * RTC Interrupt Service Routine
	 * Wakes up every ~10 milliseconds to update stowatch
	 */
	#pragma vector = RTC_VECTOR
	__interrupt void RTC_ISR(void)
	{
	    switch(__even_in_range(RTCIV, RTCIV_RTCIF))
	    {
	        case RTCIV_NONE : break;
	        case RTCIV_RTCIF: break;
	    }
	}

	/*
	 * ADC Interrupt Service Routine
	 * Wake up from LPM3 when ADC conversion completes
	 */
	#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
	#pragma vector=ADC_VECTOR
	__interrupt void ADC_ISR(void)
	#elif defined(__GNUC__)
	void __attribute__ ((interrupt(ADC_VECTOR))) ADC_ISR (void)
	#else
	#error Compiler not supported!
	#endif
	{
	    switch(__even_in_range(ADCIV,ADCIV_ADCIFG))
	    {
	        case ADCIV_NONE:
	            break;
	        case ADCIV_ADCOVIFG:
	            break;
	        case ADCIV_ADCTOVIFG:
	            break;
	        case ADCIV_ADCHIIFG:
	            break;
	        case ADCIV_ADCLOIFG:
	            break;
	        case ADCIV_ADCINIFG:
	            break;
	        case ADCIV_ADCIFG:
	            // Clear interrupt flag
	            ADC_clearInterrupt(ADC_BASE, ADC_COMPLETED_INTERRUPT_FLAG);
	            __bic_SR_register_on_exit(LPM3_bits);                // Exit LPM3
	            break;
	        default:
	            break;
	    }

	return 0;
}
