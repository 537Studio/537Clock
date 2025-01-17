/*
537 Clock
Version 2.0 Beta

tclass.cpp

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
*/
#include "include/tclass.h"

#ifndef _GLIBCXX_HAS_GTHREADS
#define _GLIBCXX_HAS_GTHREADS
#endif

#ifndef _GLIBCXX_USE_C99_STDINT_TR1
#define _GLIBCXX_USE_C99_STDINT_TR1 1
#endif


#ifndef _GLIBCXX_THREAD_ABI_COMPAT
#define _GLIBCXX_THREAD_ABI_COMPAT
#endif

#include <thread>
#include <chrono>
void tsleep(int milliseconds){  
	std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));  
}
void tprint(std::wstring content, int SleepTime, int times){  
	for(int i=0;i<times;i++) std::wcout<<content; //此函数作用是：在输出times个content后，
	tsleep(SleepTime);        //再去等待SleepTime毫秒 
}
