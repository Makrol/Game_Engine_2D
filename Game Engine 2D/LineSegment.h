#pragma once
#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class LineSegment
{
public:

	LineSegment(Point2D first,Point2D second);

	Point2D getFirst();
	Point2D getSecond();

	void setFirst(Point2D point);
	void setSecond(Point2D point);
	void drawDefault(RenderWindow* window,Color color);
	void drawProgressive(RenderWindow* window,Color color, int thickness);
private:
	Point2D first;
	Point2D second;
	
};

