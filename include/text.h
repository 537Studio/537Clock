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
#define do1 261.626
#define re1 293.665
#define mi1 329.629
#define fa1 349.228
#define so1 391.995
#define la1 440.000
#define si1 493.883
#define do2 523.251
#define re2 587.330
#define mi2 659.255
#define fa2 698.456
#define so2 783.991
#define la2 880.000
#define si2 987.767
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
char title[MAX_PATH]={};
const char title_AppName[MAX_PATH]="537 Clock - ";
long long timer;
long long last_unixtime;
struct TimeInfo{
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	
	long long unixtime;
}nowtime; 
struct StartTimeInfo{
	int year;
	int month;
	int day;
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
	
	tprint("\n\n>>暂停面板------------", 25);
	tprint("------------------", 25, 2);
	tprint("----------------------\n", 80);
	tprint("\n按下按键以启用功能:\n\n", 40);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("t");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(" 计时清零\n", 80);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("a");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(" 关于程序\n", 80);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("w");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(" 官方网站\n", 80);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("e");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(" 电子邮件\n", 80);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("l");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(" 用户协议\n", 80);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("o");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(" 开源网站\n", 80);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("s");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(" 清空屏幕\n", 80);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("x");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(" 继续计时\n", 80);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<TEXT("q");
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(" 退出软件\n", 80);
	
	cout<<TEXT("\n>537>>按下按键>>");
	while(true){
		if (KEY('T')){
			bgm.play("[5^ 3^ 1]");
			cout<<TEXT("计时器清零\n");
			timer=0;
			cout<<TEXT("时间已清零,");
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if (KEY('A')){
			bgm.play("[5^ 3^ 1]");
			cout<<TEXT("关于\n");
			about();
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('W')){
			cout<<TEXT("打开537工作室官方网站\n"); 
			bgm.play("[5^ 3^ 1]");
			ShellExecute(NULL,"open","https://www.537studio.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("已打开537工作室官方网站，");
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('E')){
			cout<<TEXT("电子邮件\n");
			bgm.play("[5^ 3^ 1]");
			ShellExecute(NULL,"open","mailto:wushaoquan666@outlook.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("已打开邮件窗口，");
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('L')){
			cout<<TEXT("用户协议\n");
			bgm.play("[5^ 3^ 1]");
			ShellExecute(NULL,"open","https://www.gnu.org/licenses/lgpl-3.0-standalone.html",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("已打开GNU GPL-3.0协议网站，");
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('O')){
			cout<<TEXT("开源网站\n");
			bgm.play("[5^ 3^ 1]");
			tprint(TEXT("\n请选择要访问的站点\n"),30);
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
            		cout<<TEXT("Gitee\n");
            		bgm.play("[5 3^]");
					ShellExecute(NULL,"open","https://gitee.com/FTS-537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("已打开Gitee上的537秒表仓库\n");
					PRESS_ENTER_TO_CONTINUE();
					return;
        		}else if(KEY('2')){ 
            		cout<<TEXT("GitHub\n");
            		bgm.play("[5 3^]");
					ShellExecute(NULL,"open","https://github.com/537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("已打开GitHub上的537秒表仓库\n");
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
			cout<<TEXT("清空屏幕\n");
			bgm.play("[5^ 3^ 1]");
			cls();
			about();
			menu();
			return;
		}else if(KEY('X')){
			cout<<TEXT("继续计时\n");
			bgm.play("[5 3]");
			menu();
			return;
		}else if(KEY('Q')){
			cout<<TEXT("退出软件\n");
			cout<<TEXT("正在退出...");
			system("color F"); 
			exit(0);
		}
		Sleep(15);
	}
} 
void menu(){
	tprint(TEXT("\n>年---月--日---时--分--秒--------"),20);
	tprint(TEXT("---------Unix时间戳(1970年1月1日距今)---"),20);
	tprint(TEXT("-计时--\n"),0);
}
void PRESS_ENTER_TO_CONTINUE(){
	//功能相似的宏WAIT_PRESS_ENTER_AND_RETURN() 
	cout<<TEXT("按回车键以继续...\n");
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
	cout<<TEXT("按空格键以继续...\n");
	for(;;){
		if(KEY(' ')){
           	menu();
			return;
       	}	
    	Sleep(25);
	}
}
void about(){
	tprint(TEXT("  /-------\\\t=== === ===    /==\\  ||          | =\n"),100);
	tprint(TEXT(" /  -----  \\\t|     |   /    |    ====         |\n"),100);
	tprint(TEXT("|===5 3 7===|\t=== ===  /     \\==\\  ||  |  |  /=| | /==\\\n"),100);
	tprint(TEXT(" \\  -----  /\t  |   | /         |  ||  |  | |  | | |  |\n"),100);
	tprint(TEXT("  \\-------/\t=== === =      \\==/  ||  \\==/\\ \\=/\\| \\==/\n"),80);
	/*
	/==\  ||          | =
	|    ====         |
	\==\  ||  |  |  /=| | /==\
	   |  ||  |  | |  | | |  |
	\==/  ||  \==/\ \=/\| \==/
	
	/==\  ||          | =
	|    ====         |
	\\==\\  ||  |  |  /=| | /==\\
	   |  ||  |  | |  | | |  |
	\\==/  ||  \\==/\\ \\=/\\| \\==/
	*/
	tprint(TEXT("  "),15);
	
	SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	tprint(TEXT(APP_NAME_L),15);
	tprint(TEXT("\tVersion "),15);
	tprint(TEXT(APP_VERSION),15);
	tprint(TEXT("\t"),15);
	
	SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
	tprint(TEXT(APP_DEVELOPER),15);
	tprint(TEXT("\t"),0);
	tprint(TEXT(APP_WEBSITE),25);
	
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	tprint(TEXT("\n  "),5);
	tprint(TEXT(APP_COPYRIGHT),30);
	
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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
	Beep(so1,155);
	Beep(so1,155);
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
