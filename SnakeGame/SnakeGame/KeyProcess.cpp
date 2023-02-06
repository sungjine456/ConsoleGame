#include "KeyProcess.h"

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