#pragma once
#include "ShapeObject.h"

#include "Point2D.h"

#include "PrimitiveRenderer.h"



class Rectangle:public ShapeObject
{
public:

	Rectangle(Point2D position, int xSize, int ySize, Color border, Color fill, int thickness);
	void draw(RenderWindow* window);
	void translate(int x, int y);
	void rotate(int px, int py, int angle);
	void rotate(int angle);
	void scale(int px, int py, float kx, float ky);
	void scale(float kx, float ky);

};

