/* Copyright (C) 2011-2014 by Jacob Alexander
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

// ----- Includes -----

// Compiler Includes
#include <Lib/MainLib.h>


// Project Includes
#include "led.h"



// ----- Functions -----

// Error LED Setup
inline void init_errorLED()
{
// AVR
#if defined(_at90usb162_) || defined(_atmega32u4_) || defined(_at90usb646_) || defined(_at90usb1286_)

	// Use pin D6 as an output (LED)
	DDRD |= (1<<6);

// ARM
#elif defined(_mk20dx128_) || defined(_mk20dx256_)

	// Enable pin
	GPIOC_PDDR |= (1<<5);

	// Setup pin - Pin 13 -> C5 - See Lib/pin_map.teensy3 for more details on pins
	PORTC_PCR5 = PORT_PCR_SRE | PORT_PCR_DSE | PORT_PCR_MUX(1);

// MCHCK / Kiibohd-dfu
#elif defined(_mk20dx128vlf5_)

/* Actual MCHCK
	// Enable pin
	GPIOB_PDDR |= (1<<16);

	// Setup pin - B16 - See Lib/pin_map.mchck for more details on pins
	PORTB_PCR16 = PORT_PCR_SRE | PORT_PCR_DSE | PORT_PCR_MUX(1);
*/
	// Kiibohd MCHCK Variant
	// Enable pin
	GPIOA_PDDR |= (1<<19);

	// Setup pin - A19 - See Lib/pin_map.mchck for more details on pins
	PORTA_PCR19 = PORT_PCR_SRE | PORT_PCR_DSE | PORT_PCR_MUX(1);

// Kiibohd-dfu
#elif defined(_mk20dx256vlh7_)
	// Kiibohd-dfu
	// Enable pin
	GPIOA_PDDR |= (1<<5);

	// Setup pin - A5 - See Lib/pin_map.mchck for more details on pins
	PORTA_PCR5 = PORT_PCR_SRE | PORT_PCR_DSE | PORT_PCR_MUX(1);
#endif
}

// Error LED Control
inline void errorLED( uint8_t on )
{
// AVR
#if defined(_at90usb162_) || defined(_atmega32u4_) || defined(_at90usb646_) || defined(_at90usb1286_)

	// Error LED On (D6)
	if ( on ) {
		PORTD |= (1<<6);
	}
	// Error LED Off
	else {
		PORTD &= ~(1<<6);
	}

// ARM
#elif defined(_mk20dx128_) || defined(_mk20dx256_)

	// Error LED On (C5)
	if ( on ) {
		GPIOC_PSOR |= (1<<5);
	}
	// Error LED Off
	else {
		GPIOC_PCOR |= (1<<5);
	}

// MCHCK
#elif defined(_mk20dx128vlf5_)

/* Actual MCHCK
	// Error LED On (B16)
	if ( on ) {
		GPIOB_PSOR |= (1<<16);
	}
	// Error LED Off
	else {
		GPIOB_PCOR |= (1<<16);
	}
*/
	// Kiibohd MCHCK Variant
	// Error LED On (A19)
	if ( on ) {
		GPIOA_PSOR |= (1<<19);
	}
	// Error LED Off
	else {
		GPIOA_PCOR |= (1<<19);
	}

// Kiibohd-dfu
#elif defined(_mk20dx256vlh7_)
	// Kiibohd-dfu
	// Error LED On (A5)
	if ( on ) {
		GPIOA_PSOR |= (1<<5);
	}
	// Error LED Off
	else {
		GPIOA_PCOR |= (1<<5);
	}

#endif
}

