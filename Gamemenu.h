#pragma once
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<mmsystem.h>
#include <windows.h>   //  �����graphics.h������..�����о�̬��winmm.lib
#pragma comment(lib, "winmm.lib")

 


void drawButton(struct button* pB);
int mouseInButton(struct button* pB, MOUSEMSG m);
int clickButton(struct button* pB, MOUSEMSG m);
int GameIntroduction();
int TeamIntroduction();
int levelChoose();
int Gameadjust();
void GameMainMenu();
void  GameWin();
void GameFall();
