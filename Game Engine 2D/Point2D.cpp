#include "Point2D.h"
#include <iostream>
Point2D::Point2D()
{
	x = 0;
	y = 0;
	color = Color::White;
	thickness = 1;
}

Point2D::Point2D(int x, int y)
{
	this->x = x;
	this->y = y;
	color = Color::White;
	thickness = 1;
}

Point2D::Point2D(int x, int y, Color color, int thickness)
{
	this->x = x;
	this->y = y;
	this->color = color;
	this->thickness = thickness;
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

int& Point2D::getXRef()
{
	return x;
}

int& Point2D::getYRef()
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

void Point2D::draw(RenderWindow *window)
{
	RectangleShape point;
	point.setPosition(x,y);
	point.setSize(Vector2f(thickness, thickness));
	point.setFillColor(color);
	window->draw(point);

}



void Point2D::swapPoints(Point2D& p1, Point2D& p2)
{
	Point2D tmp = p1;
	p1 = p2;
	p2 = tmp;
}

void Point2D::translate(int x, int y)
{
	this->x += x;
	this->y += y;
	TransformableObject::translate(this->x,this->y,x,y);
}

void Point2D::rotate(int px,int py, int angle)
{
	TransformableObject::rotate(x,y,px,py,angle);
}

void Point2D::rotate(int angle)
{
	TransformableObject::rotate(x, y, 0, 0, angle);
}

void Point2D::scale(int px, int py, float kx, float ky)
{
	x = (float)x * kx + (float)(1 - kx) * px;
	y = (float)y * ky + (float)(1 - ky) * py;
}

void Point2D::scale(float kx, float ky)
{
	x = (float)x * kx;
	y = (float)y * ky;
}

