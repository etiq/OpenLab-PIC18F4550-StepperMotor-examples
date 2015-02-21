/*
 * File name            : main.c
 * Compiler             : MPLAB XC8/ MPLAB C18 compiler
 * IDE                  : Microchip  MPLAB X IDE v1.90/ MPLAB IDE v8
 * Author               : Etiq Technologies
 * Description          : Example_11.2 Stepper motor Half step drive
 *                      : Created on November 15, 2013, 10:37 AM
 *                      : Example code for energizing a stepper motor in half step drive
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

/* RC7, RC6, RC1 and RC0 bits goes LOGIC HIGH in half step sequence and energizes
   stepper motor field coils to rotate the shaft in half step anti-clockwise direction.

   Half Step driving sequence
   --------------------------

        bits  - RC7 RC6 RC1 RC0

                  10000000
                  11000000
                  01000000
                  01000010
                  00000010
                  00000011
                  00000001
                  10000001
 */

int main(void)
{
    TRISC = 0x00;                                                   /* Direction of PORTB set as output             */
    /* Stepper motor half step driving sequence */
    while(1)
    {
    PORTC = 0b10000000;
    delay_ms(100);
    PORTC = 0b11000000;
    delay_ms(100);
    PORTC = 0b01000000;
    delay_ms(100);
    PORTC = 0b01000010;
    delay_ms(100);
    PORTC = 0b00000010;
    delay_ms(100);
    PORTC = 0b00000011;
    delay_ms(100);
    PORTC = 0b00000001;
    delay_ms(100);
    PORTC = 0b10000001;
    delay_ms(100);
    }
    return (0);
}