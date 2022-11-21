#include "Triangle.h"

Triangle::Triangle(Point2D position, int Size, Color border, Color fill, int thickness)
{
	this->position = position;
	this->xSize = Size;
	this->ySize = Size;
	this->border = border;
	this->fill = fill;
	this->thickness = thickness;
}

void Triangle::draw(RenderWindow* window)
{
	PrimitiveRenderer::drawTriangle(position,xSize,border,fill,window,thickness);
}

void Triangle::translate(int x, int y)
{
}

void Triangle::rotate(int px, int py, int angle)
{
}

void Triangle::rotate(int angle)
{
}

void Triangle::scale(int px, int py, float kx, float ky)
{
}

void Triangle::scale(float kx, float ky)
{
}
