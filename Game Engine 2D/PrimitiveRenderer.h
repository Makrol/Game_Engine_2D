#pragma once
#include <SFML/Graphics.hpp>
#include "Point2D.h"
//#include <cmath>
using namespace sf;

class PrimitiveRenderer
{
public:
	static void drawLine(Point2D p1, Point2D p2, RenderWindow* window,Color color);
	static void drawRectangle(Point2D p1, int sizeX, int sizeY,Color color,RenderWindow* window);
	static void drawTriangle(Point2D p1, int size,Color color,RenderWindow* window);
	static void drawCircle(Point2D p1, int size,RenderWindow* window,Color color);
	static void drawPolygon(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window,bool isOpen);
};

