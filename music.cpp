
#include <stdio.h>
#include <stdlib.h>
//����ͼ�ο�ͷ�ļ�
#include <string.h>
#include <conio.h>  //ʹ��getch()
#include <graphics.h>

#include"music.h"
//��������
#include <windows.h>   //  �����graphics.h������..�����о�̬��winmm.lib
#include <mmsystem.h>  //������ý���豸�ӿ�ͷ�ļ�
//���ؾ�̬��
#pragma comment(lib, "winmm.lib")
//���Ϳ���ʹ��mciSendString����������������
void musicplay_bgm1() //������Ϸ�������ֺ���
{

	mciSendString("open ��������1.mp3", 0, 0, 0);
	mciSendString("play ��������1.mp3 repeat", 0, 0, 0);
}
void musicplay_bgm2() //������Ϸ�������ֺ���
{

	mciSendString("open ��������2.mp3", 0, 0, 0);
	mciSendString("play ��������2.mp3 repeat", 0, 0, 0);
}
void soundeffect_death()
{
	mciSendString("open ����.mp3", 0, 0, 0);
	mciSendString("play ����.mp3", 0, 0, 0);
}
void soundeffect_victory()
{
	mciSendString("open ʤ��.mp3", 0, 0, 0);
	mciSendString("play ʤ��.mp3", 0, 0, 0);
}
void soundeffect_fall()
{
	mciSendString("open ʧ��.mp3", 0, 0, 0);
	mciSendString("play ʧ��.mp3", 0, 0, 0);
}

void soundeffect_gem()
{
	mciSendString("open �񵽱�ʯ.mp3", 0, 0, 0);
	mciSendString("play �񵽱�ʯ.mp3 ", 0, 0, 0);
}
