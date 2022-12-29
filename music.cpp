
#include <stdio.h>
#include <stdlib.h>
//包含图形库头文件
#include <string.h>
#include <conio.h>  //使用getch()
#include <graphics.h>

#include"music.h"
//播放音乐
#include <windows.h>   //  这个在graphics.h里面有..里面有静态库winmm.lib
#include <mmsystem.h>  //包含多媒体设备接口头文件
//加载静态库
#pragma comment(lib, "winmm.lib")
//最后就可以使用mciSendString函数来播放音乐了
void musicplay_bgm1() //播放游戏背景音乐函数
{

	mciSendString("open 背景音乐1.mp3", 0, 0, 0);
	mciSendString("play 背景音乐1.mp3 repeat", 0, 0, 0);
}
void musicplay_bgm2() //播放游戏背景音乐函数
{

	mciSendString("open 背景音乐2.mp3", 0, 0, 0);
	mciSendString("play 背景音乐2.mp3 repeat", 0, 0, 0);
}
void soundeffect_death()
{
	mciSendString("open 死亡.mp3", 0, 0, 0);
	mciSendString("play 死亡.mp3", 0, 0, 0);
}
void soundeffect_victory()
{
	mciSendString("open 胜利.mp3", 0, 0, 0);
	mciSendString("play 胜利.mp3", 0, 0, 0);
}
void soundeffect_fall()
{
	mciSendString("open 失败.mp3", 0, 0, 0);
	mciSendString("play 失败.mp3", 0, 0, 0);
}

void soundeffect_gem()
{
	mciSendString("open 捡到宝石.mp3", 0, 0, 0);
	mciSendString("play 捡到宝石.mp3 ", 0, 0, 0);
}
