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
#ifndef CONFIG_H
#define CONFIG_H

#include "opentyr.h"
#include "config_file.h"

#include <stdio.h>
#include <SDL.h>


#define SAVE_FILES_NUM (11 * 2)

/* These are necessary because the size of the structure has changed from the original, but we
   need to know the original sizes in order to find things in TYRIAN.SAV */
#define SAVE_FILES_SIZE 2398
#define SIZEOF_SAVEGAMETEMP SAVE_FILES_SIZE + 4 + 100
#define SAVE_FILE_SIZE (SIZEOF_SAVEGAMETEMP - 4)

/*#define SAVE_FILES_SIZE (2502 - 4)
#define SAVE_FILE_SIZE (SAVE_FILES_SIZE)*/

typedef SDL_Scancode JE_KeySettingType[8]; /* [1..8] */
typedef Uint8 JE_PItemsType[12]; /* [1..12] */

typedef Uint8 JE_EditorItemAvailType[100]; /* [1..100] */

typedef struct
{
	Uint16       encode;
	Uint16       level;
	JE_PItemsType items;
	Sint32    score;
	Sint32    score2;
	char          levelName[11]; /* string [9]; */ /* SYN: Added one more byte to match lastLevelName below */
	char       name[15]; /* [1..14] */ /* SYN: Added extra byte for null */
	Uint8       cubes;
	Uint8       power[2]; /* [1..2] */
	Uint8       episode;
	JE_PItemsType lastItems;
	Uint8       difficulty;
	Uint8       secretHint;
	Uint8       input1;
	Uint8       input2;
	bool    gameHasRepeated; /*See if you went from one episode to another*/
	Uint8       initialDifficulty;

	/* High Scores - Each episode has both sets of 1&2 player selections - with 3 in each */
	Sint32    highScore1,
	              highScore2;
	char          highScoreName[30]; /* string [29] */
	Uint8       highScoreDiff;
} JE_SaveFileType;

typedef JE_SaveFileType JE_SaveFilesType[SAVE_FILES_NUM]; /* [1..savefilesnum] */
typedef Uint8 JE_SaveGameTemp[SAVE_FILES_SIZE + 4 + 100]; /* [1..sizeof(savefilestype) + 4 + 100] */

extern const Uint8 cryptKey[10];
extern const JE_KeySettingType defaultKeySettings;
extern const char defaultHighScoreNames[34][23];
extern const char defaultTeamNames[22][25];
extern const JE_EditorItemAvailType initialItemAvail;
extern bool smoothies[9];
extern Uint8 starShowVGASpecialCode;
extern Uint16 lastCubeMax, cubeMax;
extern Uint16 cubeList[4];
extern bool gameHasRepeated;
extern Sint8 difficultyLevel, oldDifficultyLevel, initialDifficulty;
extern uint power, lastPower, powerAdd;
extern Uint8 shieldWait, shieldT;

enum
{
	SHOT_FRONT,
	SHOT_REAR,
	SHOT_LEFT_SIDEKICK,
	SHOT_RIGHT_SIDEKICK,
	SHOT_MISC,
	SHOT_P2_CHARGE,
	SHOT_P1_SUPERBOMB,
	SHOT_P2_SUPERBOMB,
	SHOT_SPECIAL,
	SHOT_NORTSPARKS,
	SHOT_SPECIAL2
};

extern Uint8 shotRepeat[11], shotMultiPos[11];
extern bool portConfigChange, portConfigDone;
extern char lastLevelName[11], levelName[11];
extern Uint8 mainLevel, nextLevel, saveLevel;
extern JE_KeySettingType keySettings;
extern Sint8 levelFilter, levelFilterNew, levelBrightness, levelBrightnessChg;
extern bool filtrationAvail, filterActive, filterFade, filterFadeStart;
extern bool gameJustLoaded;
extern bool galagaMode;
extern bool extraGame;
extern bool twoPlayerMode, twoPlayerLinked, onePlayerAction, superTyrian, trentWin;
extern Uint8 superArcadeMode;
extern Uint8 superArcadePowerUp;
extern float linkGunDirec;
extern Uint8 inputDevice[2];
extern Uint8 secretHint;
extern Uint8 background3over;
extern Uint8 background2over;
extern Uint8 gammaCorrection;
extern bool superPause, explosionTransparent, youAreCheating, displayScore, background2, smoothScroll, wild, superWild, starActive, topEnemyOver, skyEnemyOverAll, background2notTransparent;
extern Uint8 versionNum;
extern Uint8 fastPlay;
extern bool pentiumMode;
extern Uint8 gameSpeed;
extern Uint8 processorType;
extern JE_SaveFilesType saveFiles;
extern JE_SaveGameTemp saveTemp;
extern Uint16 editorLevel;

extern Config opentyrian_config;

void JE_initProcessorType( void );
void JE_setNewGameSpeed( void );
const char *get_user_directory( void );
void JE_loadConfiguration( void );
void JE_saveConfiguration( void );

void JE_saveGame( Uint8 slot, const char *name );
void JE_loadGame( Uint8 slot );

void JE_encryptSaveTemp( void );
void JE_decryptSaveTemp( void );

#endif /* CONFIG_H */

