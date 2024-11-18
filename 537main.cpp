/*
537 Clock
Version 2.0 Beta

537main.cpp

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/
#include <iostream>
#include <tclass.h>
//#include "include/language.h"
#include <about.h> 
#include "537Clock_AppInfo.h"
#include <locale>

int main(int argc, char* argv[]){
	//getlanguage();
	//setlanguage();
	setlocale(LC_ALL,"zh_CN.UTF-8"); //转换为中文字符，同时可用"chs"
	if(argc>1){	//带参数启动，等于 1 时是直接启动 
		std::string pm[argc];//存储 string 类型参数的数组 
		for(int i=0; i<argc; i++) pm[i]=std::string(argv[i]);	//存储参数 
		if(pm[1]=="-v" || pm[1]=="--version"){
			aboutThisApp();
			return 0;
		}
	} 
	aboutThisApp();
	return 0;
}
