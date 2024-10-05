/*
537 Clock
Version 2.0 Beta

537main.cpp

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/
#include <iostream>
#include <windows.h>
#include "include/graphics.h"
#include "include/tclass.h"
#include "include/language.h"
#include "include/about.h" 
#include "appinfo.h"

int main(int argc, char* argv[]){
	getlanguage();
	setlanguage();
	
	if(argc>1){	//���������������� 1 ʱ��ֱ������ 
		std::string pm[argc];//�洢 string ���Ͳ��������� 
		for(int i=0; i<argc; i++) pm[i]=std::string(argv[i]);	//�洢���� 
		if(pm[1]=="-v" || pm[1]=="--version") aboutThisApp();
	} 
	aboutThisApp();
	return 0;
}
