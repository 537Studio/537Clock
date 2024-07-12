#include "include/text.h"
#include "include/about.h"
int main(int argc, char* argv[]){
	SetConsoleTitle(TEXT(APP_NAME_L)); 
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	if(argc!=1){//带参数启动 
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
		
		// 获取当前时间点  
    	now=std::chrono::system_clock::now();  
    	// 将时间点转换为time_t类型，time_t是C++中用于表示时间的类型，它通常是自1970年1月1日以来的秒数  
    	now_c=std::chrono::system_clock::to_time_t(now);
    	// 将time_t转换为long long  
    	nowtime.unixtime=static_cast<long long>(now_c);  
    	// 将time_t转换为本地时间tm结构体，以便获取小时、分钟和秒  
    	local_time=localtime(&now_c);  
    	// 提取年、月、日、小时、分钟和秒  
    	nowtime.year=local_time->tm_year+1900; // tm_year是从1900年开始的年份  
    	nowtime.month=local_time->tm_mon+1;    // tm_mon是从0开始的月份（0=一月，11=十二月）  
    	nowtime.day=local_time->tm_mday; 
		nowtime.hour=local_time->tm_hour;  
    	nowtime.min=local_time->tm_min;  
    	nowtime.sec=local_time->tm_sec;  
		
		timer=nowtime.unixtime-starttime.unixtime;
		
    	tprint("\n");
    	tprint(nowtime.year,20);
    	tprint("年",5);
    	tprint(nowtime.month,20);
    	tprint("月",5);
    	tprint(nowtime.day,20);
    	tprint("日\t",40);
    	
    	tprint(nowtime.hour,20);
    	tprint("时",5);
    	tprint(nowtime.min,20);
    	tprint("分",5);
    	tprint(nowtime.sec,20);
    	tprint("秒\t",40);
    	
    	tprint("=537=\t",60);
		
		tprint("  ",30);
		
		tprint(TEXT("1970年"),30);
		
		tprint(TEXT("1月1日"),30);
		
		tprint(TEXT("距今"),30);
		cout<<nowtime.unixtime;
		tprint(TEXT("秒    "),60);
		
		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		cout<<timer<<TEXT("秒");
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
