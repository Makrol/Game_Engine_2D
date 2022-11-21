#include "Rectangle.h"



Rectangle::Rectangle(Point2D position, int xSize, int ySize, Color border, Color fill, int thickness)
{
	this->position = position;
	this->xSize = xSize;
	this->ySize = ySize;
	this->border = border;
	this->fill = fill;
	this->thickness = thickness;
}

void Rectangle::draw(RenderWindow* window)
{
	PrimitiveRenderer::drawRectangle(position, xSize, ySize, border, fill, window, thickness);
}

void Rectangle::translate(int x, int y)
{

	
	position.translate(x, y);

}

void Rectangle::rotate(int px, int py, int angle)
{
	position.rotate(px, py, angle);
}

void Rectangle::rotate(int angle)
{
	position.rotate(angle);
}

void Rectangle::scale(int px, int py, float kx, float ky)
{
	position.scale(px, py, kx, ky);
	xSize = xSize * kx;
	ySize = ySize * ky;
}

void Rectangle::scale(float kx, float ky)
{
	xSize = xSize * kx;
	ySize = ySize * ky;
}

