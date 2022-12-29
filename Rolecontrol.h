#pragma once
#include<graphics.h>
#include<stdio.h>
#include<windows.h>
extern double x;
extern double y ;
extern double b ;
extern double n ;
void initGame();
int judgeicefloor(double X, double Y);
int judgefirefloor(double X, double Y);
int judgepoisonfloor(double X, double Y);
void drawGame();
int judgeFloor(double x, double y);
void changePlusSpeed(double& ay);
void controlGame1();
void roleDrop(double y, double n);
