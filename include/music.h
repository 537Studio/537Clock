/*
537Clock
Version 1.3

include/music.h

Copyright (C) 537 Studio. 2023-2024. All rights reserved.
From: crystal203.github.io
*/

//需链接-lwinnm

/*
介绍

### 基于 `Windows API MIDI` 的 `music.h` 使用帮助

调用本头文件，能够在您的 c++ 程序中播放音色良好的自定义音乐。

#### 0.1 软件/语言支持

+ x64 Windows 系统
+ C++

#### 0.2 编译器配置

+ 开启 C++11 `-std=c++11`
+ 连接器命令行 `-lwinmm` 

### 1. 如何自定义音乐

#### 简谱格式

在任意文本文档中，第一行输入一个整数，表示乐曲节奏进行的快慢（一个四分音符的延时，毫秒），之后若干行输入指定格式的字符串，表示音符集，即可完成创作。——适用于 v1.0 版本

**在 v1.1 版本中，加入了左右手谱功能，允许程序同时播放两重旋律。此时，音符集部分将自动以两行为一组，每组为同时演奏的两重旋律。使用空行将强制打断多重旋律判定。**

例如：

```
1 2 3 4 5 5 4 3 2 1
1^- 2^- 3^ 4^- 5^--

1 1 5 5 6 6 5

1^- 2^- 3^ 4^- 5^--
```

前两行音符将同时播放，此后，后两行音符将依次播放。


**音符集格式规范**

任意两个音符/和弦间应用空格隔开。事实上，播放音符的判定**总**会在空格处执行。

高/低/升音号必须紧跟在音符后面，但这些符号内部的顺序不限。

延/分音号与音符间的顺序不限，但延/分音号内部将从左到右判读。和弦的延/分音号建议放在和弦外面。

| 字符  | 说明   | 使用示例                                               |
| ----- | ------ | ------------------------------------------------------ |
| `1~7` | 音符   | 如 `1 2 3 4 5` 表示播放 `do re mi fa sol` 五个音符     |
| `0`   | 休止符 | 略                                                     |
| `,`   | 低音   | 即音符向下附点，最多可以有三个低音号。如 `1,` `2,,` 等 |
| `^`   | 高音   | 类比低音                                               |
| `#`   | 升音   | 向上半音高。如 `4#`                                    |
| `-`   | 延音   | 每个延音号将为音符额外多出一个四分音符的延时           |
| `_`   | 分音   | 每个分音号将使音符的延时减半                           |
| `.`   | 附点   | 每个附点号将使音符的延时增半（×1.5）                   |
| `[]`  | 和弦   | 中括号内的音符将一次性演奏                             |
| `|`   | 小节线 | 程序将忽略这个符号                                     |

1*, 1% 2%^ 3# 2. 1, 3--

**在 v1.1/v1.2 版本中**，相继添加了 `*` `%` `&` 分别将音符的延时缩减为原先的三分之一，五分之一和七分之一。

### 2. 头文件解析

#### 2.1 `MusicPlayer` 类

音乐播放器。将连接相关的 `API` 进行音乐播放操作。

+ `void setVolume(int _vol)` 设置音量（`0x00` 至 `0x7f`）
+ `void setDelay(int _dctn)` 设置四分音符延时（毫秒）
+ `void play(string s)` 播放**简谱格式**的一行音符
+ `void playList(MusicList &m)` 播放歌曲

#### 2.2 `MusicList` 类

歌曲。可以将若干行音符整合，也可从文件中读取音符。

+ `void setDelay(int _dctn)` 设置四分音符延时（毫秒）——优先于播放器设置的延时
+ `void add(string s)` `void addk(string s)` 插入一行简谱格式或 `autopiano` 格式的音符
+ `void clear()` 清空歌曲
+ `void readFile(string s)` 从文件中读取音符集

#### 2.3 `BGM` 类

使用多线程，可使程序在运行同时播放歌曲。

+ `void setMusic(string s)` 从文件中读取音符集并绑定
+ `void play()` 开始循环播放此音乐
+ `void stop()` 停止播放此音乐

### 3. 程序使用范例

#### 3.1 播放指定乐曲

```cpp
#include <bits/stdc++.h>
using namespace std;
#include "music.h"
signed main(){
	MusicPlayer player;
	MusicList m;
	m.readFile("skycity.txt"); //此处输入乐曲存放的文件名
	player.playList(m);
	return 0;
}
```

#### 3.2 BGM播放

```cpp
#include <bits/stdc++.h>
using namespace std;
#include "music.h"
#include <conio.h>
signed main(){
	BGM bgm("skycity.txt",0x4f);
	bgm.play();
    //下面这部分可以换成需要的程序内容。音乐播放将不会妨碍程序运行。
	puts("Please Input A & B");
	int a,b;scanf("%d %d",&a,&b);
	printf("A + B = %d\n",a+b);
	puts("Press Any Key to EXIT");
	getch();
    
	bgm.stop();
	return 0;
}
```
 
*/
#include <windows.h>
#include <thread>
#include <conio.h>
#include <mutex>
#include <regex>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <assert.h>
#define DEBUG 0
class MusicList{
public:
	int dctn=500;
	std::vector <std::string> vec;
	~MusicList(){}
	void add(std::string s){
		vec.push_back(s);
	}
	void clear(){
		vec.clear();
	}
	void setDelay(int _dctn){
		dctn=_dctn;
	}
	void readFile(std::string fileName=""){
		clear();
		std::ifstream in(fileName);
		in>>dctn;
		std::string s;
		while (getline(in,s)) add(s);
		in.close();
	}
	MusicList(std::string fileName=""){
		vec.clear();
		if (fileName!="") readFile(fileName);
	}
};
bool isNumeric(std::string const &str){
    return regex_match(str,std::regex("[(-|+)|][0-9]+"));
}
class MusicPlayer{
private:
	enum scale{
		Rest=0,
		C8=108,
		B7=107,A7s=106,A7=105,G7s=104,G7=103,F7s=102,F7=101,E7=100,D7s=99, D7=98, C7s=97, C7=96,
		B6=95, A6s=94, A6=93, G6s=92, G6=91, F6s=90, F6=89, E6=88, D6s=87, D6=86, C6s=85, C6=84,
		B5=83, A5s=82, A5=81, G5s=80, G5=79, F5s=78, F5=77, E5=76, D5s=75, D5=74, C5s=73, C5=72,
		B4=71, A4s=70, A4=69, G4s=68, G4=67, F4s=66, F4=65, E4=64, D4s=63, D4=62, C4s=61, C4=60,
		B3=59, A3s=58, A3=57, G3s=56, G3=55, F3s=54, F3=53, E3=52, D3s=51, D3=50, C3s=49, C3=48,
		B2=47, A2s=46, A2=45, G2s=44, G2=43, F2s=42, F2=41, E2=40, D2s=39, D2=38, C2s=37, C2=36,
		B1=35, A1s=34, A1=33, G1s=32, G1=31, F1s=30, F1=29, E1=28, D1s=27, D1=26, C1s=25, C1=24,
		B0=23, A0s=22, A0=21	
	};
	const int C_Scale[7][7]={{C1,D1,E1,F1,G1,A1,B1},
							 {C2,D2,E2,F2,G2,A2,B2},
							 {C3,D3,E3,F3,G3,A3,B3},
							 {C4,D4,E4,F4,G4,A4,B4},
							 {C5,D5,E5,F5,G5,A5,B5},
							 {C6,D6,E6,F6,G6,A6,B6},
							 {C7,D7,E7,F7,G7,A7,B7}};
	const int C_Scale_s[7][7]={{C1s,D1s,-1,F1s,G1s,A1s,-1},
							   {C2s,D2s,-1,F2s,G2s,A2s,-1},
							   {C3s,D3s,-1,F3s,G3s,A3s,-1},
							   {C4s,D4s,-1,F4s,G4s,A4s,-1},
							   {C5s,D5s,-1,F5s,G5s,A5s,-1},
							   {C6s,D6s,-1,F6s,G6s,A6s,-1},
							   {C7s,D7s,-1,F7s,G7s,A7s,-1}};
	HMIDIOUT handle;
	int dctn=500;
	int volume=0x7f;
public:
	bool ENDMUSIC=0;
	int STOP;
	MusicPlayer(){
		midiOutOpen(&handle,0,0,0,CALLBACK_NULL);
	}
	~MusicPlayer(){
		midiOutClose(handle);
	}
	void setVolume(int _vol){
		volume=_vol;
	}
	void setDelay(int _dctn){
		dctn=_dctn;
	}
	std::mutex mu;
	int ttag=0;
	int tick1,tick2;
	void play_single(std::string s,bool isMain){
		std::vector <int> nbuf;
		s=s+' ';int n=s.size();
		int ctn=32*21,vol=volume;
		bool isChord=0;nbuf.clear();
		int st=clock(),tick=0;
		for (int i=0;i<n;++i){
			if (ENDMUSIC) break;
			char c=s[i];
			switch (c){
				case '[':case '{':{
					assert(isChord==0);
					isChord=1;
					break;
				}
				case ']':case '}':{
					assert(isChord==1);
					isChord=0;
					break;
				}
				case ' ':{
					if (!isChord){
						if (!nbuf.empty()){
							for (int i=0;i<(int)nbuf.size();++i) if (nbuf[i]!=0) midiOutShortMsg(handle,nbuf[i]);nbuf.clear();
							while ((clock()-st)*1000.0/CLOCKS_PER_SEC<dctn/32.0/21*(tick+ctn));tick+=ctn;ctn=32*21;			
						}
					}
					break;
				}
				case '|':break;
				case '_':{
					ctn/=2;
					break;
				}
				case '*':{
					ctn/=3;
					break;
				}
				case '&':{
					ctn/=7;
					break;
				}
				case '%':{
					ctn/=5;
					break;
				}
				case '.':{
					ctn*=1.5;
					break;
				}
				case '-':{
					ctn+=32*21;
					break;
				}
				case '0':{
					nbuf.push_back(Rest);
					break;
				}
				default:{
					assert(c>='1' && c<='7');
					int x=(int)c-49,lvl=3;
					bool isSharp=0;
					for (int j=i+1;j<n;++j){
						if (s[j]=='^') lvl++;
						else if (s[j]==',') lvl--;
						else if (s[j]=='#') isSharp=1; 
						else break;
						i++;
					}
					if (isSharp) nbuf.push_back((vol<<16)+(C_Scale_s[lvl][x]<<8)+0x90);
					else nbuf.push_back((vol<<16)+(C_Scale[lvl][x]<<8)+0x90);
					break;
				}
			}
		}
		if (isMain) tick1=tick;else tick2=tick;
		mu.lock();
		STOP++;
		mu.unlock();
		return;
	}
	void play(std::string s1,std::string s2=""){
		STOP=0;tick1=0;tick2=0;
		std::thread tune1(&MusicPlayer::play_single,this,s1,1);tune1.detach();
		std::thread tune2(&MusicPlayer::play_single,this,s2,0);tune2.detach();
		while (STOP<2);
		if (DEBUG){
			if (tick1==tick2) puts("Succ");
			else printf("Warn: %d!=%d\n",tick1,tick2);			
		}
	}
	void playList(MusicList &m){
		dctn=m.dctn;ENDMUSIC=0;
		for (int i=0;i<(int)m.vec.size() && !ENDMUSIC;++i){
			while (i<(int)m.vec.size() && (m.vec[i]=="" || isNumeric(m.vec[i]))){
				if (isNumeric(m.vec[i])) setDelay(stoi(m.vec[i]));i++;
			}
			if (i>=(int)m.vec.size()) break;
			std::string s1=m.vec[i],s2="";
			if (i<(int)m.vec.size()-1 && m.vec[i+1]!="") s2=m.vec[i+1],i++;
			play(s1,s2);
		}
	}
};
class BGM{
public:
	MusicPlayer player;
	MusicList nowList;
	BGM(std::string name,int volume=0x7f){
		nowList.readFile(name);player.setVolume(volume);
	}
	~BGM(){
		player.ENDMUSIC=1;
	}
	void setMusic(std::string name){
		nowList.readFile(name);
	}
	void play_thread(){
		while (1){
			player.playList(nowList);
			if (player.ENDMUSIC) break;	
		}
	}
	void play(){
		player.ENDMUSIC=0;
		std::thread bgm(&BGM::play_thread,this);bgm.detach();
	}
	void stop(){
		player.ENDMUSIC=1;
	}
};
