#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Point2D
{
private:
	int x;
	int y;
public:
	Point2D();
	Point2D(int x,int y);
	~Point2D();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	void draw(RenderWindow *window,Color color,int size);
	static void swapPoints(Point2D& p1, Point2D& p2);

};

