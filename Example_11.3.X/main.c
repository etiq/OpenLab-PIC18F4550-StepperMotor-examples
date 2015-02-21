
/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example_11.3 Stepper motor Wave drive
 *                      : Created on November 14, 2013, 9:33 AM
 *                      : Example code for energizing a stepper motor in wave drive
*/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File 		*/
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File 	*/
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File 		*/
#endif

#if defined(__XC) || defined(HI_TECH_C)
#include <stdint.h>        /* For uint8_t definition 		*/
#include <stdbool.h>       /* For true/false definition 	*/
#endif

#if defined(__XC) || defined(__18CXX)
#include "config.h"
#include "delay.h"
#endif

/* RC7, RC6, RC1 and RC0 bits goes LOGIC HIGH in wave drive sequence and energizes
   stepper motor field coils to rotate the shaft in anti-clockwise direction.

   Wave driving sequence
   ---------------------

        bits  - RC7 RC6 RC1 RC0

                  10000000
                  01000000
                  00000010
                  00000001
*/

int main(int argc, char** argv)
{
   TRISC = 0X00;                                                    /* Setting PORTB as output                  */

   /*                           Wave driving sequence                                   */
   while(1)
    {       
     PORTC = 0b10000000;
     delay_ms(100);
     PORTC = 0b01000000;
     delay_ms(100);
     PORTC = 0b00000010;
     delay_ms(100);
     PORTC = 0b00000001;
     delay_ms(100);
    }
    return (0);
}
