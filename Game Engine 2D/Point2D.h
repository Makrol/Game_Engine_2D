#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "TransformableObject.h"
#include "DrawableObject.h"
#include <cmath>


using namespace sf;

class Point2D: public DrawableObject,TransformableObject
{
private:
	int x;
	int y;
	Color color;
	int thickness;
public:
	Point2D();
	Point2D(int x,int y);
	Point2D(int x,int y,Color color,int thickness);
	~Point2D();
	int getX();
	int getY();

	int& getXRef();
	int& getYRef();

	void setX(int x);
	void setY(int y);
	void draw(RenderWindow *window);
	static void swapPoints(Point2D& p1, Point2D& p2);
	void translate(int x, int y);
	void rotate(int px, int py, int angle);
	void rotate(int angle);
	void scale(int px, int py, float kx, float ky);
	void scale(float kx, float ky);
};

