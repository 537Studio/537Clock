#include <iostream>
#include <ctime>
#include <winapifamily.h>
#include <windows.h>
#define ShellExecute __MINGW_NAME_AW(ShellExecute)
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
using namespace std; 
SHSTDAPI_(HINSTANCE) ShellExecuteA (HWND hwnd, LPCSTR lpOperation, LPCSTR lpFile, LPCSTR lpParameters, LPCSTR lpDirectory, INT nShowCmd);
time_t unixtime=time(NULL);
long long starttime=unixtime,timeex=0;
void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void menu(){
	cout<<"\n>��---��--��---ʱ--��--��--------";
	Sleep(20);
	cout<<"---------Unixʱ���(1970��1��1�վ��)---";
	Sleep(20);
	cout<<"-��ʱ------------";
	Sleep(20);
	cout<<"-----------�����ո������ͣ---\n";
}
void about(){
	Beep(do1,275);
	Beep(do1,250);
	Beep(do2,200);
	Beep(mi2,275);
	Beep(re2,175);
	Beep(do2,300);
	Beep(so1,315);
	cout<<"  /��������������\\\t=== === ===    /==\\  ||          | =\n";
	Sleep(100);
	cout<<" /  _____  \\\t|     |   /    |    ====         |\n";
	Sleep(100);
	cout<<"|===5 3 7===|\t=== ===  /     \\==\\  ||  |  |  /=| | /==\\\n";
	Sleep(100);
	cout<<" \\  ����������  /\t  |   | /         |  ||  |  | |  | | |  |\n";
	Sleep(100);
	cout<<"  \\_______/\t=== === =      \\==/  ||  \\==/\\ \\=/\\| \\==/\n";
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
	cout<<"   537���\t";
	Sleep(30);
	cout<<" Version 1.0\t";
	Sleep(30);
	cout<<"537�����ҳ�Ʒ\t";
	Sleep(30);
	cout<<"www.537studio.com\n";
	Sleep(30);
	cout<<"    Copyright(C)537 Studio\t2023-2024.";
	Sleep(30);
	cout<<"  All rights reserved.\n";
}
void color(){
	Beep(so1,155);
	Beep(so1,155);
	Sleep(50);
	cout<<"����537���������ɫ\n";
	Sleep(50);
	cout<<"1 = ��ɫ\t2 = ��ɫ\n";
	Sleep(50);
	cout<<"3 = ǳ��ɫ\t4 = ��ɫ\n";
	Sleep(50);
	cout<<"5 = ��ɫ\t6 = ��ɫ\n";
	Sleep(50);
	cout<<"7 = ��ɫ\t8 = ��ɫ\n";
	Sleep(50);
	cout<<"9 = ����ɫ\tA = ����ɫ(Ĭ��)\n";
	Sleep(50);
	cout<<"B = ��ǳ��ɫ\tC = ����ɫ\n";
	Sleep(50);
	cout<<"D = ����ɫ\tE = ����ɫ\n";
	Sleep(50);
	cout<<"F = ����ɫ\n";
	Sleep(50);
	cout<<"��537�����������ʾ��ɫ������ΪĬ����ɫ��\n";
	Sleep(50);
	cout<<"\n>537>>���ı���ɫ>�밴�¶�Ӧ��ɫ�İ���>";
	while(true){
		if ((GetAsyncKeyState('1') & 0x8000)){
			cout<<"��ɫ\n";
			system("color 1");
			return;
		}else if ((GetAsyncKeyState('2') & 0x8000)){
			cout<<"��ɫ\n";
			system("color 2");
			return;
		}else if((GetAsyncKeyState('3') & 0x8000)){
			cout<<"ǳ��ɫ\n";
			system("color 3");
			return;
		}else if((GetAsyncKeyState('4') & 0x8000)){
			cout<<"��ɫ\n"; 
			system("color 4");
			return;
		}else if((GetAsyncKeyState('5') & 0x8000)){
			cout<<"��ɫ\n";
			system("color 5");
			return;
		}else if((GetAsyncKeyState('6') & 0x8000)){
			cout<<"��ɫ\n";
			system("color 6");
			return;
		}else if((GetAsyncKeyState('7') & 0x8000)){
			cout<<"��ɫ\n";
			system("color 7");
			return;
		}else if((GetAsyncKeyState('8') & 0x8000)){
			cout<<"��ɫ\n";
			system("color 8");
			return;
		}else if((GetAsyncKeyState('9') & 0x8000)){
			cout<<"����ɫ\n";
			system("color 9");
			return;
		}else if((GetAsyncKeyState('A') & 0x8000)){
			cout<<"����ɫ(Ĭ��)\n";
			system("color A");
			return;
		}else if((GetAsyncKeyState('B') & 0x8000)){
			cout<<"��ǳ��ɫ\n";
			system("color B");
			return;
		}else if((GetAsyncKeyState('C') & 0x8000)){
			cout<<"����ɫ\n";
			system("color C");
			return;
		}else if((GetAsyncKeyState('D') & 0x8000)){
			cout<<"����ɫ\n";
			system("color D");
			return;
		}else if((GetAsyncKeyState('E') & 0x8000)){
			cout<<"����ɫ\n";
			system("color E");
			return;
		}else if((GetAsyncKeyState('F') & 0x8000)){
			cout<<"����ɫ\n";
			system("color F");
			return;
		}
		Sleep(10);
	}
}
void control(){
	Beep(si1,150);
	Beep(do1,300);
	Sleep(80);
	cout<<endl<<"\n>>��ͣ���------------";
	Sleep(25);
	cout<<"------------------------------";
	Sleep(25);
	cout<<"---------------------------------";
	Sleep(25);
	cout<<"-----------------------------------\n"<<endl;
	Sleep(80);
	cout<<"���°��������ù���:\n";
	Sleep(40);
	cout<<"t";
	Sleep(40);
	cout<<" ��ʱ������\n";
	Sleep(80);
	cout<<"a";
	Sleep(40);
	cout<<" ����\n";
	Sleep(80);
	cout<<"c";
	Sleep(40);
	cout<<" ��ɫ\n";
	Sleep(80);
	cout<<"w";
	Sleep(40);
	cout<<" ��537�����ҹٷ���վ\n";
	Sleep(80);
	cout<<"h";
	Sleep(40);
	cout<<" ��������վ�����ĵ�\n";
	Sleep(80);
	cout<<"e";
	Sleep(40);
	cout<<" �����ʼ�\n";
	Sleep(80);
	cout<<"l";
	Sleep(40);
	cout<<" �û�Э��\n";
	Sleep(80);
	cout<<"x";
	Sleep(40);
	cout<<" ������ʱ\n";
	Sleep(80);
	cout<<"q";
	Sleep(40);
	cout<<" �˳����\n";
	Sleep(80);
	cout<<"\n>537>>���°���>>";
	while(true){
		if ((GetAsyncKeyState('T') & 0x8000)){
			Beep(so1,155);
			Beep(so1,155);
			cout<<"��ʱ������\n";
			cout<<"ʱ��������,���ո����ʼ��ʱ...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
    	        	menu();
					timeex=0;
					return;
    	    	}	
    			Sleep(25);
			}
		}else if ((GetAsyncKeyState('A') & 0x8000)){
			cout<<"����\n";
			Beep(so1,155);
			Beep(so1,155);
			about();
			cout<<"���ո���Լ���...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
    	        	menu();
					return;
    	    	}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('C') & 0x8000)){
			cout<<"��ɫ\n\n";
			Beep(so1,155);
			Beep(so1,155);
			color();
			cout<<"���ո���Լ���...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
    	        	menu();
					return;
    	    	}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('W') & 0x8000)){
			cout<<"��537�����ҹٷ���վ\n"; 
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.537studio.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<"\n���ո���Լ���...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
    	        	menu();
					return;
    	    	}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('H') & 0x8000)){
			cout<<"��������վ�����ĵ�\n";
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://sean537.github.io/help",NULL,NULL,SW_SHOWNORMAL);
			cout<<"\n���ո���Լ���...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
    	        	menu();
					return;
    	    	}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('E') & 0x8000)){
			cout<<"�����ʼ�\n";
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","mailto:wushaoquan666@outlook.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<"\n���ո���Լ���...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
            		menu();
					return;
        		}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('L') & 0x8000)){
			cout<<"�û�Э��\n";
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.gnu.org/licenses/lgpl-3.0-standalone.html",NULL,NULL,SW_SHOWNORMAL);
			cout<<"\n���ո���Լ���...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
            		menu();
					return;
        		}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('X') & 0x8000)){
			cout<<"������ʱ\n";
			Beep(so1,155);
			Beep(so1,155);
			menu();
			return; 
		}else if((GetAsyncKeyState('Q') & 0x8000)){
			cout<<"�˳����\n";
			cout<<"�����˳�..."; 
			exit(0);
		}
		Sleep(15);
	}
} 
int main(){
	SetConsoleTitle(TEXT("537���")); 
	system("color A");
	about();
	menu();
	timeex=unixtime-starttime;
	for(int i=0;;i++){
		if(i==2) i=0;
		if(i==0){
			size_t strftime(char* strDest,size_t maxsize,const char* format,const struct tm *timeptr);
			time_t unixtime=time(NULL);
			char time[256]={0};
			strftime(time,sizeof(time),"%Y��%m��%d�� %Hʱ%M��%S��",localtime(&unixtime));
			timeex++;
    		cout<<endl<<time<<"\t";
    		Sleep(60);
			cout<<"=537=\t";
			Sleep(60);
			cout<<"  ";
			Sleep(30);
			cout<<"1970��";
			Sleep(30);
			cout<<"1��1��";
			Sleep(30);
			cout<<"���";
			Sleep(30);
			cout<<unixtime<<"��    ";
			Sleep(60);
			cout<<timeex<<"��";
		}
    	if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
            control();
        }else{//δ���¿ո� 
            if(timeex%30==0 && i==0) cout<<"\t\t\t\t�����ո������ͣ";
        }
    	Sleep(500);//ȥ��������ʾ��Ⱦ�����õ�Լ1���� 
	}
	
    return 0;
}
