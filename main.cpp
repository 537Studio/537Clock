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
			cout<<timeex<<TEXT("��");
		}
    	if((GetAsyncKeyState(' ') & 0x8000)){ // '&'������������0x8000���а�λ��������ж����λ�Ƿ�Ϊ1
            control();
        }else{//δ���¿ո� 
            if(timeex%30==0 && i==0) cout<<TEXT("\t\t\t\t�����ո������ͣ");
        }
    	Sleep(500);//ȥ��������ʾ��Ⱦ�����õ�Լ1���� 
	}
	
    return 0;
}
