#pragma once
#define _USE_MATH_DEFINES
#include <SFML/Graphics.hpp>
#include "Point2D.h"
#include <stack>
using namespace sf;

class PrimitiveRenderer
{
private:
	static bool isColision(Point2D &p1, Point2D& p2, Point2D& p3, Point2D& p4);
public:
	static void drawLine(Point2D p1, Point2D p2, RenderWindow* window,Color color,int thickness);
	static void drawRectangle(Point2D p1, int sizeX, int sizeY, Color border, Color fill,RenderWindow* window,int thickness);
	static void drawTriangle(Point2D p1, int size, Color border, Color fill,RenderWindow* window,int thickness);
	static void drawCircle(Point2D p1, int size,RenderWindow* window, Color border, Color fill,int thickness);
	static void drawPolygon(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window,int thickness);
	static void drawCircle8Symmetry(Point2D p1, int radius,RenderWindow *window,Color color,int thickness);
	static void drawEllipse4Symmetry(Point2D p1, int radiusX,int radiusY,RenderWindow *window,Color color,int thickness);
	static void drawBrokenLine(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window,bool isOpen,int thickness);
	static void floodFill(Point2D start, Color filColor, RenderWindow* window);
	static void boundryFill(Point2D start, Color filColor, Color borderColor, RenderWindow* window);
};

