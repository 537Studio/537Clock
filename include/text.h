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
// '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
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
		cout<<content; //�˺��������ǣ������times��content��
	Sleep(sleep);        //��ȥ�ȴ�sleep��
}

void menu();

void logo();

void about(); 

void color();

void PRESS_ENTER_TO_CONTINUE();

void PRESS_SPACE_TO_CONTINUE();
//���ã�����537Clock1.1�汾�󰴼���������ߣ�ע�ⲻҪ����һ�����������غ� 
//�����û���δ��ʱ̧�𰴼��������ٴδ�����ͣ�˵� 
//�����ڶ��⹦����ʹ��PRESS_ENTER_TO_CONTINUE()����

void cls();

void gotoxy(int x, int y);

void SetConsoleColor(WORD color);

void control(){
	MusicPlayer bgm;
	bgm.play("[5^ 3_] [5^ 1 1]");
	
	tprint("\n\n>>", 15);
	tprint(T.pausepanel, 15);
	tprint("------------",15);
	tprint("------------------", 25, 2);
	tprint("----------------------\n", 80);
	
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
			cout<<TEXT("�Ѵ�537�����ҹٷ���վ��");
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('E')){
			tprint(T.email,20);
			tprint("\n\n");
			bgm.play("[5^ 3^ 1]");
			char address[MAX_PATH]="mailto:";
			strcpy(address,APP_EMAIL);
			ShellExecute(NULL,"open",address,NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ��ʼ����ڣ�");
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('L')){
			tprint(T.license,20);
			tprint("\n\n");
			bgm.play("[5^ 3^ 1]");
			ShellExecute(NULL,"open","https://www.gnu.org/licenses/lgpl-3.0-standalone.html",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ�GNU GPL-3.0Э����վ��");
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('O')){
			tprint(T.opensourcewebsite,20);
			tprint("\n\n");
			bgm.play("[5^ 3^ 1]");
			tprint(TEXT("��ѡ��Ҫ���ʵ�վ��\n"),30);
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout<<TEXT("1");
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(TEXT("\tGitee��"),30);
			tprint(TEXT("https://gitee.com/FTS-537Studio/537Clock\n"),30);
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout<<TEXT("2");
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(TEXT("\tGitHub��"),30);
			tprint(TEXT("https://github.com/537Studio/537Clock\n"),30);
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout<<TEXT("ESC");
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(TEXT("\tȡ��\n"),30);
			tprint(TEXT("\n>537>>���°���>>"),30);
			
			while(true){
				if(KEY('1')){ 
            		cout<<TEXT("Gitee\n\n");
            		bgm.play("[5 3^]");
					ShellExecute(NULL,"open","https://gitee.com/FTS-537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("�Ѵ�Gitee�ϵ�537���ֿ�\n");
					PRESS_ENTER_TO_CONTINUE();
					return;
        		}else if(KEY('2')){ 
            		cout<<TEXT("GitHub\n\n");
            		bgm.play("[5 3^]");
					ShellExecute(NULL,"open","https://github.com/537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("�Ѵ�GitHub�ϵ�537���ֿ�\n");
					PRESS_ENTER_TO_CONTINUE();
					return;
        		}else if(KEY(VK_ESCAPE)){
        			cout<<TEXT("ȡ��\n\n");
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
			cout<<TEXT("�����˳�...");
			system("color F"); 
			exit(0);
		}
		Sleep(15);
	}
} 
void menu(){
	if(lang==1){
		tprint(TEXT("\n>>-��--��--��----ʱ--��--��-----"),20);
		tprint(TEXT("Unixʱ���---"),20);
		tprint(TEXT("-��ʱ--\n"),0);
	}else{
		tprint(TEXT("\n>>YY-MM-D----H-MM-S------"),20);
		tprint(TEXT("Unix Timestamps---"),20);
		tprint(TEXT("-Timer--\n"),0);
	}
}
void PRESS_ENTER_TO_CONTINUE(){
	//�������Ƶĺ�WAIT_PRESS_ENTER_AND_RETURN() 
	if(lang==1){
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("��",20);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		tprint("�س���",30);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("�Լ���...\n",20);
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
	//���ã�����537Clock1.1�汾�󰴼���������ߣ�ע�ⲻҪ����һ�����������غ� 
	//�����û���δ��ʱ̧�𰴼��������ٴδ�����ͣ�˵� 
	//�����ڶ��⹦����ʹ��PRESS_ENTER_TO_CONTINUE()���� 
	
	//�������Ƶĺ�WAIT_PRESS_SPACE_AND_RETURN() 
	
	if(lang==1){
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("��",20);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		tprint("�ո��",30);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		tprint("�Լ���...\n",20);
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
	tprint(TEXT("\n	 "),5);
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
	//��ͣ�� 
	Sleep(50);
	
	map<char, string> color_list{     //�������ɫ��
		{'1', "��ɫ  "}, {'2', "��ɫ  "}, {'3', "ǳ��ɫ"},
		{'4', "��ɫ  "}, {'5', "��ɫ  "}, {'6', "��ɫ  "},
		{'7', "��ɫ  "}, {'8', "��ɫ  "}, {'9', "����ɫ"},
		{'A', "����ɫ"}, {'B', "��ǳ��"}, {'C', "����ɫ"},
		{'D', "����ɫ"}, {'E', "����ɫ"}, {'F', "����ɫ"}
	};
	
	tprint("����537���������ɫ\n\n",50);
	int num = 1;
	for(auto colors : color_list){  //�����������ɫ��
		string content;
		content += colors.first;
		content += '=';
		content += colors.second;
		tprint(content, 50);
		tprint((num%2==0)?"\n":"\t",(num%2==0)?25:0);
		num++;
	}
	tprint("\n\n��537�����������ʾ��ɫ������ΪĬ����ɫ��\n", 50);
	cout<<"\n>537>>���ı���ɫ>�밴�¶�Ӧ��ɫ�İ���>";
	
	while(true){
		for(auto k : color_list){
			if (KEY(k.first)){
				cout<<k.second<<"ɫ\n";
				
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
