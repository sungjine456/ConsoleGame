#include <stdio.h>
#include "Initialized.h"
#include "KeyProcess.h"
#include "GameProcess.h"

int main()
{
	SetCursorType(NO_CURSOR);

	Initialized();

	while (true)
	{
		KeyProcess();

		if (!isStart)
			continue;

		GameProcess();
	}
}