#include <iostream>
#include <string>
#include <ctime>
#include <time.h>
#include <windows.h>
#include <winapifamily.h>
#include "include/text.h"
#include "include/about.h"
using namespace std;
int main(){
	SetConsoleTitle(TEXT("537���")); 
	system("color A");
	about();
	menu();
	FTSClock set;
	timeex=set.unixtime-set.starttime;
	while(true){
		size_t strftime(char* strDest,size_t maxsize,const char* format,const struct tm *timeptr);
		set.unixtime=time(NULL);
		cout<<"\n";
		char time[256]={0}; 
		strftime(time,sizeof(time),TEXT("%Y��%m��%d�� %Hʱ%M��%S��"),localtime(&set.unixtime));
		timeex++;
    	cout<<"\n"<<time<<"\t";
    	Sleep(60);
		cout<<TEXT("=537=\t");
		Sleep(60);
		cout<<"  ";
		Sleep(30);
		cout<<TEXT("1970��");
		Sleep(30);
		cout<<TEXT("1��1��");
		Sleep(30);
		cout<<TEXT("���");
		Sleep(30);
		cout<<set.unixtime<<TEXT("��    ");
		Sleep(60);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<timeex<<TEXT("��");
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    	ifcontrol();
    	Sleep(500);//ȥ��������ʾ��Ⱦ�����õ�Լ1���� 
	}
	
    return 0;
}
