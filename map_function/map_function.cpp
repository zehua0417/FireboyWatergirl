// #undef UNICODE
// #undef _UNICODE
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
#define BUTTONWIDTH 25
#define BUTTONHEIGHT 15


/**
 * @brief 图宝石链表节点(各难度设置一个文件)
 */
struct diamond
{
	int type; // 1->蓝宝石, 2->红宝石, 3->绿宝石
	int x;  // 宝石的横坐标
	int y;  // 宝石的纵坐标
	int n;    // 宝石编号,便于修改删除
	struct diamond* next;
};

struct diamond* head =NULL;
struct diamond* end = head;

/**
 * @brief 电梯结构体
 */
struct evt
{
	int x;           // 横坐标
	int y;           // 纵坐标
	double distance; // 可以滑行的距离
	double dis_now;  // 电梯此时的位置(相对起点的距离)<=distance
	int n;           // 电梯编号,便于和按钮对应
	int type;        // 运动类型: 1,上->下; 2,下->上; 3,左->右; 4,右->左
	//double distance; // 可以滑行的距离
	//double dis_now;  // 电梯此时的位置(相对起点的距离)<=distance
};

struct evt evt_data[NUM_evt] = { 0 }; // 设置电梯结构体数组, 每个关卡一个

/**
 * @brief 按钮结构体
 */
struct button
{
	int x;         // 横坐标
	int y;         // 纵坐标
	int n;         // 编号
	int status; // 状态即被按下的深度
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
	 set_map(1);
	load_diamond(1);
	del_diamond(search_diamond(150,150));
	set_diamond();
	load_evt(1);
	set_evt();
	FlushBatchDraw();
	_getch();
}

int main(void)
{
	test();
	return 0;
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
		loadimage(&map, _T("./image/hightlevel_map.jpg"), WIDTH, HEIGHT);
		break;
	}
	putimage(0, 0, &map);
}

//================================================================================

void init_diamondlist()
{
	head=(struct diamond*)malloc(sizeof(struct diamond));
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

void del_diamond(int n)
{
	struct diamond* pre = head;
	while (20030417)
	{
		if (pre->next && (pre->next->n == n))
		{
			struct diamond* q = pre->next;
			pre->next = pre->next->next;
			free(q);
			return;
		}
		else
		{
			if (pre->next != NULL)
				pre = pre->next;
			else
				return;
		}
	}
}

int search_diamond(double x, double y)
{
	while (20030417)
	{
		struct diamond* find = head->next;
		while (find && !(fabs(find->x - x) <= 3 && fabs(find->y - y) <= 3))
			find = find->next;
		if (find)
		{
			return find->n;
		}
		return 0;
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
		transparentimage(NULL,p->x, p->y, &diamage);

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
	while (~fscanf(fp, "%4d%4d%2d%2d%4lf%4lf\n",
		&evt_data[i].x, &evt_data[i].y, &evt_data[i].n,
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
	for (int i = 0; evt_data[i].n != 0; i++)
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
		&button_data[i].x, &button_data[i].y, &button_data[i].n, &button_data[i].status))
	{
		i++;
	}
	fclose(fp);
}

void set_button()
{
	IMAGE buttonimage;
	int x = 0, y = 0;
	for (int i = 0; button_data[i].n != 0; i++)
	{
		switch (button_data[i].status)
		{
		case 0:
			return;
		case 1:
			loadimage(&buttonimage, _T("./image/buttonimage.png", BUTTONWIDTH, BUTTONHEIGHT));
			transparentimage(NULL, x, y, &buttonimage);
		}
	}
}
