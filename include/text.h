#include <iostream> 
#include <string>
#include <ctime>
#include <map>
#include <windows.h>
#include <winapifamily.h>
#include <ShellApi.h>
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
// '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
#define KEY(key) (GetAsyncKeyState(key) & 0x8000) 

#define WAIT_PRESS_SPACE_AND_RETURN() cout<<"���ո���Լ���...";	\
						for(;;){   \
							if(KEY(' ')){   \
								menu();     \
								return;   \
							}	\
							Sleep(25);  \
						}
#define WAIT_PRESS_ENTER_AND_RETURN() cout<<"���س����Լ���...";	\
						for(;;){   \
							if(KEY(VK_RETURN)){   \
								menu();     \
								return;   \
							}	\
							Sleep(25);  \
						}
using namespace std;
SHSTDAPI_(HINSTANCE) ShellExecuteA (HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd); 
class FTSClock{
	public:
		size_t strftime(char* strDest,size_t maxsize,const char* format,const struct tm *timeptr);
		time_t unixtime=time(NULL);
		long long starttime=unixtime;
		string copyright=TEXT("Copyright(C)537 Studio.2023-2024.");
		
};
long long timeex=0;

template<typename T>
void print_sleep(T content, int sleep, int times = 1){  
	for(int i = 0; i<times; i++)
		cout << content; //�˺��������ǣ������times��content��
	Sleep(sleep);        //��ȥ�ȴ�sleep��
}

void menu();

void about(); 

void color();

void PRESS_ENTER_TO_CONTINUE();

void PRESS_SPACE_TO_CONTINUE();
//���ã�����537Clock1.1�汾�󰴼���������ߣ�ע�ⲻҪ����һ�����������غ� 
//�����û���δ��ʱ̧�𰴼��������ٴδ�����ͣ�˵� 
//�����ڶ��⹦����ʹ��PRESS_ENTER_TO_CONTINUE()����

void cls();

void gotoxy(int x, int y);

void control(){
	FTSClock set;
	Beep(si1,150);
	Beep(do1,300);
	
	print_sleep("\n\n\n>>��ͣ���------------", 25);
	print_sleep("------------------", 25, 2);
	print_sleep("----------------------\n", 80);
	print_sleep("\n���°��������ù���:\n\n", 40);
	print_sleep("t ��ʱ������\n", 80);
	print_sleep("a ����\n", 80);
	print_sleep("c ��ɫ(������)\n", 80);
	print_sleep("w ��537�����ҹٷ���վ\n", 80);
	print_sleep("h ��������վ�����ĵ�\n", 80);
	print_sleep("e �����ʼ�\n", 80);
	print_sleep("l �û�Э��\n", 80);
	print_sleep("o ��Դ��վ\n", 80);
	print_sleep("s �����Ļ\n", 80);
	print_sleep("x ������ʱ\n", 80);
	print_sleep("q �˳����\n", 80);
	
	cout<<TEXT("\n>537>>���°���>>");
	while(true){
		if (KEY('T')){
			Beep(so1,155);
			Beep(so1,155);
			cout<<TEXT("��ʱ������\n");
			timeex=0;
			cout<<TEXT("ʱ��������,");
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if (KEY('A')){
			cout<<TEXT("����\n");
			Beep(so1,155);
			Beep(so1,155);
			about();
			PRESS_ENTER_TO_CONTINUE();
			return;
		}else if(KEY('C')){
			cout<<TEXT("��ɫ(������)\n\n");
			Beep(so1,155);
			Beep(so1,155);
			color();
			WAIT_PRESS_ENTER_AND_RETURN();
//			PRESS_ENTER_TO_CONTINUE();
//			return;
		}else if(KEY('W')){
			cout<<TEXT("��537�����ҹٷ���վ\n"); 
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.537studio.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ�537�����ҹٷ���վ��");
			WAIT_PRESS_ENTER_AND_RETURN();
//			PRESS_ENTER_TO_CONTINUE();
//			return;
		}else if(KEY('H')){
			cout<<TEXT("��������վ�����ĵ�\n");
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.537studio.com/help",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ�537�����ҹٷ���վ����ҳ�棬");
			WAIT_PRESS_ENTER_AND_RETURN();
//			PRESS_ENTER_TO_CONTINUE();
//			return;
		}else if(KEY('E')){
			cout<<TEXT("�����ʼ�\n");
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","mailto:wushaoquan666@outlook.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ��ʼ����ڣ�");
			WAIT_PRESS_ENTER_AND_RETURN();
//			PRESS_ENTER_TO_CONTINUE();
//			return;
		}else if(KEY('L')){
			cout<<TEXT("�û�Э��\n");
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.gnu.org/licenses/lgpl-3.0-standalone.html",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ�GNU GPL-3.0Э����վ��");
			WAIT_PRESS_ENTER_AND_RETURN();
//			PRESS_ENTER_TO_CONTINUE();
//			return;
		}else if(KEY('O')){
			cout<<TEXT("��Դ��վ\n");
			Beep(so1,155);
			Beep(so1,155);
			print_sleep(TEXT("\n��ѡ��Ҫ���ʵ�վ��\n"),30);
			print_sleep(TEXT("1\tGitee��"),30);
			print_sleep(TEXT("https://gitee.com/FTS-537Studio/537Clock\n"),30);
			print_sleep(TEXT("2\tGitHub��"),30);
			print_sleep(TEXT("https://github.com/537Studio/537Clock\n"),30);
			
			print_sleep(TEXT("ESC\tȡ��\n"),30);
			print_sleep(TEXT("\n>537>>���°���>>"),30);
			
			while(true){
				if(KEY('1')){ 
            		cout<<TEXT("Gitee\n");
					ShellExecute(NULL,"open","https://gitee.com/FTS-537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("�Ѵ�Gitee�ϵ�537���ֿ�\n");
					WAIT_PRESS_ENTER_AND_RETURN();
//					PRESS_ENTER_TO_CONTINUE();
//					return;
        		}else if(KEY('2')){ 
            		cout<<TEXT("GitHub\n");
					ShellExecute(NULL,"open","https://github.com/537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("�Ѵ�GitHub�ϵ�537���ֿ�\n");
					WAIT_PRESS_ENTER_AND_RETURN();
//					PRESS_ENTER_TO_CONTINUE();
//					return;
        		}else if(KEY(VK_ESCAPE)){
        			cout<<TEXT("ȡ��\n\n");
        			menu();
					return;
				}
    			Sleep(25);
			}
		}else if(KEY('S')){
			cout<<TEXT("�����Ļ\n");
			Beep(so1,155);
			Beep(so1,155);
			cls();
			about();
			menu();
			return;
		}else if(KEY('X')){
			cout<<TEXT("������ʱ\n");
			Beep(so1,155);
			Beep(so1,155);
			menu();
			return;
		}else if(KEY('Q')){
			cout<<TEXT("�˳����\n");
			cout<<TEXT("�����˳�...");
			system("color F"); 
			exit(0);
		}
		Sleep(15);
	}
} 
void menu(){
	print_sleep(TEXT("\n>��---��--��---ʱ--��--��--------"),20);
	print_sleep(TEXT("---------Unixʱ���(1970��1��1�վ��)---"),20);
	print_sleep(TEXT("-��ʱ--\n"),0);
}
void PRESS_ENTER_TO_CONTINUE(){
	//�������Ƶĺ�WAIT_PRESS_ENTER_AND_RETURN() 
	cout<<TEXT("���س����Լ���...\n");
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
	cout<<TEXT("���ո���Լ���...\n");
	for(;;){
		if(KEY(' ')){
           	menu();
			return;
       	}	
    	Sleep(25);
	}
}
void about(){
	print_sleep(TEXT("  /-------\\\t=== === ===    /==\\  ||          | =\n"),100);
	print_sleep(TEXT(" /  -----  \\\t|     |   /    |    ====         |\n"),100);
	print_sleep(TEXT("|===5 3 7===|\t=== ===  /     \\==\\  ||  |  |  /=| | /==\\\n"),100);
	print_sleep(TEXT(" \\  -----  /\t  |   | /         |  ||  |  | |  | | |  |\n"),100);
	print_sleep(TEXT("  \\-------/\t=== === =      \\==/  ||  \\==/\\ \\=/\\| \\==/\n"),80);
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
	print_sleep(TEXT("   537 Clock\t"),30);
	print_sleep(TEXT(" Version 1.1"),30);
	print_sleep(TEXT("\t537 Studio\t"),30);
	print_sleep(TEXT("www.537studio.com\n"),30);
	print_sleep(TEXT("    Copyright(C)537 Studio. 2023-2024."),30);
	print_sleep(TEXT(" All rights reserved.\n"),0);
	Beep(do1,275);
	Beep(do1,250);
	Beep(do2,200);
	Beep(mi2,275);
	Beep(re2,175);
	Beep(do2,300);
	Beep(so1,315);
}
void color(){
	Beep(so1,155);
	Beep(so1,155);
	Sleep(50);
	/*
	map<char, string> color_list{     //�������ɫ��
		{'1', "��ɫ  "}, {'2', "��ɫ  "}, {'3', "ǳ��ɫ"},
		{'4', "��ɫ  "}, {'5', "��ɫ  "}, {'6', "��ɫ  "},
		{'7', "��ɫ  "}, {'8', "��ɫ  "}, {'9', "����ɫ"},
		{'A', "����ɫ"}, {'B', "��ǳ��"}, {'C', "����ɫ"},
		{'D', "����ɫ"}, {'E', "����ɫ"}, {'F', "����ɫ"}
	};
	*/
	print_sleep("����537���������ɫ\n\n",50);
	
	
	/*
	int num = 1;
	for(auto colors : color_list){  //�����������ɫ��
		string content;
		content += colors.first;
		content += '=';
		content += colors.second;
		print_sleep(content, 50);
		print_sleep((num%2==0)?"\n":"\t",(num%2==0)?25:0);
		num++;
	}
	*/
	print_sleep("\n\n��537�����������ʾ��ɫ������ΪĬ����ɫ��\n", 50);
	cout<<"\n>537>>���ı���ɫ>�밴�¶�Ӧ��ɫ�İ���>";
	
	while(true){
		if(key("1")){
			SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			return;
		}else if(key("2")){
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			return;
		}else if(key("3")){
			SetConsoleColor(FOREGROUND_GREEN | FORGROUND_BLUE | FOREGROUND_INTENSITY);
			return;
		}else 
	}
	/* 
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
	*/
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
void SetConsoleColor(WORD color) {  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleTextAttribute(hConsole, color);  
}
