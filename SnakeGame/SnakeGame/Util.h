#ifndef _UTIL_H_
#define _UTIL_H_
#include <Windows.h>

enum CURSOR_TYPE
{
	NO_CURSOR,
	SOLID_CURSOR,
	NORMAL_CURSOR
};

void GotoXY(int x, int y);
void SetCursorType(CURSOR_TYPE c);
#endif // !_UTIL_H_
