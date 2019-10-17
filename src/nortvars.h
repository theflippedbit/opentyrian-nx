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
#ifndef NORTVARS_H
#define NORTVARS_H

#include "opentyr.h"

extern bool inputDetected;

bool JE_buttonPressed( void );

bool JE_anyButton( void );

void JE_dBar3( SDL_Surface *surface, Sint16 x,  Sint16 y,  Sint16 num,  Sint16 col );
void JE_barDrawShadow( SDL_Surface *surface, Uint16 x, Uint16 y, Uint16 res, Uint16 col, Uint16 amt, Uint16 xsize, Uint16 ysize );
void JE_wipeKey( void );

#endif /* NORTVARS_H */

