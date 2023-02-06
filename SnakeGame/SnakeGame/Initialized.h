#ifndef _INITIALIZED_H_
#define _INITIALIZED_H_

#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#include "KeyProcess.h"

#define MAP_WIDTH			19
#define MAP_HEIGHT			17

#define HEAD				0
#define TAIL				(length - 1)

extern int snakeX[(MAP_HEIGHT - 2) * (MAP_WIDTH - 2)];
extern int snakeY[(MAP_HEIGHT - 2) * (MAP_WIDTH - 2)];
extern int feedX, feedY;
extern int length;
extern int dir;
extern int speed;
extern int isStart;

void Initialized();
#endif // !_INITIALIZED_H_
