#include <stdio.h>
#include <stdlib.h>
#include "Util.h"
#include "KeyProcess.h"
#include "GameProcess.h"
#include "DrawGame.h"

int main()
{
	SetCursorType(NO_CURSOR);

	while (1)
	{
		KeyProcess();
		GameProcess();
		DrawGame();
	}
}