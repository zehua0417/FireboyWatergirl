#define _CRT_SECURE_NO_WARNINGS
#include<easyx.h>
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<mmsystem.h>
#include"music.h"
#include"map_function.h"
#include"Rolecontrol.h"
#include"Gamemenu.h"
#include"Gameresult.h"
#include"Judge.h"
#include <windows.h>   //  �����graphics.h������..�����о�̬��winmm.lib
#include <mmsystem.h>  //������ý���豸�ӿ�ͷ�ļ�
//���ؾ�̬��
#pragma comment(lib, "winmm.lib")
//while (1)
//{
//	MOUSEMSG m = GetMouseMsg();
//	switch (m.uMsg)
//	{
//	case WM_LBUTTON:
//	}
//}

//�������ֺ���
//mciSendString("ָ��", 0, 0, 0);
//ay:����
//open:��
//close���ر�
//pause����ͣ
//resume������
int bgm1 = 2;
int bgm2 = 2;
struct button
{
	int x;
	int y;
	int width;
	int height;
	COLORREF color;
	char* pText;
};
//��ʼ����ť������
struct button* createButton(int x, int y, int width, int height, COLORREF color, const char* pText)
{
	struct button* pB = (struct button*)malloc(sizeof(struct button));
	pB->x = x;
	pB->y = y;
	pB->width = width;
	pB->height = height;
	pB->color = color;
	pB->pText = (char*)malloc(strlen(pText) + 1);
	strcpy(pB->pText, pText);
	return pB;
}

//����ť
void drawButton(struct button* pB)
{
	setfillcolor(pB->color);
	settextstyle(35, 0, "����");
	setlinecolor(BLACK);
	setbkmode(TRANSPARENT);
	fillrectangle(pB->x, pB->y, pB->x + pB->width, pB->y + pB->height);
	outtextxy(pB->x + 20, pB->y + 10, pB->pText);
}
//�ж�����Ƿ��ڰ�ť��
int mouseInButton(struct button* pB, MOUSEMSG m)
{
	if (pB->x < m.x && m.x <= pB->x + pB->width && pB->y <= m.y && m.y <= pB->height + pB->y)
	{
		pB->color = RED;
		return 1;
	}
	pB->color = RGB(253, 208, 0);
	return 0;
}
//�ж���갴��
int clickButton(struct button* pB, MOUSEMSG m)
{
	if (mouseInButton(pB, m) && m.uMsg == WM_LBUTTONDOWN)
	{
		return 1;
	}
	return 0;
}
//��Ϸ˵������
int GameIntroduction()
{

	IMAGE introduction;

	loadimage(&introduction, "��Ļ��ͼ 2022-12-26 115456.PNG", 800, 600);
	struct button* back = createButton(0, 540, 200, 50, RGB(253, 208, 0), "���ز˵�");
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &introduction);
		drawButton(back);
		MOUSEMSG m = GetMouseMsg();
		if (clickButton(back, m))
		{
			cleardevice();
			return 0;
		}
		EndBatchDraw();
	}

}
//�Ŷӽ��ܺ���
int TeamIntroduction()
{

	IMAGE introduction;

	loadimage(&introduction, "��Ļ��ͼ 2022-12-26 172216.PNG", 800, 600);
	struct button* back = createButton(0, 540, 200, 50, RGB(253, 208, 0), "���ز˵�");
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &introduction);
		drawButton(back);
		MOUSEMSG m = GetMouseMsg();
		if (clickButton(back, m))
		{
			cleardevice();
			return 0;
		}
		EndBatchDraw();
	}

}
//�Ѷ�ѡ��
int levelChoose()
{
	int dif = 0;
	IMAGE introduction;

	loadimage(&introduction, "��Ļ��ͼ 2022-12-26 185454.PNG", 800, 600);
	struct button* back = createButton(0, 540, 200, 50, RGB(253, 208, 0), "���ز˵�");
	struct button* easy = createButton(300, 230, 200, 50, RGB(253, 208, 0), "��");
	struct button* complex = createButton(300, 430, 200, 50, RGB(253, 208, 0), "����");

	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &introduction);
		drawButton(back);
		drawButton(easy);
		drawButton(complex);
		MOUSEMSG m = GetMouseMsg();
		if (clickButton(back, m))
		{
			cleardevice();		
			return 0;
		}
		if (clickButton(easy, m))
		{
			cleardevice();
			load_diamond(1);			
			if (bgm1 % 2 == 0)
				musicplay_bgm1();
						
			while (1) {
				BeginBatchDraw();
				set_map(1);
				search_diamond(x,y,b,n);
				set_diamond();
				initGame();
				drawGame();
				controlGame1();
				judgedoor1();
				judgefloor1();
				
                 EndBatchDraw();
			}

			}

			
		
		if (clickButton(complex, m))
		{
			cleardevice();
			load_diamond(2);
			load_button(2);
			load_evt(2);
			while (1) {
				BeginBatchDraw();
				
				set_map(2);
				search_diamond(x, y, b, n);
				press_button(x, y, b, n);
				set_diamond();
				set_button();
				set_evt();
				initGame();
				drawGame();
				controlGame1();
				
				judgefloor2();
				judgedoor2();
				EndBatchDraw();
			}


		}
		
		EndBatchDraw();
	
	}
}

//��Ϸ���ú���
int Gameadjust()
{
	IMAGE bkp;
	initgraph(800, 600);//��������
	loadimage(&bkp, "bkp.jpg", 800, 600);
	struct button* back = createButton(0, 540, 200, 50, RGB(253, 208, 0), "���ز˵�");
	struct button* musicbk = createButton(300, 285, 200, 50, RGB(253, 208, 0), "��������");
	struct button* musiceffect = createButton(300, 340, 200, 50, RGB(253, 208, 0), "��Ϸ��Ч");
	
	while (1)
	{
		BeginBatchDraw();
		putimage(0, 0, &bkp);
		drawButton(back);

		drawButton(musicbk);
		drawButton(musiceffect);
		MOUSEMSG m = GetMouseMsg();
		if (clickButton(back, m))
		{
			cleardevice();
			return 0;
		}
		if (clickButton(musicbk, m))
		{
			 cleardevice();
			 bgm1++;
		}
		if (clickButton(musiceffect, m))
		{
			cleardevice();
			bgm2++;
		}
		EndBatchDraw();
	}

}



		void GameMainMenu()
		{
			const int width = 800;
			const int hight = 600;
			IMAGE Menu;

			initgraph(width, hight);//��������
			loadimage(&Menu, "gamemenu.jpg", 800, 600);
			struct button* begin = createButton(300, 230, 200, 50, RGB(253, 208, 0), "��ʼ��Ϸ");
			struct button* introduction = createButton(300, 285, 200, 50, RGB(253, 208, 0), "��Ϸ˵��");
			struct button* adjustment = createButton(300, 340, 200, 50, RGB(253, 208, 0), "��Ϸ����");
			struct button* team = createButton(300, 395, 200, 50, RGB(253, 208, 0), "�Ŷӽ���");

			while (1)
			{
				BeginBatchDraw();
				putimage(0, 0, &Menu);
				drawButton(begin);
				drawButton(introduction);
				drawButton(adjustment);
				drawButton(team);
				MOUSEMSG m = GetMouseMsg();
				if (clickButton(begin, m))
				{
					cleardevice();
					levelChoose();
				}

				if (clickButton(introduction, m))
				{
					cleardevice();
					GameIntroduction();
				}

				if (clickButton(adjustment, m))
				{
					cleardevice();

					Gameadjust();
				}
				if (clickButton(team, m))
				{
					cleardevice();
					TeamIntroduction();
				}


				EndBatchDraw();

			}
		}

		void  GameWin()
		{
		if(bgm2%2==0)
			soundeffect_victory();
			const int width = 800;
			const int hight = 600;
			IMAGE result;
			loadimage(&result, "11.jpeg", 800, 600);
			struct button* back = createButton(0, 540, 200, 50, RGB(253, 208, 0), "���ز˵�");

			while (1)
			{
				BeginBatchDraw();
				putimage(0, 0, &result);
				settextcolor(YELLOW);
				setbkmode(YELLOW);
				settextstyle(70, 40, "����");
				outtextxy(240, 200, "��Ϸʤ��");
				drawButton(back);
				MOUSEMSG m = GetMouseMsg();
				if (clickButton(back, m))
				{
					cleardevice();
					 x = 25, y = 545;
					 b = 132, n = 545;
					free_diamond();
					GameMainMenu();
				}


				EndBatchDraw();
			}

		}
		void GameFall()
		{  if(bgm2%2==0)
			soundeffect_fall();
			const int width = 800;
			const int hight = 600;
			IMAGE result;

			


			loadimage(&result, "11.jpeg", 800, 600);
			struct button* back = createButton(0, 540, 200, 50, RGB(253, 208, 0), "���ز˵�");

			while (1)
			{
				BeginBatchDraw();
				putimage(0, 0, &result);
				settextcolor(GREEN);
				setbkmode(YELLOW);
				settextstyle(70, 40, "����");
				outtextxy(240, 200, "��Ϸʧ��");
				drawButton(back);
				MOUSEMSG m = GetMouseMsg();
				if (clickButton(back, m))
				{
					cleardevice();
					 x = 25, y = 545;
					 b = 132, n = 545;
					free_diamond();
					GameMainMenu();
				
				}

				EndBatchDraw();
			}

		}



		


int main()
{
	GameMainMenu();


	_getch();
	closegraph();


	return 0;
}
