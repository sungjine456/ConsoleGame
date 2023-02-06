#include "Initialized.h"

int snakeX[(MAP_HEIGHT - 2) * (MAP_WIDTH - 2)] = { 0, };
int snakeY[(MAP_HEIGHT - 2) * (MAP_WIDTH - 2)] = { 0, };
int feedX = 0, feedY = 0;
int length = 0;
int dir = 0;
int speed = 0;
int isStart = 0;

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
		printf("��");
		GotoXY(i, MAP_HEIGHT - 1);
		printf("��");
	}
	for (int i = 1; i < MAP_HEIGHT - 1; i++)
	{
		GotoXY(0, i);
		printf("��");
		GotoXY(MAP_WIDTH - 1, i);
		printf("��");
	}

	snakeX[HEAD] = MAP_WIDTH / 2 - 4;
	snakeY[HEAD] = MAP_HEIGHT / 2;

	GotoXY(snakeX[HEAD], snakeY[HEAD]);
	printf("��");

	for (int i = 1; i < length; i++)
	{
		snakeX[i] = snakeX[HEAD] - i;
		snakeY[i] = snakeY[HEAD];

		GotoXY(snakeX[i], snakeY[i]);
		printf("��");
	}

	feedX = MAP_WIDTH / 2 + 4;
	feedY = MAP_HEIGHT / 2;
	GotoXY(feedX, feedY);
	printf("��");
}