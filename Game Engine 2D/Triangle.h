#pragma once
#include "ShapeObject.h"
#include "PrimitiveRenderer.h"
class Triangle:public ShapeObject
{
public:
	Triangle(Point2D position, int Size, Color border, Color fill, int thickness);
	void draw(RenderWindow* window);
	void translate(int x, int y);
	void rotate(int px, int py, int angle);
	void rotate(int angle);
	void scale(int px, int py, float kx, float ky);
	void scale(float kx, float ky);
};

