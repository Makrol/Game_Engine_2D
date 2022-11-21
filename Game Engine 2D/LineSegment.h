#pragma once
#include "PrimitiveRenderer.h"
#include <SFML/Graphics.hpp>
#include "DrawableObject.h"
#include "TransformableObject.h"
using namespace sf;

class LineSegment: public TransformableObject
{
public:

	LineSegment(Point2D first,Point2D second);

	Point2D getFirst();
	Point2D getSecond();

	void setFirst(Point2D point);
	void setSecond(Point2D point);
	void drawDefault(RenderWindow* window,Color color);
	void draw(RenderWindow* window,Color color, int thickness);


	void translate(int x, int y);
	void rotate(int px, int py, int angle);
	void rotate(int angle);
	void scale(int px, int py, float kx, float ky);
	void scale(float kx, float ky);
private:
	Point2D first;
	Point2D second;
	
};

