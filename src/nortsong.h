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
#ifndef NORTSONG_H
#define NORTSONG_H

#include "opentyr.h"

#include "musmast.h"
#include "sndmast.h"

#include <SDL.h>

extern Uint32 target, target2;

extern Uint16 frameCount, frameCount2, frameCountMax;

extern Uint8 *digiFx[SAMPLE_COUNT];
extern Uint16 fxSize[SAMPLE_COUNT];

extern Uint16 tyrMusicVolume, fxVolume;
extern Uint16 fxPlayVol;
extern Uint16 tempVolume;

extern Uint16 speed;

extern float jasondelay;

void setdelay( Uint8 delay );
void setjasondelay( int delay );
void setjasondelay2( int delay );
int delaycount( void );
int delaycount2( void );

void wait_delay( void );
void service_wait_delay( void );
void wait_delayorinput( bool keyboard, bool joystick );

void JE_resetTimerInt( void );
void JE_setTimerInt( void );

void JE_calcFXVol( void );
void JE_changeVolume( Uint16 *music, int music_delta, Uint16 *sample, int sample_delta );

void JE_loadSndFile( const char *effects_sndfile, const char *voices_sndfile );
void JE_playSampleNum( Uint8 samplenum );

#endif /* NORTSONG_H */

