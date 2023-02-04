#include <stdio.h>
#include <conio.h>
#include "Util.h"

#define LEFT				75
#define RIGHT				77
#define UP					72
#define DOWN				80

#define MAP_WIDTH		19
#define MAP_HEIGHT	17

#define HEAD				0
#define TAIL				(length - 1)

int snakeX[(MAP_HEIGHT - 2) * (MAP_WIDTH - 2)];
int snakeY[(MAP_HEIGHT - 2) * (MAP_WIDTH - 2)];
int feedX, feedY;
int length;
int dir;
int speed;
int isStart;

void Initialized()
{
	system("cls");

	isStart = false;
	feedX = 0, feedY = 0;
	length = 4;
	dir = RIGHT;
	speed = 300;

	for (int i = 0; i < MAP_WIDTH; i++)
	{
		GotoXY(i, 0);
		printf("¡á");
		GotoXY(i, MAP_HEIGHT - 1);
		printf("¡á");
	}
	for (int i = 1; i < MAP_HEIGHT - 1; i++)
	{
		GotoXY(0, i);
		printf("¡á");
		GotoXY(MAP_WIDTH - 1, i);
		printf("¡á");
	}

	snakeX[HEAD] = MAP_WIDTH / 2 - 4;
	snakeY[HEAD] = MAP_HEIGHT / 2;

	GotoXY(snakeX[HEAD], snakeY[HEAD]);
	printf("¡ß");

	for (int i = 1; i < length; i++)
	{
		snakeX[i] = snakeX[HEAD] - i;
		snakeY[i] = snakeY[HEAD];

		GotoXY(snakeX[i], snakeY[i]);
		printf("¡Ý");
	}

	feedX = MAP_WIDTH / 2 + 4;
	feedY = MAP_HEIGHT / 2;
	GotoXY(feedX, feedY);
	printf("¢¾");
}
void KeyProcess()
{
	int key;

	if (_kbhit())
	{
		isStart = true;

		key = _getch();
		if (key == 224)
		{
			key = _getch();

			if (dir == LEFT && key != RIGHT ||
				dir == RIGHT && key != LEFT ||
				dir == UP && key != DOWN ||
				dir == DOWN && key != UP)
			{
				dir = key;
			}
		}
	}
}

int main()
{


	SetCursorType(NO_CURSOR);

	Initialized();

	while (true)
	{
		KeyProcess();

		if (!isStart)
			continue;

		if (snakeX[HEAD] <= 0 || snakeX[HEAD] >= MAP_WIDTH - 1 || snakeY[HEAD] <= 0 || snakeY[HEAD] >= MAP_HEIGHT - 1)
		{
			Initialized();
		}

		if (snakeX[HEAD] == feedX && snakeY[HEAD] == feedY)
		{
			bool isTry = false;
			length++;
			snakeX[TAIL] = snakeX[TAIL - 1];
			snakeY[TAIL] = snakeY[TAIL - 1];

			if (speed > 10) speed -= 2;

			do
			{
				isTry = false;
				feedX = rand() % (MAP_WIDTH - 2) + 1;
				feedY = rand() % (MAP_HEIGHT - 2) + 1;
				for (int i = 0; i < length; i++)
				{
					if (feedX == snakeX[i] && feedY == snakeY[i])
					{
						isTry = true;
						break;
					}
				}
			} while (isTry);

			GotoXY(feedX, feedY);
			printf("¢¾");
		}

		GotoXY(snakeX[HEAD], snakeY[HEAD]);
		printf("¡Ý");
		GotoXY(snakeX[TAIL], snakeY[TAIL]);
		printf("  ");

		for (int i = TAIL; i > 0; i--)
		{
			snakeX[i] = snakeX[i - 1];
			snakeY[i] = snakeY[i - 1];
		}

		switch (dir)
		{
		case LEFT:
			snakeX[HEAD]--;
			break;
		case RIGHT:
			snakeX[HEAD]++;
			break;
		case UP:
			snakeY[HEAD]--;
			break;
		case DOWN:
			snakeY[HEAD]++;
			break;
		}

		GotoXY(snakeX[HEAD], snakeY[HEAD]);
		printf("¡ß");
		Sleep(speed);
	}
}