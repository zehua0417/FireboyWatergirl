#pragma once
#include <stdio.h>
#include <stdlib.h>
//包含图形库头文件
#include <string.h>
#include <conio.h>  //使用getch()
#include <graphics.h>

//播放音乐
#include <windows.h>   //  这个在graphics.h里面有..里面有静态库winmm.lib
#include <mmsystem.h>  //包含多媒体设备接口头文件
//加载静态库
#pragma comment(lib, "winmm.lib")
//最后就可以使用mciSendString函数来播放音乐了
//背景音乐1函数
void musicplay_bgm1();
//播放游戏背景音乐2函数
void musicplay_bgm2();
//人物死亡音效
void soundeffect_death();
//游戏胜利音效（到门的时候）
void soundeffect_victory();
//游戏失败音效（遇到错误的河的时候）
void soundeffect_fall();
//拾取宝石的音效
void soundeffect_gem();
