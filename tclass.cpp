/*
537 Clock
Version 2.0 Beta

tclass.cpp

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/
#include "include/tclass.h"
#include <thread>
#include <chrono>
void tsleep(int milliseconds){  
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));  
}
void tprint(std::string content, int SleepTime, int times){  
	for(int i=0;i<times;i++) std::cout<<content; //�˺��������ǣ������times��content��
	tsleep(SleepTime);        //��ȥ�ȴ�SleepTime���� 
}
