#pragma once
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<mmsystem.h>
#include <windows.h>   //  �����graphics.h������..�����о�̬��winmm.lib
#include <mmsystem.h>  //������ý���豸�ӿ�ͷ�ļ�
//���ؾ�̬��
#include"Gamemenu.h"
#include"Rolecontrol.h"
#include"music.h"
#include"map_function.h"
#include"Gameresult.h"
//��ͼ2���жϺ���
int judgefiredoor2(double X, double Y);
int judgeicedoor2(double X, double Y);
int judgeicefloor2(double X, double Y);
int judgefirefloor2(double X, double Y);
int judgepoisonfloor2(double X, double Y);
int judgeboard21(double X, double Y);
int judgeboard22(double X, double Y);
int judgeboard23(double X, double Y);
int judgeboard24(double X, double Y);
int judgewallleft2(double X);
int judgewallright2(double X);
void judgedoor2();
void judgefloor2();
int judgebottom2( double N);

//��ͼ1���жϺ���
int judgefiredoor1(double X, double Y);
int judgeicedoor1(double X, double Y);
int judgeicefloor11(double X, double Y);
int judgefirefloor11(double X, double Y);
int judgepoisonfloor1(double X, double Y);
int judgeboard11(double X, double Y);
int judgeboard12(double X, double Y);
int judgeboard13(double X, double Y);
int judgeboard14(double X, double Y);
int judgeboard15(double X, double Y);
int judgeboard16(double X, double Y);
int judgeboard17(double X, double Y);
int judgewallleft1(double X);
int judgewallright1(double X);
void judgedoor1();
void judgefloor1();
int judgebottom1(double N);
int judgefirefloor12(double X, double Y);
int judgefirefloor13(double X, double Y);
int judgeicefloor12(double X, double Y);
int judgeicefloor13(double X, double Y);
int judgeboard111(double X, double Y);
int judgeboard112(double X, double Y);
int judgeboard113(double X, double Y);
int judgeboard114(double X, double Y);
int judgeboard115(double X, double Y);
int judgeboard116(double X, double Y);
int judgeboard117(double X, double Y);











