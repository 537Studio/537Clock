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
	system("color A");
	about();
	menu();
	FTSClock set;
	timeex=set.unixtime-set.starttime;
	for(int i=0;;i++){
		if(i==2) i=0;
		if(i==0){
			size_t strftime(char* strDest,size_t maxsize,const char* format,const struct tm *timeptr);
			//time_t unixtime=time(NULL);
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
			cout<<timeex<<TEXT("秒");
		}
    	if((GetAsyncKeyState(' ') & 0x8000)){ // '&'运算符将结果与0x8000进行按位与操作，判断最低位是否为1
            control();
        }else{//未按下空格 
            if(timeex%30==0 && i==0) cout<<TEXT("\t\t\t\t长按空格键以暂停");
        }
    	Sleep(500);//去除加载显示渲染等所用的约1毫秒 
	}
	
    return 0;
}
