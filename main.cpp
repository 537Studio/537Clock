#include "include/text.h"
#include "include/about.h"
int main(int argc, char* argv[]){
	setlanguage();
	if(lang==1){
		strcpy(T.AppName,APP_NAME_CN);
		strcpy(T.Version,TEXT_VERSION_CN);
		strcpy(T.BuildVersion,TEXT_BUILDVERSION_CN);
		
		strcpy(T.Support,APP_SUPPORT_CN);
		strcpy(T.Copyright,APP_COPYRIGHT_CN);
		
		strcpy(T.title,APP_NAME_CN);
		strcpy(T.title_AppName,APP_NAME_CN);
		strcat(T.title_AppName," - ");
		
		strcpy(T.year,TEXT_YEAR_CN);
		strcpy(T.month,TEXT_MONTH_CN);
		strcpy(T.date,TEXT_DATE_CN);
		strcpy(T.hour,TEXT_HOUR_CN);
		strcpy(T.min,TEXT_MIN_CN);
		strcpy(T.sec,TEXT_SEC_CN);
		
		strcpy(T.timer_year,TEXT_TIMER_YEAR_CN);
		strcpy(T.timer_month,TEXT_TIMER_MONTH_CN);
		strcpy(T.timer_date,TEXT_TIMER_DATE_CN);
		strcpy(T.timer_hour,TEXT_TIMER_HOUR_CN);
		strcpy(T.timer_min,TEXT_TIMER_MIN_CN);
		strcpy(T.timer_sec,TEXT_TIMER_SEC_CN);
		
		strcpy(T.pausepanel,TEXT_PAUSE_PANEL_CN);
		strcpy(T.timerclear,TEXT_TIMER_CLEAR_CN);
		strcpy(T.abouttheprogram,TEXT_ABOUT_THE_PROGRAM_CN);
		strcpy(T.changecolor,TEXT_CHANGE_COLOR_CN);
		strcpy(T.officialwebsite,TEXT_OFFICIAL_WEBSITE_CN);
		strcpy(T.email,TEXT_EMAIL_CN);
		strcpy(T.license,TEXT_LICENSE_CN);
		strcpy(T.opensourcewebsite,TEXT_OPEN_SOURCE_WEBSITE_CN);
		strcpy(T.clearscreen,TEXT_CLEAR_SCREEN_CN);
		strcpy(T.continuethetimer,TEXT_CONTINUE_THE_TIMER_CN);
		strcpy(T.exit,TEXT_EXIT_CN);
		
		strcpy(T.paused,TEXT_PAUSED_CN);
		strcpy(T.pressthekey,TEXT_PRESS_THE_KEY_CN);
		strcpy(T.pressthekeytoenablethefunction,TEXT_PRESS_THE_KEY_TO_ENABLE_THE_FUNCTION_CN); 
		strcpy(T.timeclear,TEXT_TIME_CLEAR_CN);
		strcpy(T.thewebsiteaddressis,TEXT_THE_WEBSITE_ADDRESS_IS_CN);
	}else{
		strcpy(T.AppName,APP_NAME_L);
		strcpy(T.Version,TEXT_VERSION);
		strcpy(T.BuildVersion,TEXT_BUILDVERSION);
		
		strcpy(T.Support,APP_SUPPORT);
		strcpy(T.Copyright,APP_COPYRIGHT);
		
		strcpy(T.title,APP_NAME_L);
		strcpy(T.title_AppName,APP_NAME_L);
		strcat(T.title_AppName," - ");
		
		strcpy(T.year,TEXT_YEAR);
		strcpy(T.month,TEXT_MONTH);
		strcpy(T.date,TEXT_DATE);
		strcpy(T.hour,TEXT_HOUR);
		strcpy(T.min,TEXT_MIN);
		strcpy(T.sec,TEXT_SEC);
		
		strcpy(T.timer_year,TEXT_TIMER_YEAR_S);
		strcpy(T.timer_month,TEXT_TIMER_MONTH_S);
		strcpy(T.timer_date,TEXT_TIMER_DATE_S);
		strcpy(T.timer_hour,TEXT_TIMER_HOUR_S);
		strcpy(T.timer_min,TEXT_TIMER_MIN_S);
		strcpy(T.timer_sec,TEXT_TIMER_SEC_S);
		
		strcpy(T.pausepanel,TEXT_PAUSE_PANEL);
		strcpy(T.timerclear,TEXT_TIMER_CLEAR);
		strcpy(T.abouttheprogram,TEXT_ABOUT_THE_PROGRAM);
		strcpy(T.changecolor,TEXT_CHANGE_COLOR);
		strcpy(T.officialwebsite,TEXT_OFFICIAL_WEBSITE);
		strcpy(T.email,TEXT_EMAIL);
		strcpy(T.license,TEXT_LICENSE);
		strcpy(T.opensourcewebsite,TEXT_OPEN_SOURCE_WEBSITE);
		strcpy(T.clearscreen,TEXT_CLEAR_SCREEN);
		strcpy(T.continuethetimer,TEXT_CONTINUE_THE_TIMER);
		strcpy(T.exit,TEXT_EXIT);
		
		strcpy(T.paused,TEXT_PAUSED);
		strcpy(T.pressthekey,TEXT_PRESS_THE_KEY);
		strcpy(T.pressthekeytoenablethefunction,TEXT_PRESS_THE_KEY_TO_ENABLE_THE_FUNCTION);
		strcpy(T.timeclear,TEXT_TIME_CLEAR);
		strcpy(T.thewebsiteaddressis,TEXT_THE_WEBSITE_ADDRESS_IS);
	}
	SetConsoleTitle(TEXT(T.AppName));
	SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	
	if(argc!=1){//带参数启动 
		if(string(argv[1])=="--ver" || string(argv[1])=="--version" || string(argv[1])=="-v"){ 
    		tprint(T.AppName,40);
    		tprint("\t");
    		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(T.Version,20);
			tprint(" ",10);
			tprint(APP_VERSION,20);
			SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
			tprint("\t",20);
			tprint(T.BuildVersion,30);
			tprint(" ");
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
    starttime.date=local_time->tm_mday; 
	starttime.hour=local_time->tm_hour;  
    starttime.min=local_time->tm_min;  
    starttime.sec=local_time->tm_sec;  
	
	last_unixtime=starttime.unixtime;
	
	while(true){
		strcpy(T.title,T.title_AppName);
		
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
    	nowtime.date=local_time->tm_mday; 
		nowtime.hour=local_time->tm_hour;  
    	nowtime.min=local_time->tm_min;  
    	nowtime.sec=local_time->tm_sec;  
		
		if(last_unixtime!=nowtime.unixtime){
			timer++;
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			tprint("\n");
    		tprint(nowtime.year,20);
    		tprint(T.year,5);
    		
    		tprint(nowtime.month,20);
    		tprint(T.month,5);
    		
			tprint(nowtime.date,20);
    		tprint(T.date,20);
    		tprint("\t",20);
    		
    		
    		SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    		tprint(nowtime.hour,20);
    		tprint(T.hour,5);
    		
			tprint(nowtime.min,20);
    		tprint(T.min,5);
    		
			tprint(nowtime.sec,20);
    		tprint(T.sec,20);
    		tprint("\t",20);
			
			SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(nowtime.unixtime,30);
			
			tprint("\t");
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			tprint(timer,5);
			tprint(T.timer_sec);
			SetConsoleColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		
			last_unixtime=nowtime.unixtime;
		}
    	
		
		char timenum[MAX_PATH]={};
		itoa(timer,timenum,10);
		strcat(T.title,timenum);
		strcat(T.title,T.timer_sec);
		SetConsoleTitle(TEXT(T.title));
		
		if(KEY(' ')){
    			strcat(T.title," ");
    			strcat(T.title,T.paused);
    			SetConsoleTitle(TEXT(T.title));
    			control();
			}
			Sleep(20);
	}
	
    return 0;
}
