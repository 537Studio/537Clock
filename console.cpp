#include "include/console.h"

void SetConsoleColor(WORD color){  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleTextAttribute(hConsole, color);  
}
