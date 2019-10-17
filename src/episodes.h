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
#ifndef EPISODES_H
#define EPISODES_H

#include "opentyr.h"

#include "lvlmast.h"


/* Episodes and general data */

#define FIRST_LEVEL 1
#define EPISODE_MAX 5
#ifdef TYRIAN2000
#define EPISODE_AVAILABLE 5
#else
#define EPISODE_AVAILABLE 4
#endif

typedef struct
{
	Uint16     drain;
	Uint8     shotrepeat;
	Uint8     multi;
	Uint16     weapani;
	Uint8     max;
	Uint8     tx, ty, aim;
	Uint8     attack[8], del[8]; /* [1..8] */
	Sint8 sx[8], sy[8]; /* [1..8] */
	Sint8 bx[8], by[8]; /* [1..8] */
	Uint16     sg[8]; /* [1..8] */
	Sint8 acceleration, accelerationx;
	Uint8     circlesize;
	Uint8     sound;
	Uint8     trail;
	Uint8     shipblastfilter;
} JE_WeaponType;

typedef struct
{
	char    name[31]; /* string [30] */
	Uint8 opnum;
	Uint16 op[2][11]; /* [1..2, 1..11] */
	Uint16 cost;
	Uint16 itemgraphic;
	Uint16 poweruse;
} JE_WeaponPortType[PORT_NUM + 1]; /* [0..portnum] */

typedef struct
{
	char        name[31]; /* string [30] */
	Uint16     itemgraphic;
	Uint8     power;
	Sint8 speed;
	Uint16     cost;
} JE_PowerType[POWER_NUM + 1]; /* [0..powernum] */

typedef struct
{
	char    name[31]; /* string [30] */
	Uint16 itemgraphic;
	Uint8 pwr;
	Uint8 stype;
	Uint16 wpn;
} JE_SpecialType[SPECIAL_NUM + 1]; /* [0..specialnum] */

typedef struct
{
	char        name[31]; /* string [30] */
	Uint8     pwr;
	Uint16     itemgraphic;
	Uint16     cost;
	Uint8     tr, option;
	Sint8 opspd;
	Uint8     ani;
	Uint16     gr[20]; /* [1..20] */
	Uint8     wport;
	Uint16     wpnum;
	Uint8     ammo;
	bool  stop;
	Uint8     icongr;
} JE_OptionType;

typedef struct
{
	char    name[31]; /* string [30] */
	Uint8 tpwr;
	Uint8 mpwr;
	Uint16 itemgraphic;
	Uint16 cost;
} JE_ShieldType[SHIELD_NUM + 1]; /* [0..shieldnum] */

typedef struct
{
	char        name[31]; /* string [30] */
	Uint16     shipgraphic;
	Uint16     itemgraphic;
	Uint8     ani;
	Sint8 spd;
	Uint8     dmg;
	Uint16     cost;
	Uint8     bigshipgraphic;
} JE_ShipType[SHIP_NUM + 1]; /* [0..shipnum] */

/* EnemyData */
typedef struct
{
	Uint8     ani;
	Uint8     tur[3]; /* [1..3] */
	Uint8     freq[3]; /* [1..3] */
	Sint8 xmove;
	Sint8 ymove;
	Sint8 xaccel;
	Sint8 yaccel;
	Sint8 xcaccel;
	Sint8 ycaccel;
	Sint16  startx;
	Sint16  starty;
	Sint8 startxc;
	Sint8 startyc;
	Uint8     armor;
	Uint8     esize;
	Uint16     egraphic[20];  /* [1..20] */
	Uint8     explosiontype;
	Uint8     animate;       /* 0:Not Yet   1:Always   2:When Firing Only */
	Uint8     shapebank;     /* See LEVELMAK.DOC */
	Sint8 xrev, yrev;
	Uint16     dgr;
	Sint8 dlevel;
	Sint8 dani;
	Uint8     elaunchfreq;
	Uint16     elaunchtype;
	Sint16  value;
	Uint16     eenemydie;
} JE_EnemyDatType[ENEMY_NUM + 1]; /* [0..enemynum] */

extern JE_WeaponPortType weaponPort;
extern JE_WeaponType weapons[WEAP_NUM + 1]; /* [0..weapnum] */
extern JE_PowerType powerSys;
extern JE_ShipType ships;
extern JE_OptionType options[OPTION_NUM + 1]; /* [0..optionnum] */
extern JE_ShieldType shields;
extern JE_SpecialType special;
extern JE_EnemyDatType enemyDat;
extern Uint8 initial_episode_num, episodeNum;
extern bool episodeAvail[EPISODE_MAX];

extern char episode_file[13], cube_file[13];

extern Sint32 episode1DataLoc;
extern bool bonusLevel;
extern bool jumpBackToEpisode1;

void JE_loadItemDat( void );
void JE_initEpisode( Uint8 newEpisode );
unsigned int JE_findNextEpisode( void );
void JE_scanForEpisodes( void );

#endif /* EPISODES_H */

