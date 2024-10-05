/*
537 Clock
Version 2.0 Beta

language.cpp

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/
#include "include/language.h"
#include "include/tclass.h"
LANGID langID=0;
void getlanguage(){
	langID=GetUserDefaultUILanguage();
}
void setlanguage(){
	switch(langID){
		case LANG_ZH_CN:
			//tprint("�й���½");
			break;
		case LANG_ZH_HK:
			//tprint("�й����");
			break;
		case LANG_ZH_MO:
			//tprint("�й�����");
			break;
		case LANG_ZH_TW:	
			//tprint("�й�̨��");
			break;
		case LANG_EN_US:
			//tprint("����");
			break;
		default:
			break;
	}
}
