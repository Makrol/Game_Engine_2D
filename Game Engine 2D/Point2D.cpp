#include "Point2D.h"

Point2D::Point2D()
{
	x = 0;
	y = 0;
}

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Point2D::~Point2D()
{
	
}

int Point2D::getX()
{
	return x;
}

int Point2D::getY()
{
	return y;
}

void Point2D::setX(int x)
{
	this->x = x;
}

void Point2D::setY(int y)
{
	this->y = y;
}

void Point2D::draw(RenderWindow *window,Color color)
{
	Vertex point(Vector2f(x, y), color);
	window->draw(&point, 1, Points);
	//PrimitiveRenderer::drawPiont(*window, x, y,color);
}

void Point2D::swapPoints(Point2D& p1, Point2D& p2)
{
	Point2D tmp = p1;
	p1 = p2;
	p2 = tmp;
}
