#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>
#include <winapifamily.h>
#include "include/text.h"
#include "include/about.h"
using namespace std;
int main(){
	SetConsoleTitle(TEXT("537���")); 
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
		strftime(time,sizeof(time),TEXT("%Y��%m��%d�� %Hʱ%M��%S��"),localtime(&set.unixtime));
		timeex++;
    	cout<<"\n"<<time;
    	print_sleep("\t",60);
    	
    	print_sleep("=537=\t",60);
		//if(KEY(' ')) control();
		
		print_sleep("  ",30);
		//if(KEY(' ')) control();
		
		print_sleep(TEXT("1970��"),30);
		//if(KEY(' ')) control();
		
		print_sleep(TEXT("1��1��"),30);
		//if(KEY(' ')) control();
		
		print_sleep(TEXT("���"),30);
		//if(KEY(' ')) control();
		
		cout<<set.unixtime;
		
		print_sleep(TEXT("��    "),60);
		//if(KEY(' ')) control();
		
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<timeex<<TEXT("��");
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		
    	for(int i=0;i<20;i++){
    		Sleep(25);
    		if(KEY(' ')) control();
		}
	}
	
    return 0;
}
