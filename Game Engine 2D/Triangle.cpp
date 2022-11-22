#include "Triangle.h"



Triangle::Triangle(Point2D position, int xSize, Color border, Color fill, int thickness)
{
	this->position = position;
	this->xSize = xSize;
	this->ySize = ySize;
	this->border = border;
	this->fill = fill;
	this->thickness = thickness;
}

void Triangle::draw(RenderWindow* window)
{
    PrimitiveRenderer::drawTriangle(position, xSize, border, fill, window, thickness);
}

void Triangle::translate(int x, int y)
{

    position.translate(x, y);

}

void Triangle::rotate(int px, int py, int angle)
{
    position.rotate(px, py, angle);
}

void Triangle::rotate(int angle)
{
    position.rotate(angle);
}

void Triangle::scale(int px, int py, float kx, float ky)
{
    position.scale(px, py, kx, ky);
    xSize = xSize * kx;
    ySize = ySize * ky;
}

void Triangle::scale(float kx, float ky)
{
    xSize = xSize * kx;
    ySize = ySize * ky;
}

