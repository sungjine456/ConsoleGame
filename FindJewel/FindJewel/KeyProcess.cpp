#include "KeyProcess.h"

int value = 0;
void KeyProcess()
{
	value = -1;

	if (kbhit())
	{
		value = getch();
		if (value == 224)
		{
			value = getch();
		}
	}
}