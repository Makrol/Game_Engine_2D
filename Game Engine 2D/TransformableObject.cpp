#include "TransformableObject.h"

void TransformableObject::translate(int& x, int& y, int xm, int ym)
{
	x += xm;
	y += ym;
}

void TransformableObject::rotate(int& x, int& y, int px, int py, int angle)
{
	double newAngle = ((double)angle * 2 * M_PI) / (double)360;
	int newx = px + (double)(x - px) * cos(newAngle) - (double)(y - py) * sin(newAngle);
	int newy = py + (double)(x - px) * sin(newAngle) + (double)(y - py) * cos(newAngle);
	x = newx;
	y = newy;
}

void TransformableObject::scale(int& x, int& y, int px, int py, float kx, float ky)
{
	x = (float)x * kx + (float)(1 - kx) * px;
	y = (float)y * ky + (float)(1 - ky) * py;
}
