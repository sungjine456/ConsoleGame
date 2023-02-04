#include "Util.h"

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