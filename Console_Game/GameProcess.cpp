#include <stdio.h>
#include <stdlib.h>
#include "GameProcess.h"

int map[MAP_HEIGHT][MAP_WIDTH] = {
		{0, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 1, 1, 0, 1},
		{1, 0, 0, 0, 2, 0, 1, 1, 0, 1},
		{1, 1, 1, 1, 1, 0, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int playerX = 0;
int playerY = 0;

void GameProcess()
{
	switch (value)
	{
	case LEFT:
		if (playerX - 1 >= 0)
		{
			if (map[playerY][playerX - 1] == ROAD)
			{
				playerX--;
			}
			else if (map[playerY][playerX - 1] == GEM)
			{
				printf("축하합니다. 보석을 찾았습니다.\n");
				playerX = 0;
				playerY = 0;
			}
		}

		break;
	case RIGHT:
		if (playerX + 1 < MAP_WIDTH)
		{
			if (map[playerY][playerX + 1] == ROAD)
			{
				playerX++;
			}
			else if (map[playerY][playerX + 1] == GEM)
			{
				printf("축하합니다. 보석을 찾았습니다.\n");
				playerX = 0;
				playerY = 0;
			}
		}

		break;
	case UP:
		if (playerY - 1 >= 0)
		{
			if (map[playerY - 1][playerX] == ROAD)
			{
				playerY--;
			}
			else if (map[playerY - 1][playerX] == GEM)
			{
				printf("축하합니다. 보석을 찾았습니다.\n");
				playerX = 0;
				playerY = 0;
			}
		}

		break;
	case DOWN:
		if (playerY + 1 < MAP_HEIGHT)
		{
			if (map[playerY + 1][playerX] == ROAD)
			{
				playerY++;
			}
			else if (map[playerY + 1][playerX] == GEM)
			{
				printf("축하합니다. 보석을 찾았습니다.\n");
				playerX = 0;
				playerY = 0;
			}
		}

		break;
	default:
		if (value == EXIT)
			exit(0);
		else if (value != -1)
			printf("잘못된 값을 입력하셨습니다.\n");

		break;
	}
}