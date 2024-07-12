#include "include/text.h"
#include "include/about.h"
int main(int argc, char* argv[]){
	SetConsoleTitle(TEXT(APP_NAME_L)); 
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	FTSClock set;
	
	if(argc!=1){//���������� 
		if(string(argv[1])=="--ver" || string(argv[1])=="--version" || string(argv[1])=="-v"){ 
    		print_sleep("537 Clock\t",40);
    		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			print_sleep("Version ",20);
			print_sleep(APP_VERSION,20);
			SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			print_sleep("\tBuild version ",20);
			print_sleep(APP_BUILDVERSION,20);
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			print_sleep("\n",20);
			return 0;
    	}
	}
	
	about();
	menu();
	timeex=set.unixtime-set.starttime;
	while(true){
		strcpy(set.title,set.title_AppName);
		/*
		// ��ȡ��ǰʱ���  
    	auto now = std::chrono::system_clock::now();  
    	// ��ʱ���ת��Ϊtime_t���ͣ�time_t��C++�����ڱ�ʾʱ������ͣ���ͨ������1970��1��1������������  
    	std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    	// ��time_tת��Ϊlong long  
    	long long unixtime = static_cast<long long>(now_c);  
    	// ��time_tת��Ϊ����ʱ��tm�ṹ�壬�Ա��ȡСʱ�����Ӻ���  
    	std::tm* local_time = std::localtime(&now_c);  
    	// ��ȡСʱ�����Ӻ���  
    	int h = local_time->tm_hour;  
    	int m = local_time->tm_min;  
    	int s = local_time->tm_sec;  
		*/
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
    		Sleep(30);
    		if(KEY(' ')){
    			strcat(set.title," Paused");
    			SetConsoleTitle(TEXT(set.title));
    			control();
			}
		}
	}
	
    return 0;
}
