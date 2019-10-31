/* 
 * OpenTyrian: A modern cross-platform port of Tyrian
 * Copyright (C) 2007-2009  The OpenTyrian Development Team
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "opentyr.h"

#include <SDL.h>

#include <stdbool.h>

#define SDL_POLL_INTERVAL 5

extern bool ESCPressed;
extern bool newkey, keydown;
extern SDL_Scancode lastkey_scan;
extern SDL_Keymod lastkey_mod;
extern Uint8 keysactive[SDL_NUM_SCANCODES];

extern bool new_text;
extern char last_text[SDL_TEXTINPUTEVENT_TEXT_SIZE];

extern bool input_grab_enabled;

void flush_events_buffer( void );
void wait_input( bool keyboard, bool joystick );
void wait_noinput( bool keyboard, bool joystick );
void init_keyboard( void );
void input_grab( bool enable );

void service_SDL_events( bool clear_new );

void sleep_game( void );

void JE_clearKeyboard( void );

#endif /* KEYBOARD_H */

