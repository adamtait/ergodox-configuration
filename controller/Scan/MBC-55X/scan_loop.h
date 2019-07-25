/* Copyright (C) 2013-2016 by Jacob Alexander
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

#pragma once

// ----- Includes -----

// Compiler Includes
#include <stdint.h>

// Local Includes



// ----- Defines -----

#define KEYBOARD_KEYS 0x7F // 127 - Size of the array space for the keyboard(max index)
#define KEYBOARD_BUFFER 24 // Max number of key signals to buffer



// ----- Variables -----

extern volatile     uint8_t KeyIndex_Buffer[KEYBOARD_BUFFER];
extern volatile     uint8_t KeyIndex_BufferUsed;
extern volatile     uint8_t KeyIndex_Add_InputSignal;



// ----- Functions -----

// Functions used by main.c
void Scan_setup();
uint8_t Scan_loop();


// Functions available to macro.c
uint8_t Scan_sendData( uint8_t dataPayload );

void Scan_finishedWithMacro( uint8_t sentKeys );
void Scan_finishedWithOutput( uint8_t sentKeys );
void Scan_lockKeyboard( void );
void Scan_unlockKeyboard( void );
void Scan_resetKeyboard( void );
void Scan_currentChange( unsigned int current );

