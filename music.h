#pragma once
#include <stdio.h>
#include <stdlib.h>
//����ͼ�ο�ͷ�ļ�
#include <string.h>
#include <conio.h>  //ʹ��getch()
#include <graphics.h>

//��������
#include <windows.h>   //  �����graphics.h������..�����о�̬��winmm.lib
#include <mmsystem.h>  //������ý���豸�ӿ�ͷ�ļ�
//���ؾ�̬��
#pragma comment(lib, "winmm.lib")
//���Ϳ���ʹ��mciSendString����������������
//��������1����
void musicplay_bgm1();
//������Ϸ��������2����
void musicplay_bgm2();
//����������Ч
void soundeffect_death();
//��Ϸʤ����Ч�����ŵ�ʱ��
void soundeffect_victory();
//��Ϸʧ����Ч����������ĺӵ�ʱ��
void soundeffect_fall();
//ʰȡ��ʯ����Ч
void soundeffect_gem();
