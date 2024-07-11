#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#include <winapifamily.h>
#include "include/text.h"
#include "include/about.h"
using namespace std;
int main(){
	SetConsoleTitle(TEXT("537 Clock")); 
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	about();
	menu();
	FTSClock set;
	timeex=set.unixtime-set.starttime;
	while(true){
		strcpy(set.title,set.title_AppName);
		
		size_t strftime(char* strDest,size_t maxsize,const char* format,const struct tm *timeptr);
		set.unixtime=time(NULL);
		char time[256]={0}; 
		strftime(time,sizeof(time),TEXT("%Y��%m��%d�� %Hʱ%M��%S��"),localtime(&set.unixtime));
		timeex++;
    	cout<<"\n"<<time;
    	print_sleep("\t",60);
    	
    	print_sleep("=537=\t",60);
		
		print_sleep("  ",30);
		
		print_sleep(TEXT("1970��"),30);
		
		print_sleep(TEXT("1��1��"),30);
		
		print_sleep(TEXT("���"),30);
		
		cout<<set.unixtime;
		
		print_sleep(TEXT("��    "),60);
		
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<timeex<<TEXT("��");
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		
		char timenum[MAX_PATH]={};
		itoa(timeex,timenum,10);
		strcat(set.title,timenum);
		strcat(set.title,"s");
		SetConsoleTitle(TEXT(set.title));
		
    	for(int i=0;i<20;i++){
    		Sleep(25);
    		if(KEY(' ')){
    			strcat(set.title," Paused");
    			SetConsoleTitle(TEXT(set.title));
    			control();
			}
		}
	}
	
    return 0;
}
