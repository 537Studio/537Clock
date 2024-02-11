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
	cout<<"\n>年---月--日---时--分--秒--------";
	Sleep(20);
	cout<<"---------Unix时间戳(1970年1月1日距今)---";
	Sleep(20);
	cout<<"-计时------------";
	Sleep(20);
	cout<<"-----------长按空格键以暂停---\n";
}
void about(){
	Beep(do1,275);
	Beep(do1,250);
	Beep(do2,200);
	Beep(mi2,275);
	Beep(re2,175);
	Beep(do2,300);
	Beep(so1,315);
	cout<<"  /ˉˉˉˉˉˉˉ\\\t=== === ===    /==\\  ||          | =\n";
	Sleep(100);
	cout<<" /  _____  \\\t|     |   /    |    ====         |\n";
	Sleep(100);
	cout<<"|===5 3 7===|\t=== ===  /     \\==\\  ||  |  |  /=| | /==\\\n";
	Sleep(100);
	cout<<" \\  ˉˉˉˉˉ  /\t  |   | /         |  ||  |  | |  | | |  |\n";
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
	cout<<"   537秒表\t";
	Sleep(30);
	cout<<" Version 1.0\t";
	Sleep(30);
	cout<<"537工作室出品\t";
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
	cout<<"设置537秒表文字颜色\n";
	Sleep(50);
	cout<<"1 = 蓝色\t2 = 绿色\n";
	Sleep(50);
	cout<<"3 = 浅绿色\t4 = 红色\n";
	Sleep(50);
	cout<<"5 = 紫色\t6 = 黄色\n";
	Sleep(50);
	cout<<"7 = 白色\t8 = 灰色\n";
	Sleep(50);
	cout<<"9 = 淡蓝色\tA = 淡绿色(默认)\n";
	Sleep(50);
	cout<<"B = 淡浅绿色\tC = 淡红色\n";
	Sleep(50);
	cout<<"D = 淡紫色\tE = 淡黄色\n";
	Sleep(50);
	cout<<"F = 亮白色\n";
	Sleep(50);
	cout<<"当537秒表重启后，显示颜色会重置为默认颜色。\n";
	Sleep(50);
	cout<<"\n>537>>更改背景色>请按下对应颜色的按键>";
	while(true){
		if ((GetAsyncKeyState('1') & 0x8000)){
			cout<<"蓝色\n";
			system("color 1");
			return;
		}else if ((GetAsyncKeyState('2') & 0x8000)){
			cout<<"绿色\n";
			system("color 2");
			return;
		}else if((GetAsyncKeyState('3') & 0x8000)){
			cout<<"浅绿色\n";
			system("color 3");
			return;
		}else if((GetAsyncKeyState('4') & 0x8000)){
			cout<<"红色\n"; 
			system("color 4");
			return;
		}else if((GetAsyncKeyState('5') & 0x8000)){
			cout<<"紫色\n";
			system("color 5");
			return;
		}else if((GetAsyncKeyState('6') & 0x8000)){
			cout<<"黄色\n";
			system("color 6");
			return;
		}else if((GetAsyncKeyState('7') & 0x8000)){
			cout<<"白色\n";
			system("color 7");
			return;
		}else if((GetAsyncKeyState('8') & 0x8000)){
			cout<<"灰色\n";
			system("color 8");
			return;
		}else if((GetAsyncKeyState('9') & 0x8000)){
			cout<<"淡蓝色\n";
			system("color 9");
			return;
		}else if((GetAsyncKeyState('A') & 0x8000)){
			cout<<"淡绿色(默认)\n";
			system("color A");
			return;
		}else if((GetAsyncKeyState('B') & 0x8000)){
			cout<<"淡浅绿色\n";
			system("color B");
			return;
		}else if((GetAsyncKeyState('C') & 0x8000)){
			cout<<"淡红色\n";
			system("color C");
			return;
		}else if((GetAsyncKeyState('D') & 0x8000)){
			cout<<"淡紫色\n";
			system("color D");
			return;
		}else if((GetAsyncKeyState('E') & 0x8000)){
			cout<<"淡黄色\n";
			system("color E");
			return;
		}else if((GetAsyncKeyState('F') & 0x8000)){
			cout<<"亮白色\n";
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
	cout<<endl<<"\n>>暂停面板------------";
	Sleep(25);
	cout<<"------------------------------";
	Sleep(25);
	cout<<"---------------------------------";
	Sleep(25);
	cout<<"-----------------------------------\n"<<endl;
	Sleep(80);
	cout<<"按下按键以启用功能:\n";
	Sleep(40);
	cout<<"t";
	Sleep(40);
	cout<<" 计时器清零\n";
	Sleep(80);
	cout<<"a";
	Sleep(40);
	cout<<" 关于\n";
	Sleep(80);
	cout<<"c";
	Sleep(40);
	cout<<" 调色\n";
	Sleep(80);
	cout<<"w";
	Sleep(40);
	cout<<" 打开537工作室官方网站\n";
	Sleep(80);
	cout<<"h";
	Sleep(40);
	cout<<" 打开在线网站帮助文档\n";
	Sleep(80);
	cout<<"e";
	Sleep(40);
	cout<<" 电子邮件\n";
	Sleep(80);
	cout<<"l";
	Sleep(40);
	cout<<" 用户协议\n";
	Sleep(80);
	cout<<"x";
	Sleep(40);
	cout<<" 继续计时\n";
	Sleep(80);
	cout<<"q";
	Sleep(40);
	cout<<" 退出软件\n";
	Sleep(80);
	cout<<"\n>537>>按下按键>>";
	while(true){
		if ((GetAsyncKeyState('T') & 0x8000)){
			Beep(so1,155);
			Beep(so1,155);
			cout<<"计时器清零\n";
			cout<<"时间已清零,按空格键开始计时...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
    	        	menu();
					timeex=0;
					return;
    	    	}	
    			Sleep(25);
			}
		}else if ((GetAsyncKeyState('A') & 0x8000)){
			cout<<"关于\n";
			Beep(so1,155);
			Beep(so1,155);
			about();
			cout<<"按空格键以继续...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
    	        	menu();
					return;
    	    	}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('C') & 0x8000)){
			cout<<"调色\n\n";
			Beep(so1,155);
			Beep(so1,155);
			color();
			cout<<"按空格键以继续...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
    	        	menu();
					return;
    	    	}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('W') & 0x8000)){
			cout<<"打开537工作室官方网站\n"; 
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.537studio.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<"\n按空格键以继续...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
    	        	menu();
					return;
    	    	}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('H') & 0x8000)){
			cout<<"开在线网站帮助文档\n";
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://sean537.github.io/help",NULL,NULL,SW_SHOWNORMAL);
			cout<<"\n按空格键以继续...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
    	        	menu();
					return;
    	    	}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('E') & 0x8000)){
			cout<<"电子邮件\n";
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","mailto:wushaoquan666@outlook.com",NULL,NULL,SW_SHOWNORMAL);
			cout<<"\n按空格键以继续...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
            		menu();
					return;
        		}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('L') & 0x8000)){
			cout<<"用户协议\n";
			Beep(so1,155);
			Beep(so1,155);
			ShellExecute(NULL,"open","https://www.gnu.org/licenses/lgpl-3.0-standalone.html",NULL,NULL,SW_SHOWNORMAL);
			cout<<"\n按空格键以继续...\n";
			for(;;){
				if((GetAsyncKeyState(' ') & 0x8000)){ // '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
            		menu();
					return;
        		}	
    			Sleep(25);
			}
		}else if((GetAsyncKeyState('X') & 0x8000)){
			cout<<"继续计时\n";
			Beep(so1,155);
			Beep(so1,155);
			menu();
			return; 
		}else if((GetAsyncKeyState('Q') & 0x8000)){
			cout<<"退出软件\n";
			cout<<"正在退出..."; 
			exit(0);
		}
		Sleep(15);
	}
} 
int main(){
	SetConsoleTitle(TEXT("537秒表")); 
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
			strftime(time,sizeof(time),"%Y年%m月%d日 %H时%M分%S秒",localtime(&unixtime));
			timeex++;
    		cout<<endl<<time<<"\t";
    		Sleep(60);
			cout<<"=537=\t";
			Sleep(60);
			cout<<"  ";
			Sleep(30);
			cout<<"1970年";
			Sleep(30);
			cout<<"1月1日";
			Sleep(30);
			cout<<"距今";
			Sleep(30);
			cout<<unixtime<<"秒    ";
			Sleep(60);
			cout<<timeex<<"秒";
		}
    	if((GetAsyncKeyState(' ') & 0x8000)){ // '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
            control();
        }else{//未按下空格 
            if(timeex%30==0 && i==0) cout<<"\t\t\t\t长按空格键以暂停";
        }
    	Sleep(500);//去除加载显示渲染等所用的约1毫秒 
	}
	
    return 0;
}
