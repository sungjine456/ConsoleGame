#include "DrawGame.h"

void DrawGame()
{
	for (int y = 0; y < MAP_HEIGHT; y++)
	{
		for (int x = 0; x < MAP_WIDTH; x++)
		{
			GotoXY(x, y);
			if (map[y][x] == ROAD)
			{
				if (playerX == x && playerY == y)
				{
					printf("��");
				}
				else {
					printf("��");
				}
			}
			if (map[y][x] == WALL)
				printf("��");
			if (map[y][x] == GEM)
				printf("��");
		}
	}
}