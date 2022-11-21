#include "Circle.h"

Circle::Circle(Point2D position, int Size, Color border, Color fill, int thickness)
{
	this->position = position;
	this->xSize = Size;
	this->ySize = Size;
	this->border = border;
	this->fill = fill;
	this->thickness = thickness;
}

void Circle::draw(RenderWindow* window)
{
	PrimitiveRenderer::drawCircle(position, xSize, window, border, fill, thickness);
}

void Circle::translate(int x, int y)
{
}

void Circle::rotate(int px, int py, int angle)
{
}

void Circle::rotate(int angle)
{
}

void Circle::scale(int px, int py, float kx, float ky)
{
}

void Circle::scale(float kx, float ky)
{
}
