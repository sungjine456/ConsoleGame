#include <stdio.h>

#define MAP_WIDTH		10
#define MAP_HEIGHT	10

#define ROAD				0
#define WALL				1
#define GEM				2

#define LEFT				1
#define RIGHT				2
#define UP					3
#define DOWN				4
#define EXIT				0

int main()
{
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
	int value = 0;

	while (true)
	{
		for (int y = 0; y < MAP_HEIGHT; y++)
		{
			for (int x = 0; x < MAP_WIDTH; x++)
			{
				if (map[y][x] == ROAD)
				{
					if (playerX == x && playerY == y)
					{
						printf("♀");
					}
					else {
						printf("□");
					}
				}
				if (map[y][x] == WALL)
					printf("■");
				if (map[y][x] == GEM)
					printf("▼");
			}
			printf("\n");
		}

		printf("1.왼쪽 2.오른쪽 3.위 4.아래 0.종료\n");
		scanf("%d", &value);

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
			if (value == EXIT) return 0;

			printf("잘못된 값을 입력하셨습니다.\n");

			break;
		}
	}
}