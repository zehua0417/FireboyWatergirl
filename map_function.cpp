
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <easyx.h>
#include <conio.h>
#include <math.h>
#include "map_function.h"
#pragma comment(lib, "MSIMG32.LIB")

#define WIDTH 800
#define HEIGHT 600
#define DIAWIDTH 50
#define DIAHEIGHT 50
#define EVTWIDTH 50
#define EVTHEIGHT 10
#define NUM_evt 10
#define EVT_V 10

/**
 * @brief 图宝石链表节点(各难度设置一个文件)
 */
struct diamond
{
	int type; // 1->蓝宝石, 2->红宝石, 3->绿宝石
	int x;	  // 横坐标
	int y;	  // 宝石的纵坐标
	int n;	  // 宝石编号,便于修改删除
	struct diamond* next;
};

struct diamond* head = NULL;
struct diamond* end = head;

/**
 * @brief 电梯结构体
 */
struct evt
{
	int x;			 // 横坐标
	int y;			 // 纵坐标
	double distance; // 可以滑行的距离
	double dis_now;	 // 电梯此时的位置(相对起点的距离)<=distance
	int type;		 // 运动类型: 1,上->下; 2,下->上; 3,左->右; 4,右->左
	// double distance; // 可以滑行的距离
// double dis_now;  // 电梯此时的位置(相对起点的距离)<=distance
};

struct evt evt_data[NUM_evt] = { 0 }; // 设置电梯结构体数组, 每个关卡一个

/**
 * @brief 按钮结构体
 */
struct button
{
	int x;		// 横坐标
	int y;		// 纵坐标
	int n;		// 对应按钮编号
	int status_1; // 状态即被按下的深度
	int status_2; // 状态即被按下的深度
};

struct button button_data[NUM_evt] = { 0 }; // 设置按钮结构体数组, 每个关卡一个

//=====================================================================================
//=====================================================================================
//=====================================================================================

void transparentimage(IMAGE* dstimg, int x, int y, IMAGE* srcimg) // 新版png
{
	HDC dstDC = GetImageHDC(dstimg);
	HDC srcDC = GetImageHDC(srcimg);
	int w = srcimg->getwidth();
	int h = srcimg->getheight();
	BLENDFUNCTION bf = { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
	AlphaBlend(dstDC, x, y, w, h, srcDC, 0, 0, w, h, bf);
}

void test()
{
	initgraph(WIDTH, HEIGHT);
	BeginBatchDraw();
	cleardevice();
	set_map(2);
	load_diamond(2);
	load_button(2);
	load_evt(2);
	search_diamond(270, 535, 0, 0);
	// del_diamond(search_diamond(150,150));
	set_diamond();
	press_button(400, 560, 410, 175);
	set_button();
	set_evt();
	FlushBatchDraw();
	_getch();
}


void set_map(int dif)
{
	IMAGE map;
	switch (dif)
	{
	case 1:
		loadimage(&map, _T("./image/lowlevel_map.jpg"), WIDTH, HEIGHT);
		break;
	case 2:
		loadimage(&map, _T("./image/highlevel_map.jpg"), WIDTH, HEIGHT);
		break;
	}
	putimage(0, 0, &map);
}

//================================================================================

void init_diamondlist()
{
	head = (struct diamond*)malloc(sizeof(struct diamond));
	head->next = NULL;
	end = head;
}

void load_diamond(int dif)
{
	init_diamondlist();

	FILE* fp = NULL;
	switch (dif)
	{
	case 1:
		fp = fopen(".\\data\\lowlevel_diamond.txt", "r");
		break;
	case 2:
		fp = fopen("./data/highlevel_diamond.txt", "r");
		break;
	}
	if (fp == NULL)
		return;
	struct diamond* ptr = (struct diamond*)malloc(sizeof(struct diamond));
	ptr->next = NULL;
	while (~fscanf(fp, "%2d%4d%4d%2d\n", &ptr->type, &ptr->x, &ptr->y, &ptr->n))
	{
		if (head->next == NULL)
		{
			head->next = ptr;
			end = ptr;
		}
		else
		{
			end->next = ptr;
			end = ptr;
		}
		ptr = (struct diamond*)malloc(sizeof(struct diamond));
		ptr->next = NULL;
	}
	free(ptr);
	fclose(fp);
}

struct diamond* del_diamond(int n)
{
	struct diamond* pre = head;
	while (20030417)
	{
		if (pre->next && (pre->next->n == n))
		{
			struct diamond* q = pre->next;
			pre->next = pre->next->next;
			free(q);
			return pre->next;
		}
		else
		{
			if (pre->next != NULL)
				pre = pre->next;
			else
				return NULL;
		}
	}
}

void search_diamond(double fx, double fy, double wx, double wy)
{
	struct diamond* find = head->next;
	while (20030417)
	{
		while (find)
		{
			switch (find->type)
			{
			case 1:
				if ((fabs(find->x - wx) <= 20 && fabs(find->y - wy) <= 20))
					find = del_diamond(find->n);
				break;
			case 2:
				if ((fabs(find->x - fx) <=20 && fabs(find->y - fy) <= 20))
					find = del_diamond(find->n);
				break;
			}
			if (find != NULL && find->next != NULL)
			{
				find = find->next;
			}
			else
			{
				return;
			}
		}
	}
}


void set_diamond()
{
	struct diamond* p = head->next;
	while (p != NULL)
	{
		IMAGE diamage;
		int type = p->type;

		switch (p->type)
		{
		case 1:
			loadimage(&diamage, _T("./image/bluediamond.png"), DIAWIDTH, DIAHEIGHT);
			break;
		case 2:
			loadimage(&diamage, _T("./image/reddiamond.png"), DIAWIDTH, DIAHEIGHT);
			break;
		case 3:
			loadimage(&diamage, _T("./image/greendiamond.png"), DIAWIDTH, DIAHEIGHT);
			break;
		}
		transparentimage(NULL, p->x, p->y, &diamage);

		p = p->next;
	}
}

void free_diamond()
{
	if (head == NULL)
		return;
	struct diamond* ptr = head->next;
	struct diamond* pdel = NULL;
	while (ptr != NULL)
	{
		pdel = ptr->next;
		free(ptr);
		ptr = pdel;
	}
	head->next = NULL;
}
//===================================================================================`

// void init_evt()
//{
//     struct
// }

void load_evt(int dif)
{
	FILE* fp = NULL;
	switch (dif)
	{
	case 1:
		fp = fopen("./data/lowlevel_evt.txt", "a+");
		break;
	case 2:
		fp = fopen("./data/highlevel_evt.txt", "a+");
		break;
	}
	if (fp == NULL)
	{
		return;
	}
	int i = 0;
	while (~fscanf(fp, "%4d%4d%2d%4lf%4lf\n",
		&evt_data[i].x, &evt_data[i].y,
		&evt_data[i].type, &evt_data[i].distance, &evt_data[i].dis_now))
	{
		i++;
	}
	fclose(fp);
}

void set_evt()
{
	IMAGE evtimage;
	loadimage(&evtimage, _T("./image/evt.png"), EVTWIDTH, EVTHEIGHT);
	int x = 0, y = 0;
	for (int i = 0; evt_data[i].type != 0; i++)
	{
		switch (evt_data[i].type)
		{
		case 1:
			x = evt_data[i].x;
			y = evt_data[i].y + evt_data[i].dis_now;
			break;
		case 2:
			x = evt_data[i].x;
			y = evt_data[i].y - evt_data[i].dis_now;
			break;
		case 3:
			x = evt_data[i].x + evt_data[i].dis_now;
			y = evt_data[i].y;
			break;
		case 4:
			x = evt_data[i].x - evt_data[i].dis_now;
			y = evt_data[i].y;
			break;
		}
		transparentimage(NULL, x, y, &evtimage);
	}
}

//===============================================================================

void load_button(int dif)
{
	FILE* fp = NULL;
	switch (dif)
	{
	case 1:
		fp = fopen("./data/lowlevel_button.txt", "a+");
		break;
	case 2:
		fp = fopen("./data/highlevel_button.txt", "a+");
		break;
	}
	int i = 0;
	if (fp == NULL)
	{
		return;
	}
	while (~fscanf(fp, "%4d%4d%2d%3d\n",
		&button_data[i].x, &button_data[i].y, &button_data[i].n, &button_data[i].status_1))
	{
		button_data[i].status_2 = button_data[i].status_1;
		i++;
	}
	fclose(fp);
}

void press_button(double fx, double fy, double wx, double wy)
{
	double temp_x = fx, temp_y = fy;
	for (int i = 0; i < 2; i++)
	{
		if (fabs(temp_x - button_data[i].x) <40 && fabs(temp_y - button_data[i].y) < 40)
		{
			button_data[i].status_1 = 0;
		}
		else if (button_data[i].status_1 == 0)
		{
			button_data[i].status_1 = 1;
		}
	}
	temp_x = wx;
	temp_y = wy;
	for (int i = 0; i < 2; i++)
	{
		if (fabs(temp_x - button_data[i].x) < 20 && fabs(temp_y - button_data[i].y) < 20)
		{
			button_data[i].status_2 = 0;
		}
		else if (button_data[i].status_2 == 0)
		{
			button_data[i].status_2 = 1;
		}
	}


}

void set_button()
{
	IMAGE buttonimage;
	for (int i = 0; button_data[i].n != 0; i++)
	{
		if (button_data[i].status_1 == 1 && button_data[i].status_2 == 1)
		{
			loadimage(&buttonimage, _T("./image/button.jpg"), 30, 15);
			transparentimage(NULL, button_data[i].x, button_data[i].y, &buttonimage);
			evt_data[button_data[i].n - 1].dis_now = 0;
		}
		else
		{
			if (evt_data[button_data[i].n - 1].dis_now < evt_data[button_data[i].n - 1].distance)
			{
				if (evt_data[button_data[i].n - 1].dis_now + EVT_V < evt_data[button_data[i].n - 1].distance)
				{
					evt_data[(button_data[i].n) - 1].dis_now += EVT_V;
				}
				else
					evt_data[button_data[i].n - 1].dis_now = evt_data[button_data[i].n - 1].distance;
			}

		}
	}
}
