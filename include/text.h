#include <iostream> 
#include <string>
#include <ctime>
#include <chrono>  
#include <map>
#include <windows.h>
#include <winapifamily.h>
#include <ShellApi.h>
#include "music.h"
#include "about.h"
#include "language.h"

#define ShellExecute __MINGW_NAME_AW(ShellExecute)
// '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
#define KEY(key) (GetAsyncKeyState(key) & 0x8000) 

#define WAIT_PRESS_SPACE_AND_RETURN() for(;;){   \
							if(KEY(' ')){   \
								menu();     \
								return;   \
							}	\
							Sleep(25);  \
						}
#define WAIT_PRESS_ENTER_AND_RETURN() for(;;){   \
							if(KEY(' ')){   \
								menu();     \
								return;   \
							}	\
							Sleep(25);  \
						}
using namespace std;
SHSTDAPI_(HINSTANCE) ShellExecuteA (HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd); 
long long timer;
long long last_unixtime;
struct Text{
	char AppName[MAX_PATH]={};
	char Version[MAX_PATH]={};
	char BuildVersion[MAX_PATH]={};
	
	char Support[MAX_PATH]={};
	char Copyright[MAX_PATH]={};
	
	char title[MAX_PATH]={};
	char title_AppName[MAX_PATH]={};
	
	char tip[MAX_PATH]={};
	
	char year[MAX_PATH]={};
	char month[MAX_PATH]={};
	char date[MAX_PATH]={};
	char hour[MAX_PATH]={};
	char min[MAX_PATH]={};
	char sec[MAX_PATH]={};
	
	char timer_year[MAX_PATH]={};
	char timer_month[MAX_PATH]={};
	char timer_date[MAX_PATH]={};
	char timer_hour[MAX_PATH]={};
	char timer_min[MAX_PATH]={};
	char timer_sec[MAX_PATH]={};
	
	char pausepanel[MAX_PATH]={};
	char pausepanel_line1[MAX_PATH]={};
	char pausepanel_line2[MAX_PATH]={};
	char pausepanel_line3[MAX_PATH]={};
	char timerclear[MAX_PATH]={};
	char abouttheprogram[MAX_PATH]={};
	char changecolor[MAX_PATH]={};
	char officialwebsite[MAX_PATH]={};
	char email[MAX_PATH]={};
	char license[MAX_PATH]={};
	char opensourcewebsite[MAX_PATH]={};
	char clearscreen[MAX_PATH]={};
	char continuethetimer[MAX_PATH]={}; 
	char exit[MAX_PATH]={};
	
	char paused[MAX_PATH]={};
	char pressthekey[MAX_PATH]={};
	char pressthekeytoenablethefunction[MAX_PATH]={};
	char timeclear[MAX_PATH]={};
	char thewebsiteaddressis[MAX_PATH]={};
	char the_official_website_has_been_opened[MAX_PATH]={};
	char the_email_window_has_been_opened[MAX_PATH]={};
	char the_open_source_license_website_has_been_opened[MAX_PATH]={};
	char exiting[MAX_PATH]={};
}T;
struct TimeInfo{
	int year;
	int month;
	int date;
	int hour;
	int min;
	int sec;
	
	long long unixtime;
}nowtime; 
struct StartTimeInfo{
	int year;
	int month;
	int date;
	int hour;
	int min;
	int sec;
	
	long long unixtime;
}starttime;
template<typename T>
void tprint(T content,int sleep=0,int times=1){  
	for(int i=0;i<times;i++)
		cout<<content; //此函数作用是：在输出times个content后，
	Sleep(sleep);        //再去等待sleep秒
}

void menu(); 
void logo();
void about(); 
void color();
void PRESS_ENTER_TO_CONTINUE();
void PRESS_SPACE_TO_CONTINUE();
//慎用，由于537Clock1.1版本后按键灵敏度提高，注意不要和下一步操作按键重合 
//否则用户若未及时抬起按键，将会再次触发暂停菜单 
//建议在额外功能中使用PRESS_ENTER_TO_CONTINUE()函数
void cls();
void gotoxy(int x, int y);
void SetConsoleColor(WORD color);

void control(){
	MusicPlayer bgm;
	bgm.play("[5^ 3_] [5^ 1 1]");
	
	tprint("\n\n>>", 15);
	tprint(T.pausepanel, 15);
	tprint(T.pausepanel_line1,15);
	tprint(T.pausepanel_line2, 25, 2);
	tprint(T.pausepanel_line3, 80);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	tprint("\n", 10);
	tprint(T.pressthekeytoenablethefunction,40);
	tprint("\n\n",20);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("t ");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.timerclear, 50);
	tprint("\n",30);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("a ");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.abouttheprogram, 50);
	tprint("\n",30);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("w ");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.officialwebsite, 80);
	tprint("\n",30);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("e ");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.email, 80);
	tprint("\n",30);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("l ");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.license, 80);
	tprint("\n",30);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("o ");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.opensourcewebsite, 80);
	tprint("\n",30);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("s ");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.clearscreen, 80);
	tprint("\n",30);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("x ");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.continuethetimer, 80);
	tprint("\n",30);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("q ");
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.exit, 80);
	tprint("\n",30);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	tprint("\n>",10);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint("537",30);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	tprint(">>",10);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(T.pressthekey,10);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	tprint(">>",10);
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	while(true){
		if (KEY('T')){
			bgm.play("[5^ 3^ 1]");
			tprint(T.timerclear,20);
			tprint("\n\n");
			timer=0;
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			tprint(T.timeclear);
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if (KEY('A')){
			bgm.play("[5^ 3^ 1]");
			tprint(T.abouttheprogram,20);
			tprint("\n\n");
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			logo();
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(T.AppName),20;
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint("\n",10);
			tprint(T.Version,20);
			tprint(" ");
			tprint(APP_VERSION,10);
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN);
			tprint("\n",10);
			tprint(T.BuildVersion,20);
			tprint(": ");
			tprint(APP_BUILDVERSION,20);
			
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE);
			tprint("\n");
			tprint(T.Support,20);
			
			SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			tprint("\n"); 
			tprint(T.thewebsiteaddressis,50);
			tprint(APP_WEBSITE,30);
			tprint("\n");
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
			tprint(T.Copyright,60);
			tprint("\n\n");
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			tprint(T.tip,70);
			tprint("\n\n");
			
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('W')){
			tprint(T.officialwebsite,20);
			tprint("\n\n");
			bgm.play("[5^ 3^ 1]");
			ShellExecute(NULL,"open","https://www.537studio.com",NULL,NULL,SW_SHOWNORMAL);
			tprint(T.the_official_website_has_been_opened);
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('E')){
			tprint(T.email,20);
			tprint("\n\n");
			bgm.play("[5^ 3^ 1]");
			char address[MAX_PATH]="mailto:";
			strcpy(address,APP_EMAIL);
			ShellExecute(NULL,"open",address,NULL,NULL,SW_SHOWNORMAL);
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			tprint(T.the_email_window_has_been_opened,30);
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('L')){
			tprint(T.license,20);
			tprint("\n\n");
			bgm.play("[5^ 3^ 1]");
			ShellExecute(NULL,"open","https://www.gnu.org/licenses/lgpl-3.0-standalone.html",NULL,NULL,SW_SHOWNORMAL);
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			tprint(T.the_open_source_license_website_has_been_opened,50);
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('O')){
			tprint(T.opensourcewebsite,20);
			tprint("\n\n");
			bgm.play("[5^ 3^ 1]");
			tprint(TEXT("请选择要访问的站点\n"),30);
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout<<TEXT("1");
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(TEXT("\tGitee："),30);
			tprint(TEXT("https://gitee.com/FTS-537Studio/537Clock\n"),30);
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout<<TEXT("2");
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(TEXT("\tGitHub："),30);
			tprint(TEXT("https://github.com/537Studio/537Clock\n"),30);
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout<<TEXT("ESC");
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(TEXT("\t取消\n"),30);
			tprint(TEXT("\n>537>>按下按键>>"),30);
			
			while(true){
				if(KEY('1')){ 
            		cout<<TEXT("Gitee\n\n");
            		bgm.play("[5 3^]");
					ShellExecute(NULL,"open","https://gitee.com/FTS-537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("已打开Gitee\n");
					PRESS_ENTER_TO_CONTINUE();
					return;
        		}else if(KEY('2')){ 
            		cout<<TEXT("GitHub\n\n");
            		bgm.play("[5 3^]");
					ShellExecute(NULL,"open","https://github.com/537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("已打开GitHub\n");
					PRESS_ENTER_TO_CONTINUE();
					return;
        		}else if(KEY(VK_ESCAPE)){
        			cout<<TEXT("取消\n\n");
        			bgm.play("3_ 3");
        			menu();
					return;
				}
    			Sleep(25);
			}
		}else if(KEY('S')){
			tprint(T.clearscreen,20);
			tprint("\n");
			bgm.play("[5^ 3^ 1]");
			cls();
			about();
			menu();
			return;
		}else if(KEY('X')){
			tprint(T.continuethetimer,20);
			tprint("\n");
			bgm.play("[5 3]");
			menu();
			return;
		}else if(KEY('Q')){
			tprint(T.exit,20);
			tprint("\n");
			tprint(T.exiting,20);
			system("color F"); 
			exit(0);
		}
		Sleep(15);
	}
} 
void menu(){
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	if(lang==1){
		tprint(TEXT("\n>>-年--月--日----时--分--秒-----"),20);
		tprint(TEXT("Unix时间戳-----"),20);
		tprint(TEXT("-计时----------------------------\n"),0);
	}else{
		tprint(TEXT("\n>>YY-MM-D--------H-MM-S----"),20);
		tprint(TEXT("Unix Timestamps---"),20);
		tprint(TEXT("-Timer-----------------------------\n"),0);
	}
}
void setlanguage(int lan){
	if(lan==1){//简体中文 
		strcpy(T.AppName,APP_NAME_CN);
		strcpy(T.Version,TEXT_VERSION_CN);
		strcpy(T.BuildVersion,TEXT_BUILDVERSION_CN);
		
		strcpy(T.Support,APP_SUPPORT_CN);
		strcpy(T.Copyright,APP_COPYRIGHT_CN);
		
		strcpy(T.title,APP_NAME_CN);
		strcpy(T.title_AppName,APP_NAME_CN);
		strcat(T.title_AppName," - ");
		
		strcpy(T.tip,TEXT_TIP_CN);
		
		strcpy(T.year,TEXT_YEAR_CN);
		strcpy(T.month,TEXT_MONTH_CN);
		strcpy(T.date,TEXT_DATE_CN);
		strcpy(T.hour,TEXT_HOUR_CN);
		strcpy(T.min,TEXT_MIN_CN);
		strcpy(T.sec,TEXT_SEC_CN);
		
		strcpy(T.timer_year,TEXT_TIMER_YEAR_CN);
		strcpy(T.timer_month,TEXT_TIMER_MONTH_CN);
		strcpy(T.timer_date,TEXT_TIMER_DATE_CN);
		strcpy(T.timer_hour,TEXT_TIMER_HOUR_CN);
		strcpy(T.timer_min,TEXT_TIMER_MIN_CN);
		strcpy(T.timer_sec,TEXT_TIMER_SEC_CN);
		
		strcpy(T.pausepanel,TEXT_PAUSE_PANEL_CN);
		strcpy(T.pausepanel_line1,TEXT_PAUSE_PANEL_LINE1_CN);
		strcpy(T.pausepanel_line2,TEXT_PAUSE_PANEL_LINE2_CN);
		strcpy(T.pausepanel_line3,TEXT_PAUSE_PANEL_LINE3_CN);
		strcpy(T.timerclear,TEXT_TIMER_CLEAR_CN);
		strcpy(T.abouttheprogram,TEXT_ABOUT_THE_PROGRAM_CN);
		strcpy(T.changecolor,TEXT_CHANGE_COLOR_CN);
		strcpy(T.officialwebsite,TEXT_OFFICIAL_WEBSITE_CN);
		strcpy(T.email,TEXT_EMAIL_CN);
		strcpy(T.license,TEXT_LICENSE_CN);
		strcpy(T.opensourcewebsite,TEXT_OPEN_SOURCE_WEBSITE_CN);
		strcpy(T.clearscreen,TEXT_CLEAR_SCREEN_CN);
		strcpy(T.continuethetimer,TEXT_CONTINUE_THE_TIMER_CN);
		strcpy(T.exit,TEXT_EXIT_CN);
		
		strcpy(T.paused,TEXT_PAUSED_CN);
		strcpy(T.pressthekey,TEXT_PRESS_THE_KEY_CN);
		strcpy(T.pressthekeytoenablethefunction,TEXT_PRESS_THE_KEY_TO_ENABLE_THE_FUNCTION_CN); 
		strcpy(T.timeclear,TEXT_TIME_CLEAR_CN);
		strcpy(T.thewebsiteaddressis,TEXT_THE_WEBSITE_ADDRESS_IS_CN);
		strcpy(T.the_official_website_has_been_opened,TEXT_THE_OFFICIAL_WEBSITE_HAS_BEEN_OPENED_CN);
		strcpy(T.the_email_window_has_been_opened,TEXT_THE_EMAIL_WINDOW_HAS_BEEN_OPENED_CN);
		strcpy(T.the_open_source_license_website_has_been_opened,TEXT_THE_OPEN_SOURCE_LICENSE_WEBSITE_HAS_BEEN_OPENED_CN);
		strcpy(T.exiting,TEXT_EXITING_CN);
	}else{//英文 
		strcpy(T.AppName,APP_NAME_L);
		strcpy(T.Version,TEXT_VERSION);
		strcpy(T.BuildVersion,TEXT_BUILDVERSION);
		
		strcpy(T.Support,APP_SUPPORT);
		strcpy(T.Copyright,APP_COPYRIGHT);
		
		strcpy(T.title,APP_NAME_L);
		strcpy(T.title_AppName,APP_NAME_L);
		strcat(T.title_AppName," - ");
		
		strcpy(T.tip,TEXT_TIP);
		
		strcpy(T.year,TEXT_YEAR);
		strcpy(T.month,TEXT_MONTH);
		strcpy(T.date,TEXT_DATE);
		strcpy(T.hour,TEXT_HOUR);
		strcpy(T.min,TEXT_MIN);
		strcpy(T.sec,TEXT_SEC);
		
		strcpy(T.timer_year,TEXT_TIMER_YEAR_S);
		strcpy(T.timer_month,TEXT_TIMER_MONTH_S);
		strcpy(T.timer_date,TEXT_TIMER_DATE_S);
		strcpy(T.timer_hour,TEXT_TIMER_HOUR_S);
		strcpy(T.timer_min,TEXT_TIMER_MIN_S);
		strcpy(T.timer_sec,TEXT_TIMER_SEC_S);
		
		strcpy(T.pausepanel,TEXT_PAUSE_PANEL);
		strcpy(T.pausepanel_line1,TEXT_PAUSE_PANEL_LINE1);
		strcpy(T.pausepanel_line2,TEXT_PAUSE_PANEL_LINE2);
		strcpy(T.pausepanel_line3,TEXT_PAUSE_PANEL_LINE3);
		strcpy(T.timerclear,TEXT_TIMER_CLEAR);
		strcpy(T.abouttheprogram,TEXT_ABOUT_THE_PROGRAM);
		strcpy(T.changecolor,TEXT_CHANGE_COLOR);
		strcpy(T.officialwebsite,TEXT_OFFICIAL_WEBSITE);
		strcpy(T.email,TEXT_EMAIL);
		strcpy(T.license,TEXT_LICENSE);
		strcpy(T.opensourcewebsite,TEXT_OPEN_SOURCE_WEBSITE);
		strcpy(T.clearscreen,TEXT_CLEAR_SCREEN);
		strcpy(T.continuethetimer,TEXT_CONTINUE_THE_TIMER);
		strcpy(T.exit,TEXT_EXIT);
		
		strcpy(T.paused,TEXT_PAUSED);
		strcpy(T.pressthekey,TEXT_PRESS_THE_KEY);
		strcpy(T.pressthekeytoenablethefunction,TEXT_PRESS_THE_KEY_TO_ENABLE_THE_FUNCTION);
		strcpy(T.timeclear,TEXT_TIME_CLEAR);
		strcpy(T.thewebsiteaddressis,TEXT_THE_WEBSITE_ADDRESS_IS);
		strcpy(T.the_official_website_has_been_opened,TEXT_THE_OFFICIAL_WEBSITE_HAS_BEEN_OPENED);
		strcpy(T.the_email_window_has_been_opened,TEXT_THE_EMAIL_WINDOW_HAS_BEEN_OPENED);
		strcpy(T.the_open_source_license_website_has_been_opened,TEXT_THE_OPEN_SOURCE_LICENSE_WEBSITE_HAS_BEEN_OPENED);
		strcpy(T.exiting,TEXT_EXITING);
	}
}
void PRESS_ENTER_TO_CONTINUE(){
	//功能相似的宏WAIT_PRESS_ENTER_AND_RETURN() 
	if(lang==1){
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("按",20);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		tprint("回车键",30);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("以继续...\n",20);
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}else{
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("Press",20);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		tprint(" Enter",30);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint(" to continue...\n",20);
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	for(;;){
		if(KEY(VK_RETURN)){
           	menu();
			return;
       	}	
    	Sleep(25);
	}
}
void PRESS_SPACE_TO_CONTINUE(){
	//慎用，由于537Clock1.1版本后按键灵敏度提高，注意不要和下一步操作按键重合 
	//否则用户若未及时抬起按键，将会再次触发暂停菜单 
	//建议在额外功能中使用PRESS_ENTER_TO_CONTINUE()函数 
	
	//功能相似的宏WAIT_PRESS_SPACE_AND_RETURN() 
	
	if(lang==1){
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("按",20);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		tprint("空格键",30);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("以继续...\n",20);
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}else{
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("Press",20);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		tprint(" Space",30);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint(" to continue...\n",20);
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	}
	for(;;){
		if(KEY(' ')){
           	menu();
			return;
       	}	
    	Sleep(25);
	}
}
void logo(){
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	tprint(TEXT("# #     # #\t=== === ===    /==\\  ||          | =\n"),100);
	tprint(TEXT("# # # # # #\t|     |   /    |    ====         |\n"),100);
	tprint(TEXT("  # ^-^ #  \t=== ===  /     \\==\\  ||  |  |  /=| | /==\\\n"),100);
	tprint(TEXT("# # # # # #\t  |   | /         |  ||  |  | |  | | |  |\n"),100);
	tprint(TEXT("# #     # #\t=== === =      \\==/  ||  \\==/\\ \\=/\\| \\==/\n"),80);
	/*
	# #     # # 
	# # # # # # 
	  # ^-^ #  
	# # # # # # 
	# #     # #
	
	  /-------\
	 /  -----  \
	|===5 3 7===|
	 \  -----  /
	  \-------/
	
	=== === ===    /==\  ||          | =
	|     |   /    |    ====         |
	=== ===  /     \==\  ||  |  |  /=| | /==\
	  |   | /         |  ||  |  | |  | | |  |
	=== === =      \==/  ||  \==/\ \=/\| \==/
	*/
}
void about(){
	logo();
	tprint(TEXT("  "),15);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(TEXT(T.AppName),15);
	tprint(TEXT("\t"),5);
	tprint(T.Version,10);
	tprint(" ");
	tprint(TEXT(APP_VERSION),15);
	tprint(TEXT("\t"),15);
	
	SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
	tprint(TEXT(T.Support),15);
	/*
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(TEXT("\n  "),5);
	tprint(TEXT(T.Copyright),30);
	*/
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(TEXT("\n"),5);
	tprint(TEXT(T.tip),50);
	
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint("\n"); 
	//MusicPlayer bgm;
	//bgm.play("5,_ [1, 1_] 2_ 3 2_ 1_ [5, 1, 1-]");
	/*
	Beep(do1,275);
	Beep(do1,250);
	Beep(do2,200);
	Beep(mi2,275);
	Beep(re2,175);
	Beep(do2,300);
	Beep(so1,315);
	*/
}
void color(){
	//已停用 
	Sleep(50);
	
	map<char, string> color_list{     //这个是颜色表
		{'1', "蓝色  "}, {'2', "绿色  "}, {'3', "浅绿色"},
		{'4', "红色  "}, {'5', "紫色  "}, {'6', "黄色  "},
		{'7', "白色  "}, {'8', "灰色  "}, {'9', "淡蓝色"},
		{'A', "淡绿色"}, {'B', "淡浅绿"}, {'C', "淡红色"},
		{'D', "淡紫色"}, {'E', "淡黄色"}, {'F', "亮白色"}
	};
	
	tprint("设置537秒表文字颜色\n\n",50);
	int num = 1;
	for(auto colors : color_list){  //遍历并输出颜色表
		string content;
		content += colors.first;
		content += '=';
		content += colors.second;
		tprint(content, 50);
		tprint((num%2==0)?"\n":"\t",(num%2==0)?25:0);
		num++;
	}
	tprint("\n\n当537秒表重启后，显示颜色会重置为默认颜色。\n", 50);
	cout<<"\n>537>>更改背景色>请按下对应颜色的按键>";
	
	while(true){
		for(auto k : color_list){
			if (KEY(k.first)){
				cout<<k.second<<"色\n";
				
				string comm = "color ";
				comm += k.first;
				
				system(comm.c_str());
				return;
			}
		} 
		Sleep(10);
	}
}
void cls(){
	for(int i=0;i<50;i++){
		cout<<"\n";
		Sleep(40);
	}
	system("cls");
}
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetConsoleColor(WORD color){  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleTextAttribute(hConsole, color);  
}
