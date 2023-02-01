#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define MAP_WIDTH		10
#define MAP_HEIGHT	10

#define ROAD				0
#define WALL				1
#define GEM				2

#define EXTRA				224

#define LEFT				75
#define RIGHT				77
#define UP					72
#define DOWN				80
#define EXIT				0

enum CURSOR_TYPE
{
	NO_CURSOR,
	SOLID_CURSOR,
	NORMAL_CURSOR
};

void GotoXY(int x, int y)
{
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void SetCursorType(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO curInfo;
	switch (c)
	{
	case NO_CURSOR:
		curInfo.dwSize = 1;
		curInfo.bVisible = FALSE;
		break;
	case SOLID_CURSOR:
		curInfo.dwSize = 100;
		curInfo.bVisible = TRUE;
		break;
	case NORMAL_CURSOR:
		curInfo.dwSize = 20;
		curInfo.bVisible = TRUE;
		break;
	default:
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

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

	SetCursorType(NO_CURSOR);

	while (1)
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
		}

		value = -1;
		if (kbhit())
		{
			value = getch();
		}

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
				return 0;
			else if (value != -1)
				printf("잘못된 값을 입력하셨습니다.\n");

			break;
		}
	}
}