#include "GameProcess.h"

void GameProcess()
{
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

	for (int i = 1; i < length; i++)
	{
		if (snakeX[HEAD] == snakeX[i] && snakeY[HEAD] == snakeY[i])
		{
			Initialized();
		}
	}

	Sleep(speed);
}