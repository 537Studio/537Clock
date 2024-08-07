/*
537Clock
Version 1.3 Beta

include/language.h

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/ 
  
// 英语变体  
#define LANG_EN_US 0x0409 // 英语（美国）  
#define LANG_EN_GB 0x0809 // 英语（英国）  
#define LANG_EN_AU 0x0C09 // 英语（澳大利亚）  
#define LANG_EN_CA 0x1009 // 英语（加拿大）  
#define LANG_EN_NZ 0x1409 // 英语（新西兰）  
#define LANG_EN_IE 0x1809 // 英语（爱尔兰）  
#define LANG_EN_ZA 0x1C09 // 英语（南非）  
#define LANG_EN_JM 0x2009 // 英语（牙买加）  
#define LANG_EN_TT 0x2409 // 英语（特立尼达和多巴哥）  
#define LANG_EN_PH 0x3409 // 英语（菲律宾）  
#define LANG_EN_IN 0x4009 // 英语（印度）  
#define LANG_EN_MY 0x4409 // 英语（马来西亚）  
#define LANG_EN_SG 0x4809 // 英语（新加坡）  
  
// 中文变体  
#define LANG_ZH_CN 0x0804 // 简体中文（中国大陆）  
#define LANG_ZH_TW 0x0404 // 繁体中文（中国台湾省） 
#define LANG_ZH_HK 0x7C04 // 繁体中文（中国香港特别行政区），传统书写（非标准）  
#define LANG_ZH_MO 0x9004 // 繁体中文（中国澳门特别行政区），传统书写（非标准）  
  
// 法语变体  
#define LANG_FR_FR 0x040C // 法语（法国）  
#define LANG_FR_CA 0x0C0C // 法语（加拿大）  
#define LANG_FR_CH 0x100C // 法语（瑞士）  
#define LANG_FR_BE 0x140C // 法语（比利时）  
  
// 德语变体  
#define LANG_DE_DE 0x0407 // 德语（德国）  
#define LANG_DE_CH 0x0807 // 德语（瑞士）  
#define LANG_DE_AT 0x0C07 // 德语（奥地利）  
#define LANG_DE_LI 0x1407 // 德语（列支敦士登）  
  
// 日语  
#define LANG_JA_JP 0x0411 // 日语（日本）  
  
// 韩语  
#define LANG_KO_KR 0x0412 // 韩语（韩国）  

#include <windows.h>
int lang=0;
void getlanguage(){
	LANGID langID = GetUserDefaultUILanguage();
	switch(langID){
		case LANG_ZH_CN:
			lang=1;
			break;
		case LANG_ZH_TW:
			lang=1;
			break;
		case LANG_ZH_HK:
			lang=1;
			break;
		case LANG_ZH_MO:
			lang=1;
			break;
		default:
			break;
	}
} 
