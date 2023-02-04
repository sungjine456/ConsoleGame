#ifndef _GAME_PROCESS_H_
#define _GAME_PROCESS_H_

#include "KeyProcess.h"

#define MAP_WIDTH		10
#define MAP_HEIGHT	10

#define LEFT				75
#define RIGHT				77
#define UP					72
#define DOWN				80
#define EXIT				0

#define ROAD				0
#define WALL				1
#define GEM				2

extern int map[MAP_HEIGHT][MAP_WIDTH];
extern int playerX;
extern int playerY;

void GameProcess();
#endif // !_GAME_PROCESS_H_
