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
#ifndef MAININT_H
#define MAININT_H

#include "config.h"
#include "opentyr.h"
#include "palette.h"
#include "player.h"
#include "sprite.h"

extern bool button[4]; // fire, left fire, right fire, mode swap

extern Sint8 constantLastX;
extern Uint16 textErase;
extern Uint16 upgradeCost;
extern Uint16 downgradeCost;
extern bool performSave;
extern bool jumpSection;
extern bool useLastBank;

extern bool pause_pressed, ingamemenu_pressed;

/*void JE_textMenuWait ( Uint16 waittime, bool dogamma );*/

void JE_drawTextWindow( const char *text );
void JE_initPlayerData( void );
void JE_highScoreScreen( void );
void JE_gammaCorrect_func( Uint8 *col, float r );
void JE_gammaCorrect( Palette *colorBuffer, Uint8 gamma );
bool JE_gammaCheck( void );
/* void JE_textMenuWait( Uint16 *waitTime, bool doGamma ); /!\ In setup.h */
void JE_loadOrderingInfo( void );
void JE_nextEpisode( void );
void JE_helpSystem( Uint8 startTopic );
void JE_doInGameSetup( void );
bool JE_inGameSetup( void );
void JE_inGameHelp( void );
void JE_sortHighScores( void );
void JE_highScoreCheck( void );
void adjust_difficulty( void );

bool load_next_demo( void );
bool replay_demo_keys( void );
bool read_demo_keys( void );

void JE_SFCodes( Uint8 playerNum_, Sint16 PX_, Sint16 PY_, Sint16 playerX_, Sint16 playerY_ );
void JE_sort( void );

long weapon_upgrade_cost( long base_cost, unsigned int power );
ulong JE_getCost( Uint8 itemType, Uint16 itemNum );
Sint32 JE_getValue( Uint8 itemType, Uint16 itemNum );
ulong JE_totalScore( const Player * );

void JE_drawPortConfigButtons( void );
void JE_outCharGlow( Uint16 x, Uint16 y, const char *s );

void JE_playCredits( void );
void JE_endLevelAni( void );
void JE_drawCube( SDL_Surface * screen, Uint16 x, Uint16 y, Uint8 filter, Uint8 brightness );
void JE_handleChat( void );
bool str_pop_int( char *str, int *val );
void JE_loadScreen( void );
void JE_operation( Uint8 slot );
void JE_inGameDisplays( void );
void JE_mainKeyboardInput( void );
void JE_pauseGame( void );

void JE_playerMovement( Player *this_player, Uint8 inputDevice, Uint8 playerNum, Uint16 shipGr, Sprite2_array *shapes9ptr_ );
void JE_mainGamePlayerFunctions( void );
const char *JE_getName( Uint8 pnum );

void JE_playerCollide( Player *this_player, Uint8 playerNum );


#endif /* MAININT_H */

