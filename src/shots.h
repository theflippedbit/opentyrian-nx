/*
 * OpenTyrian: A modern cross-platform port of Tyrian
 * Copyright (C) 2007-2013  The OpenTyrian Development Team
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
#ifndef SHOTS_H
#define SHOTS_H
#include "opentyr.h"

typedef struct {
	Sint16 shotX, shotY, shotXM, shotYM, shotXC, shotYC;
	bool shotComplicated;
	Sint16 shotDevX, shotDirX, shotDevY, shotDirY, shotCirSizeX, shotCirSizeY;
	Uint8 shotTrail;
	Uint16 shotGr, shotAni, shotAniMax;
	Uint8 shotDmg;
	Uint8 shotBlastFilter, chainReaction, playerNumber, aimAtEnemy, aimDelay, aimDelayMax;
} PlayerShotDataType;

#define MAX_PWEAPON     81 /* 81*/
extern PlayerShotDataType playerShotData[MAX_PWEAPON + 1];
extern Uint8 shotAvail[MAX_PWEAPON];

/** Used in the shop to show weapon previews. */
void simulate_player_shots( void );

/** Points shot movement in the specified direction. Used for the turret gun. */
void player_shot_set_direction( Sint16 shot_id, uint weapon_id, float direction );

/** Moves and draws a shot. Does \b not collide it with enemies.
 * \return False if the shot went offscreen, true otherwise.
 */
bool player_shot_move_and_draw(
		int shot_id, bool* out_is_special,
		int* out_shotx, int* out_shoty,
		Sint16* out_shot_damage, Uint8* out_blast_filter,
		Uint8* out_chain, Uint8* out_playerNum,
		Uint16* out_special_radiusw, Uint16* out_special_radiush );

/** Creates a player shot. */
Sint16 player_shot_create( Uint16 portnum, uint shot_i, Uint16 px, Uint16 py, Uint16 wpnum, Uint8 playernum );

#endif // SHOTS_H
