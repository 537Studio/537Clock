/*
537Clock
Version 2.0 Beta

537main.cpp

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/
#include <iostream>
#include <windows.h>
#include "include/graphics.h"
#include "include/tclass.h"
#include "include/language.h"
int main(int argc, char* argv[]){
	getlanguage();
	setlanguage();
	initgraph(600,400);
	tsleep(1000);
	closegraph();
	return 0;
}
