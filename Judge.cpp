
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<fstream>
#include<mmsystem.h>
#include <windows.h>   //  这个在graphics.h里面有..里面有静态库winmm.lib
#include <mmsystem.h>  //包含多媒体设备接口头文件
//加载静态库

#include"Rolecontrol.h"
#include"music.h"
#include"map_function.h"
#include"Gamemenu.h"
#include"Judge.h"

int judgefiredoor2(double X, double Y)
{
	if (X >= 120 && X <= 195 && Y <= 150 && Y >= 50)
		return 1;//位于火门
	else
		return 0;
}
//判断是否位于冰门
int judgeicedoor2(double X, double Y)
{
	if (X >= 20 && X <= 110 && Y <= 150 && Y >= 50)
		return 1;//位于冰门
	else
		return 0;
}
//判断是否位于冰面

void judgedoor2()
{
	if (judgefiredoor2(x, y) == 1 && judgeicedoor2(b, n) == 1)
		GameWin();

}
int judgeicefloor2(double X, double Y)
{
	if (X <= 310 && X >= 240 && Y >= 275 && Y <= 288)
		return 1;//位于冰面
	else
		return 0;
}
//判断是否位于火面
int judgefirefloor2(double X, double Y)
{
	if (X >= 255 && X <= 325 && Y >= 510 && Y <= 570)
		return 1;//位于火面
	else
		return 0;
}
//判断是否毒面
int judgepoisonfloor2(double X, double Y, double M, double N)
{
	if( (X >= 490 && X <= 545 && Y >= 575 && Y <= 588)|| (M >= 490 && M <= 545 && N >= 575 &&N <= 588))
		return 1;//位于毒面
	else
		return 0;
}

void judgefloor2()
{
	if (judgeicefloor2(x, y)==1 || judgefirefloor2(b, n)==1 )
	
	GameFall();
	


}



//2地图
//判断是否会板1(靠近门的)
int judgeboard21(double X, double Y)
{
	if ((X >= 25 && X <= 320 && Y >=82&&Y<=155) )
		return 1;//撞了
	else
		return 2;
}

int judgeboard22(double X, double Y)
{
	if ((X >= 380 && X <= 530 && Y >= 143&&Y<=215) )
		return 1;//撞了
	else
		return 2;
}
int judgeboard23(double X, double Y)
{
	if ((X >= 630 && X <= 745 && Y >= 215&&Y<=288))
		return 1;//撞了
	else
		return 2;
}
int judgeboard24(double X, double Y)
{
	if ((X >= 25 && X <= 335 && Y >= 270 && Y <= 350))
		return 1;//撞了
	else
		return 2;
}








//判断是否会撞左墙
int judgewallleft2(double X)
{
	if (X <= 25)
		return 1;//撞了
	else
		return 2;
}
//判断是否会撞右墙
int judgewallright2(double X)
{
	if (X >= 735)
		return 1;//撞了
	else
		return 2;
}
//判断是否在地面上
int judgebottom2( double N) {

	if ( N > 520)
		return 1;//到达地面
	else
		return 2;
}










//1   地图的判断函数如下
int judgefiredoor1(double X, double Y)
{
	if (X >= 26 && X <=86 && Y <= 167 && Y >= 103)
		return 1;//位于火门
	else
		return 0;
}
//判断是否位于冰门
int judgeicedoor1(double X, double Y)
{
	if (X >= 710 && X <= 750 && Y <= 167 && Y >= 103)
		return 1;//位于冰门
	else
		return 0;
}
//判断是否位于冰面

void judgedoor1()
{
	if (judgefiredoor1(x, y) == 1 && judgeicedoor1(b, n) == 1)
		GameWin();

}
int judgeicefloor11(double X, double Y)
{
	if (X <=145 && X >= 100 && Y >= 135 && Y <= 145)
		return 1;//位于冰面
	else
		return 0;
}
int judgeicefloor12(double X, double Y)
{
	if (X <= 608 && X >=555 && Y >= 230 && Y <= 250)
		return 1;//位于冰面
	else
		return 0;
}
int judgeicefloor13(double X, double Y)
{
	if (X <= 348 && X >= 263 && Y >= 530 && Y <= 555)
		return 1;//位于冰面
	else
		return 0;
}
//判断是否位于火面
int judgefirefloor11(double X, double Y)
{
	if (X >= 655 && X <= 705 && Y >= 135 && Y <= 145)
		return 1;//位于火面
	else
		return 0;
}
int judgefirefloor12(double X, double Y)
{
	if (X >= 202 && X <= 250 && Y >=230 && Y <= 250)
		return 1;//位于火面
	else
		return 0;
}
int judgefirefloor13(double X, double Y)
{
	if (X >= 473 && X <= 565&& Y >= 530 && Y <= 555)
		return 1;//位于火面
	else
		return 0;
}
//判断是否毒面
int judgepoisonfloor1(double X, double Y, double M, double N)
{
	if ((X >= 490 && X <= 545 && Y >= 575 && Y <= 588) || (M >= 490 && M <= 545 && N >= 575 && N <= 588))
		return 1;//位于毒面
	else
		return 0;
}

void judgefloor1()
{
	if (judgeicefloor11(x, y) == 1 || judgefirefloor11(b, n) == 1|| judgefirefloor12(b, n) == 1|| judgeicefloor12(x,y ) == 1 || judgefirefloor13(b, n) == 1|| judgeicefloor13(x, y) == 1)

		GameFall();



}



//1地图
//判断是否会板1
int judgeboard11(double X, double Y)
{
	if ((X >= 26 && X <= 167 && Y >= 131 && Y <= 160))
		return 1;//撞了
	else
		return 2;
}

int judgeboard12(double X, double Y)
{
	if ((X >= 623 && X <= 764 && Y >= 131 && Y <= 160))
		return 1;//撞了
	else
		return 2;
}
int judgeboard13(double X, double Y)
{
	if ((X >= 171 && X <= 621 && Y >= 232 && Y <= 261))
		return 1;//撞了
	else
		return 2;
}
int judgeboard14(double X, double Y)
{
	if ((X >= 26 && X <= 144 && Y >= 338 && Y <= 367))
		return 1;//撞了
	else
		return 2;
}
int judgeboard15(double X, double Y)
{
	if ((X >= 646 && X <= 764 && Y >= 346 && Y <= 375))
		return 1;//撞了
	else
		return 2;
}int judgeboard16(double X, double Y)
{
	if ((X >= 131&& X <= 274 && Y >= 431 && Y <= 460))
		return 1;//撞了
	else
		return 2;
}
int judgeboard17(double X, double Y)
{
	if ((X >= 509 && X <= 652 && Y >= 431 && Y <= 460))
		return 1;//撞了
	else
		return 2;
}









//判断是否会撞左墙
int judgewallleft1(double X)
{
	if (X <= 25)
		return 1;//撞了
	else
		return 2;
}
//判断是否会撞右墙
int judgewallright1(double X)
{
	if (X >= 735)
		return 1;//撞了
	else
		return 2;
}
//判断是否在地面上
int judgebottom1(double N) {

	if (N > 520)
		return 1;//到达地面
	else
		return 2;
}
int judgeboard111(double X, double Y)
{
	if ((X >= 26 && X <= 167 &&Y <= 167))
		return 1;//撞了
	else
		return 2;
}int judgeboard112(double X, double Y)
{
	if ((X >= 26 && X <= 167 &&  Y <= 167))
		return 1;//撞了
	else
		return 2;
}
int judgeboard113(double X, double Y)
{
	if ((X >= 26 && X <= 167 &&  Y <= 268))
		return 1;//撞了
	else
		return 2;
}
int judgeboard114(double X, double Y)
{
	if ((X >= 26 && X <= 167 && Y<=374))
		return 1;//撞了
	else
		return 2;
}
int judgeboard115(double X, double Y)
{
	if ((X >= 26 && X <= 167 && Y >= 131 && Y <= 160))
		return 1;//撞了
	else
		return 2;
}
int judgeboard116(double X, double Y)
{
	if ((X >= 26 && X <= 167 && Y >= 131 && Y <= 160))
		return 1;//撞了
	else
		return 2;
}
int judgeboard117(double X, double Y)
{
	if ((X >= 26 && X <= 167 && Y >= 131 && Y <= 160))
		return 1;//撞了
	else
		return 2;
}
