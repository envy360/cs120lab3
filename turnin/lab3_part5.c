/*	Author: lab
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRD = 0x00; PORTD = 0x00; // Configure port D's 8 pins as inputs
	DDRB = 0x06; PORTB = 0x00; // Configure port B's 8 pins 

	unsigned char tmpB = 0x00; // 
	unsigned short weight = 0x00; // Temporary variable to hold the total weight

    /* Insert your solution below */
    while (1) {
	weight = ( PIND << 1 ) + ( PINB & 0x01 );
	if (weight >= 70 ) tmpB = tmpB | 0x02; // set PB1 = 1
	else               tmpB = tmpB & 0xFD; // clear PB1 to 0
	if ( weight > 5  && weight < 70 ) tmpB = tmpB | 0x04; // set PB2 = 1
	else               tmpB = tmpB & 0xFB; // clear PB2 to 0

	PORTB = tmpB;
    }

    return 0;
}
