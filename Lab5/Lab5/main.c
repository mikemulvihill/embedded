#include "msp430.h"


//5.1 Definitions, used for shortcuts
#define RedLED BIT0
#define GreenLED BIT6
#define ToggleLeds (P1OUT ^= RedLED|GreenLED)

//main, to be used for all three problems
void main(void)
{
    //5.1
    //setting clock frequency
    BCSCTL2 |= DIVS_3;
    WDTCTL = WDT_MDLY_32;
    IE1 |= WDTIE; //interrupts based on watchdog
    P1DIR = RedLED|GreenLED; //inputs and outputs
    P1OUT = RedLED;

    _enable_interrupts(); //interrupts enabled

    LPM1; //low power mode 1


    //5.2
    //WDTCTL = WDTPW + WDTHOLD;  // Stop WDT
    //P1DIR |= BIT6;             // P1.6 to output
    //TA0CTL = TASSEL_2 + MC_1+ID_3;//+TACLR;
    //TA0CCR0 = 62499; // Set maximum count value (PWM Period
    //TA0CCR1 = 6249; // initialize counter compare value
    //TA0CCTL0 |= CCIE;
    //TA0CCTL1 |= CCIE;
    //TA0CCTL0 &=~CCIFG;
    //TA0CCTL1 &=~CCIFG;
    //_enable_interrupts(); // Enter LPM0



    //5.3
    //WDTCTL = WDTPW|WDTHOLD;

    //P1DIR |= BIT6; //red LED input and output
    //P1SEL |= BIT6;

    //TACCR0 = 31249; //calculations done on paper
    //TACCR1 = 6250;
    //TACCTL1 = OUTMOD_7;
    //TACTL = TASSEL_2|ID_3|MC_1; //divide by 8

    //LPM1;
}

//5.1 Vector
#pragma vector = WDT_VECTOR
__interrupt void WDT(void){
    ToggleLeds; //shortcut above
}


//5.2 Vectors
//#pragma vector = TIMER0_A0_VECTOR   //define the interrupt service vector
//__interrupt void TA0_ISR (void){     //interrupt service routine
  //  P1OUT |=BIT6;                   //Toggle
    //TA0CCTL0 &=~CCIFG;
    //}

//#pragma vector = TIMER0_A1_VECTOR   //define interrupt service vector
//__interrupt void TA1_ISR (void) {   //interrupt service routine
  //  P1OUT &=~BIT6;                  //Toggle
    //TA0CCTL1 &=~CCIFG;
    //}
