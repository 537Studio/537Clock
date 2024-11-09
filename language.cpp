/*
537 Clock
Version 2.0 Beta

language.cpp

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/
#include "include/language.h"
#include "include/tclass.h"
#include <iostream>
#include <string>
#include <locale>
LANGID langID=0;
void getlanguage(){
	langID=GetUserDefaultUILanguage();
}
void setlanguage(){
	switch(langID){
		case LANG_ZH_CN:
			//tprint("中国大陆");
			setlocale(LC_ALL,"zh_CN.UTF-8"); //转换为中文字符，同时可用"chs"
			break;
		case LANG_ZH_HK:
			//tprint("中国香港");
			break;
		case LANG_ZH_MO:
			//tprint("中国澳门");
			break;
		case LANG_ZH_TW:	
			//tprint("中国台湾");
			break;
		case LANG_EN_US:
			//tprint("美国");
			break;
		default:
			break;
	}
}
/*
简体中文
Windows: "zh_CN" 或 "zh_CN.UTF-8"
Linux/Unix: "zh_CN.UTF-8"
繁体中文
Windows: "zh_TW" 或 "zh_TW.UTF-8"
Linux/Unix: "zh_TW.UTF-8" 或 "zh_TW.big5"
英文
Windows: "en_US" 或 "en_US.UTF-8"
Linux/Unix: "en_US.UTF-8"
法语
Windows: "fr_FR" 或 "fr_FR.UTF-8"
Linux/Unix: "fr_FR.UTF-8"
德语
Windows: "de_DE" 或 "de_DE.UTF-8"
Linux/Unix: "de_DE.UTF-8"
日语
Windows: "ja_JP" 或 "ja_JP.UTF-8"
Linux/Unix: "ja_JP.UTF-8"
韩语
Windows: "ko_KR" 或 "ko_KR.UTF-8"
Linux/Unix: "ko_KR.UTF-8"
*/