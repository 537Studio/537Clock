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
	SetConsoleTitle(TEXT("537秒表")); 
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
		strftime(time,sizeof(time),TEXT("%Y年%m月%d日 %H时%M分%S秒"),localtime(&set.unixtime));
		timeex++;
    	cout<<"\n"<<time<<"\t";
    	Sleep(60);
		cout<<TEXT("=537=\t");
		Sleep(60);
		cout<<"  ";
		Sleep(30);
		cout<<TEXT("1970年");
		Sleep(30);
		cout<<TEXT("1月1日");
		Sleep(30);
		cout<<TEXT("距今");
		Sleep(30);
		cout<<set.unixtime<<TEXT("秒    ");
		Sleep(60);
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<timeex<<TEXT("秒");
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    	ifcontrol();
    	Sleep(500);//去除加载显示渲染等所用的约1毫秒 
	}
	
    return 0;
}
