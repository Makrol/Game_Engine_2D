#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
class TransformableObject
{
public:
	static void translate(int& x, int& y, int xm, int ym);
	static void rotate(int &x,int &y,int px, int py, int angle);
	static void scale(int& x, int& y, int px, int py, float kx, float ky);
	virtual void translate(int x,int y)=0;
	virtual void rotate(int px,int py,int angle)=0;
	virtual void rotate(int angle)=0;
	virtual void scale(int px, int py,float kx,float ky)=0;
	virtual void scale(float kx,float ky)=0;
};

