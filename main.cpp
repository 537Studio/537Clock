#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <winapifamily.h>
#include "include/text.h"
#include "include/about.h"
using namespace std;
int main(){
	SetConsoleTitle(TEXT("537秒表")); 
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	about();
	menu();
	FTSClock set;
	timeex=set.unixtime-set.starttime;
	while(true){
		size_t strftime(char* strDest,size_t maxsize,const char* format,const struct tm *timeptr);
		set.unixtime=time(NULL);
		//cout<<"\n";
		//if(KEY(' ')) control();
		char time[256]={0}; 
		strftime(time,sizeof(time),TEXT("%Y年%m月%d日 %H时%M分%S秒"),localtime(&set.unixtime));
		timeex++;
    	cout<<"\n"<<time;
    	print_sleep("\t",60);
    	
    	print_sleep("=537=\t",60);
		//if(KEY(' ')) control();
		
		print_sleep("  ",30);
		//if(KEY(' ')) control();
		
		print_sleep(TEXT("1970年"),30);
		//if(KEY(' ')) control();
		
		print_sleep(TEXT("1月1日"),30);
		//if(KEY(' ')) control();
		
		print_sleep(TEXT("距今"),30);
		//if(KEY(' ')) control();
		
		cout<<set.unixtime;
		
		print_sleep(TEXT("秒    "),60);
		//if(KEY(' ')) control();
		
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<timeex<<TEXT("秒");
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		
    	for(int i=0;i<20;i++){
    		Sleep(25);
    		if(KEY(' ')) control();
		}
	}
	
    return 0;
}
