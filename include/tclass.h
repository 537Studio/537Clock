#ifndef _FTSCLOCK_TCLASS_H_
#define _FTSCLOCK_TCLASS_H_

#include <iostream>
#include <string>
void tsleep(int milliseconds);
void tprint(std::string content, int SleepTime=0, int times=1);
/*
class t{
	public:
		void tsleep(int milliseconds){  
    		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));  
		}
		//template<typename T>
		void tprint(std::string content, int SleepTime=0, int times=1){  
			for(int i=0;i<times;i++)
				std::cout<<content; //�˺��������ǣ������times��content��
			tsleep(SleepTime);        //��ȥ�ȴ�SleepTime���� 
		}
};
*/
/*
namespace t{
	
	void tsleep(int milliseconds){  
    	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));  
	}
	
	template<typename T>
	void tprint(T content, int SleepTime=0, int times=1){  
		for(int i=0;i<times;i++)
			std::cout<<content; //�˺��������ǣ������times��content��
		tsleep(SleepTime);        //��ȥ�ȴ�SleepTime���� 
	}
	
}
*/
#endif
