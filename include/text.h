#include <iostream> 
#include <string>
#include <ctime>
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

void menu();
void about(); 
void color();
void PRESS_SPACE_TO_CONTINUE();
void cls();
void gotoxy(int x, int y);
void ifcontrol();
void control(){
	FTSClock set;
	Beep(si1,150);
	Beep(do1,300);
	Sleep(80);
	cout<<TEXT("\n\n>>��ͣ���------------");
	Sleep(25);
	cout<<TEXT("------------------------------");
	Sleep(25);
	cout<<TEXT("---------------------------------");
	Sleep(25);
	cout<<TEXT("-----------------------------------\n\n");
	Sleep(80);
	cout<<TEXT("���°��������ù���:\n");
	Sleep(40);
	cout<<endl<<"t";
	Sleep(40);
	cout<<TEXT(" ��ʱ������\n");
	Sleep(80);
	cout<<"a";
	Sleep(40);
	cout<<TEXT(" ����\n");
	Sleep(80);
	cout<<"c";
	Sleep(40);
	cout<<TEXT(" ��ɫ\n");
	Sleep(80);
	cout<<"w";
	Sleep(40);
	cout<<TEXT(" ��537�����ҹٷ���վ\n");
	Sleep(80);
	cout<<"h";
	Sleep(40);
	cout<<TEXT(" ��������վ�����ĵ�\n");
	Sleep(80);
	cout<<"e";
	Sleep(40);
	cout<<TEXT(" �����ʼ�\n");
	Sleep(80);
	cout<<"l";
	Sleep(40);
	cout<<TEXT(" �û�Э��\n");
	Sleep(80);
	cout<<"o";
	Sleep(40);
	cout<<TEXT(" ��Դ��վ\n");
	Sleep(80);
	cout<<"s";
	Sleep(40);
	cout<<TEXT(" �����Ļ\n");
	Sleep(80);
	cout<<"x";
	Sleep(40);
	cout<<TEXT(" ������ʱ\n");
	Sleep(80);
	cout<<"q";
	Sleep(40);
	cout<<TEXT(" �˳����\n");
	Sleep(80);
	cout<<TEXT("\n>537>>���°���>>");
	while(true){
		if ((GetAsyncKeyState('T') & 0x8000)){
			Beep(so1,155);
			Beep(so1,155);
			cout<<TEXT("��ʱ������\n");
			timeex=0;
			cout<<TEXT("ʱ��������,");
			PRESS_SPACE_TO_CONTINUE();
			return;
		}else if ((GetAsyncKeyState('A') & 0x8000)){
			cout<<TEXT("����\n");
			Beep(so1,155);
			Beep(so1,155);
			about();
			PRESS_SPACE_TO_CONTINUE();
			return;
		}else if((GetAsyncKeyState('C') & 0x8000)){
			cout<<TEXT("��ɫ\n\n");
			Beep(so1,155);
			Beep(so1,155);
			color();
			PRESS_SPACE_TO_CONTINUE();
			return;
		}else if((GetAsyncKeyState('W') & 0x8000)){
			cout<<TEXT("��537�����ҹٷ���վ\n"); 
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.537studio.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ�537�����ҹٷ���վ��");
			PRESS_SPACE_TO_CONTINUE();
			return;
		}else if((GetAsyncKeyState('H') & 0x8000)){
			cout<<TEXT("��������վ�����ĵ�\n");
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.537studio.com/help",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ�537�����ҹٷ���վ����ҳ�棬");
			PRESS_SPACE_TO_CONTINUE();
			return;
		}else if((GetAsyncKeyState('E') & 0x8000)){
			cout<<TEXT("�����ʼ�\n");
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","mailto:wushaoquan666@outlook.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ��ʼ����ڣ�");
			PRESS_SPACE_TO_CONTINUE();
			return;
		}else if((GetAsyncKeyState('L') & 0x8000)){
			cout<<TEXT("�û�Э��\n");
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.gnu.org/licenses/lgpl-3.0-standalone.html",NULL,NULL,SW_SHOWNORMAL);
			cout<<TEXT("�Ѵ�GNU GPL-3.0Э����վ��");
			PRESS_SPACE_TO_CONTINUE();
			return;
		}else if((GetAsyncKeyState('O') & 0x8000)){
			cout<<TEXT("��Դ��վ\n");
			Beep(so1,155);
			Beep(so1,155);
			cout<<TEXT("\n>537>>��ѡ��Ҫ���ʵ�վ��\n"); 
			Sleep(30);
			cout<<TEXT("1\tGitee��");
			Sleep(30);
			cout<<TEXT("https://gitee.com/FTS-537Studio/537Clock\n");
			Sleep(30);
			cout<<TEXT("2\tGitHub��");
			Sleep(30);
			cout<<TEXT("https://github.com/537Studio/537Clock\n");
			Sleep(30);
			cout<<TEXT("ESC\tȡ��\n\n>537>>���°���>>");
			while(true){
				if((GetAsyncKeyState('1') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
            		cout<<TEXT("Gitee\n");
					ShellExecute(NULL,"open","https://gitee.com/FTS-537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("-�Ѵ�Gitee�ϵ�537���ֿ�\n");
					PRESS_SPACE_TO_CONTINUE();
					return;
        		}else if((GetAsyncKeyState('2') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
            		cout<<TEXT("GitHub\n");
					ShellExecute(NULL,"open","https://github.com/537Studio/537Clock",NULL,NULL,SW_SHOWNORMAL);
					cout<<TEXT("-�Ѵ�GitHub�ϵ�537���ֿ�\n");
					PRESS_SPACE_TO_CONTINUE();
					return;
        		}else if((GetAsyncKeyState(VK_ESCAPE) & 0x8000)){
        			cout<<TEXT("ȡ��\n\n");
        			menu();
					return;
				}
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('S') & 0x8000)){
			cout<<TEXT("�����Ļ\n");
			Beep(so1,155);
			Beep(so1,155);
			cls();
			about();
			menu();
			return;
		}else if((GetAsyncKeyState('X') & 0x8000)){
			cout<<TEXT("������ʱ\n");
			Beep(so1,155);
			Beep(so1,155);
			menu();
			return;
		}else if((GetAsyncKeyState('Q') & 0x8000)){
			cout<<TEXT("�˳����\n");
			cout<<TEXT("�����˳�...");
			system("color 7"); 
			exit(0);
		}
		Sleep(15);
	}
} 
void menu(){
	cout<<TEXT("\n>��---��--��---ʱ--��--��--------");
	Sleep(20);
	cout<<TEXT("---------Unixʱ���(1970��1��1�վ��)---");
	Sleep(20);
	cout<<TEXT("-��ʱ--");
}
void PRESS_SPACE_TO_CONTINUE(){
	cout<<TEXT("���ո���Լ���...\n");
	for(;;){
		if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
           	menu();
			return;
       	}	
    	Sleep(25);
	}
}
void about(){
	Beep(do1,275);
	Beep(do1,250);
	Beep(do2,200);
	Beep(mi2,275);
	Beep(re2,175);
	Beep(do2,300);
	Beep(so1,315);
	cout<<TEXT("  /-------\\\t=== === ===    /==\\  ||          | =\n");
	Sleep(100);
	cout<<TEXT(" /  -----  \\\t|     |   /    |    ====         |\n");
	Sleep(100);
	cout<<TEXT("|===5 3 7===|\t=== ===  /     \\==\\  ||  |  |  /=| | /==\\\n");
	Sleep(100);
	cout<<TEXT(" \\  -----  /\t  |   | /         |  ||  |  | |  | | |  |\n");
	Sleep(100);
	cout<<TEXT("  \\-------/\t=== === =      \\==/  ||  \\==/\\ \\=/\\| \\==/\n");
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
	Sleep(80);
	cout<<TEXT("   537 Clock\t");
	Sleep(30);
	cout<<TEXT(" Version 1.1");
	Sleep(30);
	cout<<TEXT("\t537 Studio\t");
	Sleep(30);
	cout<<TEXT("www.537studio.com\n");
	Sleep(30);
	cout<<TEXT("    Copyright(C)537 Studio. 2023-2024.");
	Sleep(30);
	cout<<TEXT(" All rights reserved.\n";)
}
void color(){
	Beep(so1,155);
	Beep(so1,155);
	Sleep(50);
	cout<<TEXT("����537���������ɫ\n");
	Sleep(50);
	cout<<TEXT("1 = ��ɫ\t2 = ��ɫ\n");
	Sleep(50);
	cout<<TEXT("3 = ǳ��ɫ\t4 = ��ɫ\n");
	Sleep(50);
	cout<<TEXT("5 = ��ɫ\t6 = ��ɫ\n");
	Sleep(50);
	cout<<TEXT("7 = ��ɫ\t8 = ��ɫ\n");
	Sleep(50);
	cout<<TEXT("9 = ����ɫ\tA = ����ɫ(Ĭ��)\n");
	Sleep(50);
	cout<<TEXT("B = ��ǳ��ɫ\tC = ����ɫ\n");
	Sleep(50);
	cout<<TEXT("D = ����ɫ\tE = ����ɫ\n");
	Sleep(50);
	cout<<TEXT("F = ����ɫ\n");
	Sleep(50);
	cout<<TEXT("��537�����������ʾ��ɫ������ΪĬ����ɫ��\n");
	Sleep(50);
	cout<<TEXT("\n>537>>���ı���ɫ>�밴�¶�Ӧ��ɫ�İ���>");
	while(true){
		if ((GetAsyncKeyState('1') & 0x8000)){
			cout<<TEXT("��ɫ\n");
			system("color 1");
			return;
		}else if ((GetAsyncKeyState('2') & 0x8000)){
			cout<<TEXT("��ɫ\n");
			system("color 2");
			return;
		}else if((GetAsyncKeyState('3') & 0x8000)){
			cout<<TEXT("ǳ��ɫ\n");
			system("color 3");
			return;
		}else if((GetAsyncKeyState('4') & 0x8000)){
			cout<<TEXT("��ɫ\n"); 
			system("color 4");
			return;
		}else if((GetAsyncKeyState('5') & 0x8000)){
			cout<<TEXT("��ɫ\n");
			system("color 5");
			return;
		}else if((GetAsyncKeyState('6') & 0x8000)){
			cout<<TEXT("��ɫ\n");
			system("color 6");
			return;
		}else if((GetAsyncKeyState('7') & 0x8000)){
			cout<<TEXT("��ɫ\n");
			system("color 7");
			return;
		}else if((GetAsyncKeyState('8') & 0x8000)){
			cout<<TEXT("��ɫ\n");
			system("color 8");
			return;
		}else if((GetAsyncKeyState('9') & 0x8000)){
			cout<<TEXT("����ɫ\n");
			system("color 9");
			return;
		}else if((GetAsyncKeyState('A') & 0x8000)){
			cout<<TEXT("����ɫ\n");
			system("color A");
			return;
		}else if((GetAsyncKeyState('B') & 0x8000)){
			cout<<TEXT("��ǳ��ɫ\n");
			system("color B");
			return;
		}else if((GetAsyncKeyState('C') & 0x8000)){
			cout<<TEXT("����ɫ\n");
			system("color C");
			return;
		}else if((GetAsyncKeyState('D') & 0x8000)){
			cout<<TEXT("����ɫ\n");
			system("color D");
			return;
		}else if((GetAsyncKeyState('E') & 0x8000)){
			cout<<TEXT("����ɫ\n");
			system("color E");
			return;
		}else if((GetAsyncKeyState('F') & 0x8000)){
			cout<<TEXT("����ɫ\n");
			system("color F");
			return;
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
void SetConsoleColor(WORD color) {  
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  
	SetConsoleTextAttribute(hConsole, color);  
}
void ifcontrol(){
	if((GetAsyncKeyState(' ') & 0x8000)) control();
}  
