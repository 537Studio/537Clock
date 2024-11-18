/*
537 Clock
Version 2.0 Beta

about.cpp

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/
#include <tclass.h>
#include <console.h>
#include "537Clock_AppInfo.h"
void aboutThisApp(){
	tprint(APP_LOGO_L1);
	tprint(APP_DEVELOPER_LOGO_L1,50);
	
	tprint(APP_LOGO_L2);
	tprint(APP_DEVELOPER_LOGO_L2,50);
	
	tprint(APP_LOGO_L3);
	tprint(APP_DEVELOPER_LOGO_L3,50);
	
	tprint(APP_LOGO_L4);
	tprint(APP_DEVELOPER_LOGO_L4,50);
	
	tprint(APP_LOGO_L5);
	tprint(APP_DEVELOPER_LOGO_L5,50);
	
	tprint(APP_NAME_CN,20);
	tprint(L"\t");
	
	tprint(TEXT_VERSION_CN,20);
	tprint(L" ");
	tprint(APP_VERSION);
	tprint(L"\t");
	
	tprint(APP_IDEA_CN,20);
	tprint(L"\t");

	tprint(APP_SUPPORT_CN);
	tprint(L"\n");

	tprint(TEXT_TIP_CN,20);
	tprint(L"\n");
}
