#include "msp430.h"


//5.1 Definitions
#define RedLED BIT0
#define GreenLED BIT6
#define ToggleLeds (P1OUT ^= RedLED|GreenLED)

void main(void)
{
    //5.1
    BCSCTL2 |= DIVS_3;
    WDTCTL = WDT_MDLY_32;
    IE1 |= WDTIE;
    P1DIR = RedLED|GreenLED;
    P1OUT = RedLED;

    _enable_interrupts();

    LPM1;


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

    //P1DIR |= BIT6;
    //P1SEL |= BIT6;

    //TACCR0 = 31249;
    //TACCR1 = 6250;
    //TACCTL1 = OUTMOD_7;
    //TACTL = TASSEL_2|ID_3|MC_1;

    //LPM1;
}

//5.1 Vector
#pragma vector = WDT_VECTOR
__interrupt void WDT(void){
    ToggleLeds;
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
