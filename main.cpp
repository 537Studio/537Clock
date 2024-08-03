#include "include/text.h"
#include "include/about.h"

void menu(); 
void logo();
void about(); 
void color();
void PRESS_ENTER_TO_CONTINUE();
void PRESS_SPACE_TO_CONTINUE();
//���ã�����537Clock1.1�汾�󰴼���������ߣ�ע�ⲻҪ����һ�����������غ� 
//�����û���δ��ʱ̧�𰴼��������ٴδ�����ͣ�˵� 
//�����ڶ��⹦����ʹ��PRESS_ENTER_TO_CONTINUE()����
void cls();
void gotoxy(int x, int y);
void SetConsoleColor(WORD color);

int main(int argc, char* argv[]){
	getlanguage();
	
	SetConsoleTitle(TEXT(T.AppName));
	
	if(argc!=1){//���������� 
		if(string(argv[1])=="--ver" || string(argv[1])=="--version" || string(argv[1])=="-v"){ 
			setlanguage(lang);
			
			SetConsoleColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
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
		if(string(argv[1])=="/lan" || string(argv[1])=="/lang"){
    		if(string(argv[2])=="cn" || string(argv[2])=="chinese" || string(argv[2])=="Chinese" || string(argv[2])=="zh-CN" || string(argv[2])=="zh-TW" || string(argv[2])=="zh-HK" || string(argv[2])=="zh-MO"){
    			tprint("�ڼ�������ģʽ������\n");
    			lang=1;
    			setlanguage(lang);
			}else if(string(argv[2])=="en" || string(argv[2])=="english" || string(argv[2])=="English" || string(argv[2])=="en-US" || string(argv[2])=="en-GB" || string(argv[2])=="en-AU" || string(argv[2])=="en-CA" || string(argv[2])=="en-NZ" || string(argv[2])=="en-IE" || string(argv[2])=="en-ZA" || string(argv[2])=="en-JM" || string(argv[2])=="en-TT" || string(argv[2])=="en-PH" || string(argv[2])=="en-IN" || string(argv[2])=="en-MY" || string(argv[2])=="en-SG"){
				tprint("Run in the English mode\n");
				lang=2;
				setlanguage(lang);
			}else{
				setlanguage(lang);
			}
		} 
	}else{
		setlanguage(lang);
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
