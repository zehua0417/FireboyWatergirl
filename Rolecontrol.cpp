
#include<graphics.h>
#include<stdio.h>
#include<windows.h>
#include"Rolecontrol.h"
#include"Judge.h"
#include"map_function.h"
/*
 项目日志
1.做窗口
2.加载图片
3.开始播放背景音乐
4.循环贴图
5.按键控制人物移动
*/

#define WINDOW_WIDTH 800
#define WINDOW_HEIGTHT 600
#define time 60
int fb_time = 0;
int wg_time = 0;
//全局变量：背景图和动作图
IMAGE bk, move, BlueStand, RedStand, BK;
//人物初始坐标
double x = 25, y = 545;
double b = 132, n = 545;
//用于存放图片的数组
char name1[256];
char name2[256];
char name3[256];
char name4[256];
IMAGE imageHeros1[10];
IMAGE imageHeros2[10];
IMAGE imageHeros3[10];
IMAGE imageHeros4[10];
//初始化游戏
/*
1.做窗口
2.加载图片
3.变量的初始化
4.播放背景音乐
*/
void initGame() {
	

	loadimage(&BlueStand, "bk1(2).png",20,30);
	loadimage(&RedStand, "bk2(1).png",20,30);
}

//判断冰面
int judgeicefloor(double X, double Y)
{
	if (X <= 630 && X >= 545 && Y >= 685)
		return 1;//位于冰面
	else
		return 0;
}
//判断火面
int judgefirefloor(double X, double Y)
{
	if (X >= 864 && X >= 770 && Y >= 685)
		return 1;//位于火面
	else
		return 0;
}
//判断毒面
int judgepoisonfloor(double X, double Y)
{
	if (X >= 695 && X <= 815 && Y >= 540 && Y <= 568)
		return 1;//位于毒面
	else
		return 0;
}
//贴图
/*
贴背景图
贴人物图
*/



//这里的函数是为了把所有图片都放到一个数组里面
void drawGame() {
	//贴图前防止闪烁
	BeginBatchDraw();

	//加载人物奔跑图片,//贴人物图

	for (int i = 0; i < 7; i++) {
		sprintf_s(name1, "红色妖姬右/红色妖姬%d(1)(1).png", i + 1);
		loadimage(&imageHeros1[i], name1,20,30);
	}

	for (int i = 0; i < 4; i++) {
		sprintf_s(name2, "红色妖姬左/红色妖姬%d(1)(1).png", i + 1);
		loadimage(&imageHeros2[i], name2,20,30);
	}

	for (int i = 0; i < 4; i++) {
		sprintf_s(name3, "蓝色妖姬左/蓝色妖姬%d(1)(1).png", i + 1);
		loadimage(&imageHeros3[i], name3,20,30);
	}

	for (int i = 0; i < 9; i++) {
		sprintf_s(name4, "蓝色妖姬右/蓝色妖姬%d(1)(1).png", i + 1);
		loadimage(&imageHeros4[i], name4,20,30);
	}


	putimage(0, 0, &BK);//贴背景图
	putimage(b, n, &BlueStand);
	putimage(x, y, &RedStand);
	EndBatchDraw();
}


int judgeFloor(double x, double y) {
	if (x > 600 && x < 800 && y>400 && y < 600)return 1;//假设此处为空
	else
		return 0;
}

//改变加速度
void changePlusSpeed(double& ay) {
	if (!judgeFloor(x, y))
		ay += 10;
	else
		ay = 0;
}




//通过键盘控制人物移动
void controlGame1() {

	if (GetAsyncKeyState('W') & 0x8000) {
		
		for (int i = 0; i < 7; i++) {
			
			transparentimage(NULL,x, y, &imageHeros1[i]);
			Sleep(100);
			
		}
		
		y -= 100;
		while (!judgeFloor(x, y)&& judgebottom2(x) == 2 && judgeboard11(x, y) == 2 && judgeboard12(x, y) == 2 && judgeboard13(x, y) == 2 && judgeboard14(x, y) == 2 && judgeboard15(x, y) == 2 && judgeboard16(x, y) == 2 && judgeboard17(x, y) == 2) {
			if (GetAsyncKeyState('D') & 0x8000) {
				if (judgewallright2(x) == 2)
				x += 20;
			}
			if (GetAsyncKeyState('A') & 0x8000)
			{
				if (judgewallleft2(x) == 2)
				x -= 20;
			}
			if (judgebottom2(x) == 2 && judgeboard11(x, y) == 2 && judgeboard12(x, y) == 2 && judgeboard13(x, y) == 2 && judgeboard14(x, y) == 2 && judgeboard15(x, y) == 2 && judgeboard16(x, y) == 2 && judgeboard17(x,y) == 2)
			y += 5;
			else
			break;
			for (int i = 0; i < 7; i++) {
				transparentimage(NULL,x, y, &imageHeros1[i]);
				Sleep(5);
			}
			transparentimage(NULL,0, 0, &BK);
			transparentimage(NULL,b, n, &BlueStand);

		
			set_map(1);
			search_diamond(x, y, b, n);
			set_diamond();
			
			if (x<25||x >= 775|| y >= 545)break;
		}
	}
	if (GetAsyncKeyState('D') & 0x8000) {
		for (int i = 0; i < 4; i++) {
			transparentimage(NULL,x, y, &imageHeros1[i]);
			Sleep(100);
		}
		if (judgewallright2(x)==2)
		x += 20;
		if (GetAsyncKeyState('W') & 0x8000) {
			y -= 30;


		}
		

	}
	if (GetAsyncKeyState('S') & 0x8000) {
		for (int i = 0; i < 7; i++) {
			transparentimage(NULL,x, y, &imageHeros1[i]);
			Sleep(100);
		}
		if (judgebottom2(y) == 2 && judgeboard11(x, y) == 2 && judgeboard12(x, y) == 2 && judgeboard13(x, y) == 2 && judgeboard14(x, y) == 2 && judgeboard15(x, y) == 2 && judgeboard16(x, y) == 2 && judgeboard17(x, y) == 2)
         y += 20;

	}
	if (GetAsyncKeyState('A') & 0x8000) {
		for (int i = 0; i < 4; i++) {
			transparentimage(NULL,x, y, &imageHeros2[i]);
			Sleep(100);
		}
		if(judgewallleft2(x)==2)
		x -= 20;
		if (GetAsyncKeyState('W') & 0x8000) {
			y -= 30;
		}

		
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000) {

		for (int i = 0; i < 4; i++) {
			transparentimage(NULL,b, n, &imageHeros3[i]);
			Sleep(70);
		}
		n -= 100;
		while (!judgeFloor(b, n)) {
			if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
				if (judgewallleft2(b) == 2)
				b -= 20;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				if (judgewallright2(b) == 2)
				b += 20;
			}
			if (judgebottom2(n) == 2 && judgeboard11(b, n) == 2 && judgeboard12(b, n) == 2 && judgeboard13(b, n) == 2 && judgeboard14(b, n) == 2 && judgeboard15(b, n) == 2 && judgeboard16(b, n) == 2 && judgeboard17(b, n) == 2)
			n += 15;
			else
				break;
			
			
			
			for (int i = 0; i < 4; i++) {
				transparentimage(NULL,b, n, &imageHeros3[i]);
				Sleep(10);

			}
			transparentimage(NULL,0, 0, &BK);
			transparentimage(NULL,x, y, &RedStand);
			if (b >= 700 || n >= 490)
				break;
		}

	}
	if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
int fb_time = 0;
		for (int i = 0; i < 4; i++) {
			transparentimage(NULL,b, n, &imageHeros3[i]);
			Sleep(70);
		}
		if (judgebottom2(n) == 2 && judgeboard11(b, n) == 2 && judgeboard12(b, n) == 2 && judgeboard13(b, n) == 2 && judgeboard14(b, n) == 2 && judgeboard15(b, n) == 2 && judgeboard16(b, n) == 2 && judgeboard17(b, n) == 2)
			n += 20;
		
		
		
	}
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		for (int i = 0; i < 9; i++) {
			transparentimage(NULL,b, n, &imageHeros4[i]);
			Sleep(70);
		}
		if (judgewallright2(b) == 2)
		b += 20;
		if (GetAsyncKeyState(VK_UP) & 0x8000)
			n -= 60;
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		for (int i = 0; i < 4; i++) {
			transparentimage(NULL,b, n, &imageHeros3[i]);
			Sleep(70);
		}
		if (judgewallleft2(b) == 2)
		b -= 20;
		if (GetAsyncKeyState(VK_UP) & 0x8000)
			n -= 60;
	}


	


}


void roleDrop(double y, double n) {

	while (judgebottom2(n) == 2 && judgeboard21(b, n) == 2 && judgeboard22(b, n) == 2 && judgeboard23(b, n) == 2 && judgeboard24(b, n) == 2) {
		y += 15;
		for (int i = 0; i < 7; i++) {
			putimage(x, y, &imageHeros1[i]);
			Sleep(10);
		}
	}
	while (!judgeFloor(b, n)) {
		n += 15;
		for (int i = 0; i < 4; i++) {
			putimage(x, y, &imageHeros4[i]);
			Sleep(10);
		}
	}
}


