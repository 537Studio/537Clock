/*
537 USB Disk Manager
Version 1.0 Beta

gif.cpp

Copyright (C) 537 Studio. 2024. All rights reserved.
*/
#include "include/graphics.h"
#include <stdio.h>
#include "include/gif.h"

//构造函数
Gif::Gif(const WCHAR* gifFileName, HDC hdc)
{
	init();
	if (gifFileName != NULL)
		load(gifFileName);
	bind(hdc);
}

//复制构造函数
Gif::Gif(const Gif& gif)
{
	copy(gif);
}

//析构函数
Gif::~Gif()
{
	delete gifImage;
	delete pItem;
	delete graphics;
}

//赋值操作符重载
Gif & Gif::operator=(const Gif & gif)
{
	if (this == &gif)		return *this;
	if (graphics != NULL)	delete graphics;
	if (pItem != NULL)		delete pItem;
	if (gifImage != NULL)	delete gifImage;

	copy(gif);

	return *this;
}

//初始化
void Gif::init()
{
	x = y = 0;
	width = height = 0;
	hdc = 0;
	gifImage = NULL;
	graphics = NULL;
	pItem = NULL;
	visible = true;

	resetPlayState();
}

//加载图像
void Gif::load(const WCHAR * gifFileName)
{
	if (gifImage != NULL)
		delete gifImage;
	gifImage = new Gdiplus::Bitmap(gifFileName);

	read();
}

//绑定绘制目标HDC
void Gif::bind(HDC hdc)
{
	this->hdc = hdc;
	if (graphics != NULL)
		delete graphics;
	graphics = Gdiplus::Graphics::FromHDC(hdc);
}

//绑定绘制目标到窗口
void Gif::bindWindow()
{
	if (hdc != getHDC())
		bind(getHDC());
}

//清除加载的图像
void Gif::clear()
{
	if (gifImage) {
		delete gifImage;
		gifImage = NULL;
	}

	if (pItem) {
		delete pItem;
		pItem = NULL;
	}
	frameCount = 0;
}

//获取图像原宽度
int Gif::getOrginWidth() const
{
	if (!gifImage)
		return 0;
	return gifImage->GetWidth();
}

//获取图像原宽度
int Gif::getOrginHeight() const
{
	if (!gifImage)
		return 0;
	return gifImage->GetHeight();
}

void Gif::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

//设置图像大小
void Gif::setSize(int width, int height)
{
	this->width = width;
	this->height = height;
}

//在当前位置绘制当前帧
void Gif::draw()
{
	draw(x, y);
}

//在指定位置绘制当前帧
void Gif::draw(int x, int y)
{
	updateTime();
	drawFrame(curFrame, x, y);
}

//在当前位置绘制指定帧
void Gif::drawFrame(int frame)
{
	drawFrame(frame, x, y);
}

//在指定位置绘制指定帧
void Gif::drawFrame(int frame, int x, int y)
{
	if (!visible)
		return;
	int w = width, h = height;
	if (w == 0 && h == 0) {
		w = gifImage->GetWidth();
		h = gifImage->GetHeight();
	}
	if (frameCount != 0 && gifImage && 0 <= frame) {
		frame %= frameCount;
		gifImage->SelectActiveFrame(&Gdiplus::FrameDimensionTime, frame);
		graphics->DrawImage(gifImage, x, y, w, h);
	}
}

//获取Gif的指定帧，并保存到pimg中
void Gif::getimage(PIMAGE pimg, int frame)
{
	if (frame < 0 || frameCount <= frame)
		return;

	int width = gifImage->GetWidth(), height = gifImage->GetHeight();

	if (width != getwidth(pimg) || height != getheight(pimg))
		resize(pimg, width, height);

	//自定义图像缓存区(ARGB）
	Gdiplus::BitmapData bitmapData;
	bitmapData.Stride = width * 4;
	int buffSize = width * height * sizeof(color_t);
	bitmapData.Scan0 = getbuffer(pimg);

	gifImage->SelectActiveFrame(&Gdiplus::FrameDimensionTime, frame);
	Gdiplus::Rect rect(0, 0, width, height);
	//以32位像素ARGB格式读取， 自定义缓存区

	gifImage->LockBits(&rect,
		Gdiplus::ImageLockModeRead | Gdiplus::ImageLockModeUserInputBuf, PixelFormat32bppARGB, &bitmapData);
	gifImage->UnlockBits(&bitmapData);
}

//获取指定帧的延时时间
int Gif::getDelayTime(int frame) const
{
	if (frame < 0 || frameCount <= frame ||
		!pItem || pItem->length <= (unsigned int)frame)
		return 0;
	else
		return ((long*)pItem->value)[frame] * 10;
}

//设置指定帧的延时时间
void Gif::setDelayTime(int frame, long time_ms)
{
	if (frame < 0 || frameCount <= frame ||
		!pItem || pItem->length <= (unsigned int)frame)
		return;
	else
		((long*)pItem->value)[frame] = time_ms / 10;
}

//统一设置所有帧的延时时间
void Gif::setAllDelayTime(long time_ms)
{
	for (int i = 0; i < frameCount; i++)
		((long*)pItem->value)[i] = time_ms / 10;
}

//播放
void Gif::play()
{
	playing = true;
	clock_t sysTime = clock();
	if (frameBaseTime == 0) {
		pauseTime = frameBaseTime = sysTime;
		curFrame = 0;
		frameDelayTime = getDelayTime(curFrame);
	}
	else
		frameBaseTime += sysTime - pauseTime;
}

//暂停
void Gif::pause()
{
	if (playing) {
		playing = false;
		this->pauseTime = clock();
	}
}

//播放暂停切换
void Gif::toggle()
{
	playing ? pause() : play();
}

//重置播放状态
void Gif::resetPlayState()
{
	curFrame = 0;
	curDelayTime = frameBaseTime = frameDelayTime = 0;
	pauseTime = 0;
	playing = false;
}

//控制台显示Gif信息
void Gif::info() const
{
	printf(L"Gif Paint Size: %d x %d\n", getWidth(), getHeight());
	printf(L"Gif Normal Size: %d x %d\n", getOrginWidth(), getOrginHeight());
	int frameCnt = getFrameCount();
	printf(L"FPS: %d\n", getFrameCount());
	/*
	printf("The delay time of the frame:\n");
	
	for (int i = 0; i < frameCnt; i++)
		printf("Frame%3d:%4d ms\n", i, getDelayTime(i));
	*/
}

//读取图像
void Gif::read()
{
	/*读取图像信息*/
	UINT count = gifImage->GetFrameDimensionsCount();
	GUID* pDimensionIDs = (GUID*)new GUID[count];
	gifImage->GetFrameDimensionsList(pDimensionIDs, count);
	//帧数
	frameCount = gifImage->GetFrameCount(&pDimensionIDs[0]);
	delete[] pDimensionIDs;

	if (pItem != NULL)
		delete pItem;

	//获取每帧的延时数据
	int size = gifImage->GetPropertyItemSize(PropertyTagFrameDelay);
	pItem = (Gdiplus::PropertyItem*)malloc(size);
	gifImage->GetPropertyItem(PropertyTagFrameDelay, size, pItem);
}

//Gif复制
void Gif::copy(const Gif& gif)
{
	hdc = gif.hdc;
	x = gif.x;
	y = gif.y;
	width = gif.width;
	height = gif.height;
	curFrame = gif.curFrame;
	pauseTime = gif.pauseTime;

	frameBaseTime = gif.frameBaseTime;
	curDelayTime = gif.curDelayTime;
	frameDelayTime = gif.frameDelayTime;

	frameCount = gif.frameCount;
	graphics = new Gdiplus::Graphics(hdc);
	gifImage = gif.gifImage->Clone(0, 0, gif.getWidth(), gif.getHeight(), gif.gifImage->GetPixelFormat());

	int size = gif.gifImage->GetPropertyItemSize(PropertyTagFrameDelay);
	pItem = (Gdiplus::PropertyItem*)malloc(size);
	memcpy(pItem, gif.pItem, size);
}

//Gif时间更新，计算当前帧
void Gif::updateTime()
{
	//图像为空，或者不是动图，或者没有调用过play()播放（）
	if (frameCount <= 1 || frameBaseTime == 0
		|| (pItem && pItem->length == 0))
		return;

	//根据播放或暂停计算帧播放时间
	curDelayTime = playing ? (clock() - frameBaseTime) : (pauseTime - frameBaseTime);

	int cnt = 0, totalTime = 0;

	//间隔时间太长可能会跳过多帧
	while (curDelayTime >= frameDelayTime) {
		curDelayTime -= frameDelayTime;
		frameBaseTime += frameDelayTime;

		//切换到下一帧
		if (++curFrame >= frameCount)
			curFrame = 0;
		frameDelayTime = getDelayTime(curFrame);

		totalTime += frameDelayTime;

		//多帧图像，但总延时时间为0的处理
		if (++cnt == frameCount && totalTime == 0)
			break;
	}
}

