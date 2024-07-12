#include "include/text.h"
#include "include/about.h"
int main(int argc, char* argv[]){
	SetConsoleTitle(TEXT(APP_NAME_L)); 
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	if(argc!=1){//���������� 
		if(string(argv[1])=="--ver" || string(argv[1])=="--version" || string(argv[1])=="-v"){ 
    		tprint("537 Clock\t",40);
    		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint("Version ",20);
			tprint(APP_VERSION,20);
			SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			tprint("\tBuild version ",20);
			tprint(APP_BUILDVERSION,20);
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			tprint("\n",20);
			return 0;
    	}
	}
	
	about();
	menu();
	
    auto now=std::chrono::system_clock::now();  
    std::time_t now_c=std::chrono::system_clock::to_time_t(now);
    starttime.unixtime=static_cast<long long>(now_c);  
    std::tm* local_time = std::localtime(&now_c);  
    starttime.year=local_time->tm_year+1900; 
    starttime.month=local_time->tm_mon+1;
    starttime.day=local_time->tm_mday; 
	starttime.hour=local_time->tm_hour;  
    starttime.min=local_time->tm_min;  
    starttime.sec=local_time->tm_sec;  
	
	while(true){
		strcpy(title,title_AppName);
		
		// ��ȡ��ǰʱ���  
    	now=std::chrono::system_clock::now();  
    	// ��ʱ���ת��Ϊtime_t���ͣ�time_t��C++�����ڱ�ʾʱ������ͣ���ͨ������1970��1��1������������  
    	now_c=std::chrono::system_clock::to_time_t(now);
    	// ��time_tת��Ϊlong long  
    	nowtime.unixtime=static_cast<long long>(now_c);  
    	// ��time_tת��Ϊ����ʱ��tm�ṹ�壬�Ա��ȡСʱ�����Ӻ���  
    	local_time=localtime(&now_c);  
    	// ��ȡ�ꡢ�¡��ա�Сʱ�����Ӻ���  
    	nowtime.year=local_time->tm_year+1900; // tm_year�Ǵ�1900�꿪ʼ�����  
    	nowtime.month=local_time->tm_mon+1;    // tm_mon�Ǵ�0��ʼ���·ݣ�0=һ�£�11=ʮ���£�  
    	nowtime.day=local_time->tm_mday; 
		nowtime.hour=local_time->tm_hour;  
    	nowtime.min=local_time->tm_min;  
    	nowtime.sec=local_time->tm_sec;  
		
		timer=nowtime.unixtime-starttime.unixtime;
		
    	tprint("\n");
    	tprint(nowtime.year,20);
    	tprint("��",5);
    	tprint(nowtime.month,20);
    	tprint("��",5);
    	tprint(nowtime.day,20);
    	tprint("��\t",40);
    	
    	tprint(nowtime.hour,20);
    	tprint("ʱ",5);
    	tprint(nowtime.min,20);
    	tprint("��",5);
    	tprint(nowtime.sec,20);
    	tprint("��\t",40);
    	
    	tprint("=537=\t",60);
		
		tprint("  ",30);
		
		tprint(TEXT("1970��"),30);
		
		tprint(TEXT("1��1��"),30);
		
		tprint(TEXT("���"),30);
		cout<<nowtime.unixtime;
		tprint(TEXT("��    "),60);
		
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<timer<<TEXT("��");
		SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		
		char timenum[MAX_PATH]={};
		itoa(timer,timenum,10);
		strcat(title,timenum);
		strcat(title,"s");
		SetConsoleTitle(TEXT(title));
		
		do{
			if(KEY(' ')){
    			strcat(title," Paused");
    			SetConsoleTitle(TEXT(title));
    			control();
			}
			Sleep(20);
		}while(timer==nowtime.sec);
	}
	
    return 0;
}
