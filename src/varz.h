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
#ifndef VARZ_H
#define VARZ_H

#include "episodes.h"
#include "opentyr.h"
#include "player.h"
#include "sprite.h"

#include <stdbool.h>

#define SA 7

enum
{
	SA_NONE = 0,
	SA_NORTSHIPZ = 7,
	
	// only used for code entry
	SA_DESTRUCT = 8,
	SA_ENGAGE = 9,
	
	// only used in pItems[P_SUPERARCADE]
	SA_SUPERTYRIAN = 254,
	SA_ARCADE = 255
};

#define ENEMY_SHOT_MAX  60 /* 60*/

#define CURRENT_KEY_SPEED 1  /*Keyboard/Joystick movement rate*/

#define MAX_EXPLOSIONS           200
#define MAX_REPEATING_EXPLOSIONS 20
#define MAX_SUPERPIXELS          101

struct JE_SingleEnemyType
{
	Uint8     fillbyte;
	Sint16  ex, ey;     /* POSITION */
	Sint8 exc, eyc;   /* CURRENT SPEED */
	Sint8 exca, eyca; /* RANDOM ACCELERATION */
	Sint8 excc, eycc; /* FIXED ACCELERATION WAITTIME */
	Sint8 exccw, eyccw;
	Uint8     armorleft;
	Uint8     eshotwait[3], eshotmultipos[3]; /* [1..3] */
	Uint8     enemycycle;
	Uint8     ani;
	Uint16     egr[20]; /* [1..20] */
	Uint8     size;
	Uint8     linknum;
	Uint8     aniactive;
	Uint8     animax;
	Uint8     aniwhenfire;
	Sprite2_array *sprite2s;
	Sint8 exrev, eyrev;
	Sint16  exccadd, eyccadd;
	Uint8     exccwmax, eyccwmax;
	void       *enemydatofs;
	bool  edamaged;
	Uint16     enemytype;
	Uint8     animin;
	Uint16     edgr;
	Sint8 edlevel;
	Sint8 edani;
	Uint8     fill1;
	Uint8     filter;
	Sint16  evalue;
	Sint16  fixedmovey;
	Uint8     freq[3]; /* [1..3] */
	Uint8     launchwait;
	Uint16     launchtype;
	Uint8     launchfreq;
	Uint8     xaccel;
	Uint8     yaccel;
	Uint8     tur[3]; /* [1..3] */
	Uint16     enemydie; /* Enemy created when this one dies */
	bool  enemyground;
	Uint8     explonum;
	Uint16     mapoffset;
	bool  scoreitem;

	bool  special;
	Uint8     flagnum;
	bool  setto;

	Uint8     iced; /*Duration*/

	Uint8     launchspecial;

	Sint16  xminbounce;
	Sint16  xmaxbounce;
	Sint16  yminbounce;
	Sint16  ymaxbounce;
	Uint8     fill[3]; /* [1..3] */
};

typedef struct JE_SingleEnemyType JE_MultiEnemyType[100]; /* [1..100] */

typedef Uint16 JE_DanCShape[(24 * 28) / 2]; /* [1..(24*28) div 2] */

typedef char JE_CharString[256]; /* [1..256] */

typedef Uint8 JE_Map1Buffer[24 * 28 * 13 * 4]; /* [1..24*28*13*4] */

typedef Uint8 *JE_MapType[300][14]; /* [1..300, 1..14] */
typedef Uint8 *JE_MapType2[600][14]; /* [1..600, 1..14] */
typedef Uint8 *JE_MapType3[600][15]; /* [1..600, 1..15] */

struct JE_EventRecType
{
	Uint16     eventtime;
	Uint8     eventtype;
	Sint16  eventdat, eventdat2;
	Sint8 eventdat3, eventdat5, eventdat6;
	Uint8     eventdat4;
};

struct JE_MegaDataType1
{
	JE_MapType mainmap;
	struct
	{
		JE_DanCShape sh;
	} shapes[72]; /* [0..71] */
	Uint8 tempdat1;
	/*JE_DanCShape filler;*/
};

struct JE_MegaDataType2
{
	JE_MapType2 mainmap;
	struct
	{
		Uint8 nothing[3]; /* [1..3] */
		Uint8 fill;
		JE_DanCShape sh;
	} shapes[71]; /* [0..70] */
	Uint8 tempdat2;
};

struct JE_MegaDataType3
{
	JE_MapType3 mainmap;
	struct
	{
		Uint8 nothing[3]; /* [1..3] */
		Uint8 fill;
		JE_DanCShape sh;
	} shapes[70]; /* [0..69] */
	Uint8 tempdat3;
};

typedef Uint8 JE_EnemyAvailType[100]; /* [1..100] */

typedef struct {
	Sint16 sx, sy;
	Sint16 sxm, sym;
	Sint8 sxc, syc;
	Uint8 tx, ty;
	Uint16 sgr;
	Uint8 sdmg;
	Uint8 duration;
	Uint16 animate;
	Uint16 animax;
	Uint8 fill[12];
} EnemyShotType;

typedef struct {
	unsigned int ttl;
	signed int x, y;
	signed int delta_x, delta_y;
	bool fixed_position;
	bool follow_player;
	unsigned int sprite;
} explosion_type;

typedef struct {
	unsigned int delay;
	unsigned int ttl;
	unsigned int x, y;
	bool big;
} rep_explosion_type;

typedef struct {
	unsigned int x, y, z;
	signed int delta_x, delta_y;
	Uint8 color;
} superpixel_type;

extern Sint16 tempDat, tempDat2, tempDat3;
extern const Uint8 SANextShip[SA + 2];
extern const Uint16 SASpecialWeapon[SA];
extern const Uint16 SASpecialWeaponB[SA];
extern const Uint8 SAShip[SA];
extern const Uint16 SAWeapon[SA][5];
extern const Uint8 specialArcadeWeapon[PORT_NUM];
extern const Uint8 optionSelect[16][3][2];
extern const Uint16 PGR[21];
extern const Uint8 PAni[21];
extern const Uint16 linkGunWeapons[38];
extern const Uint16 chargeGunWeapons[38];
extern const Uint8 randomEnemyLaunchSounds[3];
extern const Uint8 keyboardCombos[26][8];
extern const Uint8 shipCombosB[21];
extern const Uint8 superTyrianSpecials[4];
extern const Uint8 shipCombos[14][3];
extern Uint8 SFCurrentCode[2][21];
extern Uint8 SFExecuted[2];
extern Uint8 lvlFileNum;
extern Uint16 maxEvent, eventLoc;
extern Uint16 tempBackMove, explodeMove;
extern Uint8 levelEnd;
extern Uint16 levelEndFxWait;
extern Sint8 levelEndWarp;
extern bool endLevel, reallyEndLevel, waitToEndLevel, playerEndLevel, normalBonusLevelCurrent, bonusLevelCurrent, smallEnemyAdjust, readyToEndLevel, quitRequested;
extern Uint8 newPL[10];
extern Uint16 returnLoc;
extern bool returnActive;
extern Uint16 galagaShotFreq;
extern Sint32 galagaLife;
extern bool debug;
extern Uint32 debugTime, lastDebugTime;
extern Sint32 debugHistCount;
extern float debugHist;
extern Uint16 curLoc;
extern bool firstGameOver, gameLoaded, enemyStillExploding;
extern Uint16 totalEnemy;
extern Uint16 enemyKilled;
extern struct JE_MegaDataType1 megaData1;
extern struct JE_MegaDataType2 megaData2;
extern struct JE_MegaDataType3 megaData3;
extern Uint8 flash;
extern Sint8 flashChange;
extern Uint8 displayTime;

extern bool play_demo, record_demo, stopped_demo;
extern Uint8 demo_num;
extern FILE *demo_file;

extern Uint8 demo_keys, next_demo_keys;
extern Uint16 demo_keys_wait;

extern Uint8 soundQueue[8];
extern bool enemyContinualDamage;
extern bool enemiesActive;
extern bool forceEvents;
extern bool stopBackgrounds;
extern Uint8 stopBackgroundNum;
extern Uint8 damageRate;
extern bool background3x1;
extern bool background3x1b;
extern bool levelTimer;
extern Uint16 levelTimerCountdown;
extern Uint16 levelTimerJumpTo;
extern bool randomExplosions;
extern bool editShip1, editShip2;
extern bool globalFlags[10];
extern Uint8 levelSong;
extern bool loadDestruct;
extern Uint16 mapOrigin, mapPNum;
extern Uint8 mapPlanet[5], mapSection[5];
extern bool moveTyrianLogoUp;
extern bool skipStarShowVGA;
extern JE_MultiEnemyType enemy;
extern JE_EnemyAvailType enemyAvail;
extern Uint16 enemyOffset;
extern Uint16 enemyOnScreen;
extern Uint8 enemyShapeTables[6];
extern Uint16 superEnemy254Jump;
extern explosion_type explosions[MAX_EXPLOSIONS];
extern Sint16 explosionFollowAmountX, explosionFollowAmountY;
extern bool fireButtonHeld;
extern bool enemyShotAvail[ENEMY_SHOT_MAX];
extern EnemyShotType enemyShot[ENEMY_SHOT_MAX];
extern Uint8 zinglonDuration;
extern Uint8 astralDuration;
extern Uint16 flareDuration;
extern bool flareStart;
extern Sint8 flareColChg;
extern Uint8 specialWait;
extern Uint8 nextSpecialWait;
extern bool spraySpecial;
extern Uint8 doIced;
extern bool infiniteShot;
extern bool allPlayersGone;
extern const uint shadowYDist;
extern float optionSatelliteRotate;
extern Sint16 optionAttachmentMove;
extern bool optionAttachmentLinked, optionAttachmentReturn;
extern Uint8 chargeWait, chargeLevel, chargeMax, chargeGr, chargeGrWait;
extern Uint16 neat;
extern rep_explosion_type rep_explosions[MAX_REPEATING_EXPLOSIONS];
extern superpixel_type superpixels[MAX_SUPERPIXELS];
extern unsigned int last_superpixel;
extern Uint8 temp, temp2, temp3;
extern Uint16 tempX, tempY;
extern Uint16 tempW;
extern bool doNotSaveBackup;
extern Uint16 x, y;
extern Sint16 b;
extern Uint8 **BKwrap1to, **BKwrap2to, **BKwrap3to, **BKwrap1, **BKwrap2, **BKwrap3;
extern Sint8 specialWeaponFilter, specialWeaponFreq;
extern Uint16 specialWeaponWpn;
extern bool linkToPlayer;
extern Uint16 shipGr, shipGr2;
extern Sprite2_array *shipGrPtr, *shipGr2ptr;

static const int hud_sidekick_y[2][2] =
{
	{  64,  82 }, // one player HUD
	{ 108, 126 }, // two player HUD
};

void JE_getShipInfo( void );
Uint16 JE_SGr( Uint16 ship, Sprite2_array **ptr );

void JE_drawOptions( void );

void JE_tyrianHalt( Uint8 code ); /* This ends the game */
void JE_specialComplete( Uint8 playernum, Uint8 specialType );
void JE_doSpecialShot( Uint8 playernum, uint *armor, uint *shield );

void JE_wipeShieldArmorBars( void );
Uint8 JE_playerDamage( Uint8 temp, Player * );

void JE_setupExplosion( signed int x, signed int y, signed int delta_y, unsigned int type, bool fixed_position, bool follow_player );
void JE_setupExplosionLarge( bool enemyground, Uint8 explonum, Sint16 x, Sint16 y );

void JE_drawShield( void );
void JE_drawArmor( void );

Uint16 JE_portConfigs( void );

/*SuperPixels*/
void JE_doSP( Uint16 x, Uint16 y, Uint16 num, Uint8 explowidth, Uint8 color );
void JE_drawSP( void );

void JE_drawOptionLevel( void );


#endif /* VARZ_H */

