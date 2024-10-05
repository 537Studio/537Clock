#include "include/language.h"
#include "include/tclass.h"
LANGID langID=0;
void getlanguage(){
	langID=GetUserDefaultUILanguage();
}
void setlanguage(){
	switch(langID){
		case LANG_ZH_CN:
			tprint("中国大陆");
			break;
		case LANG_ZH_HK:
			tprint("中国香港");
			break;
		case LANG_ZH_MO:
			tprint("中国澳门");
			break;
		case LANG_ZH_TW:	
			tprint("中国台湾");
			break;
		case LANG_EN_US:
			tprint("美国");
			break;
		default:
			break;
	}
}
