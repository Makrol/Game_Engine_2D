#include "Circle.h"

Circle::Circle(Point2D position, int xSize, Color border, Color fill, int thickness)
{
	this->position = position;
	this->xSize = xSize;
	this->ySize = xSize;
	this->border = border;
	this->fill = fill;
	this->thickness = thickness;
}

void Circle::draw(RenderWindow* window)
{
	PrimitiveRenderer::drawCircle(position,xSize,window,border,fill,thickness);
}

void Circle::translate(int x, int y)
{
	position.translate(x, y);
}

void Circle::rotate(int px, int py, int angle)
{
	position.rotate(px, py, angle);
}

void Circle::rotate(int angle)
{
	position.rotate(angle);
}

void Circle::scale(int px, int py, float kx, float ky)
{
	position.scale(px, py, kx, ky);
	xSize = xSize * kx;
	ySize = ySize * ky;
}

void Circle::scale(float kx, float ky)
{
	xSize = xSize * kx;
	ySize = ySize * ky;
}
