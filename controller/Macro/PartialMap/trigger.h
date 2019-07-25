/* Copyright (C) 2014-2016 by Jacob Alexander
 *
 * This file is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this file.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// ----- Includes -----

// Compiler Includes
#include <stdint.h>



// ----- Functions -----

// Updates trigger state, but does not add event to processing queue
void Trigger_state( uint8_t type, uint8_t state, uint8_t index );

// Updates trigger state, adds event to processing queue
// If event was already added this cycle, it will be discarded, state is not updated, and returns 0
// Returns 1 otherwise
uint8_t Trigger_update( uint8_t type, uint8_t state, uint8_t index );

void Trigger_process();
void Trigger_setup();

