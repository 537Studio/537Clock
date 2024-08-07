/*
537Clock
Version 1.3 Beta

include/language.h

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/ 
  
// Ӣ�����  
#define LANG_EN_US 0x0409 // Ӣ�������  
#define LANG_EN_GB 0x0809 // Ӣ�Ӣ����  
#define LANG_EN_AU 0x0C09 // Ӣ��Ĵ����ǣ�  
#define LANG_EN_CA 0x1009 // Ӣ����ô�  
#define LANG_EN_NZ 0x1409 // Ӣ���������  
#define LANG_EN_IE 0x1809 // Ӣ���������  
#define LANG_EN_ZA 0x1C09 // Ӣ��Ϸǣ�  
#define LANG_EN_JM 0x2009 // Ӣ�����ӣ�  
#define LANG_EN_TT 0x2409 // Ӣ��������Ͷ�͸磩  
#define LANG_EN_PH 0x3409 // Ӣ����ɱ���  
#define LANG_EN_IN 0x4009 // Ӣ�ӡ�ȣ�  
#define LANG_EN_MY 0x4409 // Ӣ��������ǣ�  
#define LANG_EN_SG 0x4809 // Ӣ��¼��£�  
  
// ���ı���  
#define LANG_ZH_CN 0x0804 // �������ģ��й���½��  
#define LANG_ZH_TW 0x0404 // �������ģ��й�̨��ʡ�� 
#define LANG_ZH_HK 0x7C04 // �������ģ��й�����ر�������������ͳ��д���Ǳ�׼��  
#define LANG_ZH_MO 0x9004 // �������ģ��й������ر�������������ͳ��д���Ǳ�׼��  
  
// �������  
#define LANG_FR_FR 0x040C // ���������  
#define LANG_FR_CA 0x0C0C // ������ô�  
#define LANG_FR_CH 0x100C // �����ʿ��  
#define LANG_FR_BE 0x140C // �������ʱ��  
  
// �������  
#define LANG_DE_DE 0x0407 // ����¹���  
#define LANG_DE_CH 0x0807 // �����ʿ��  
#define LANG_DE_AT 0x0C07 // ����µ�����  
#define LANG_DE_LI 0x1407 // �����֧��ʿ�ǣ�  
  
// ����  
#define LANG_JA_JP 0x0411 // ����ձ���  
  
// ����  
#define LANG_KO_KR 0x0412 // ���������  

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
