#pragma once
#include "DrawableObject.h"
#include "TransformableObject.h"
#include "Point2D.h"
class ShapeObject: public DrawableObject,TransformableObject
{
protected:
	Point2D position;
	int xSize;
	int ySize;
	Color border;
	Color fill;
	int thickness;
public:
	virtual void draw(RenderWindow* window)=0;
	virtual void translate(int x, int y) = 0;
	virtual void rotate(int px, int py, int angle) = 0;
	virtual void rotate(int angle) = 0;
	virtual void scale(int px, int py, float kx, float ky) = 0;
	virtual void scale(float kx, float ky) = 0;
};

