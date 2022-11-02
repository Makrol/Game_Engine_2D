#include "PrimitiveRenderer.h"
#include <iostream>
void PrimitiveRenderer::drawLine(Point2D p1, Point2D p2, RenderWindow* window, Color color)
{
	double a = (double)(p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
	int deltaX = p1.getX() - p2.getX();
	int deltaY = p1.getY() - p2.getY();
	double startY;
	double startX;
	if (a >= -1 && a <= 1)
	{
		if (p1.getX() > p2.getX())
		{
			Point2D::swapPoints(p1, p2);
		}
		startY = p1.getY();
		double m = (double)deltaY / deltaX;
		for (int i = p1.getX();i <= p2.getX();i++)
		{
			Point2D(i, startY).draw(window,color);
			startY += m;
		}
	}
	else
	{
		if (p1.getY() > p2.getY())
		{
			Point2D::swapPoints(p1, p2);
		}
		startX = p1.getX();
		double m = (double)deltaX / deltaY;
		for (int i = p1.getY();i <= p2.getY();i++)
		{
			Point2D(startX, i).draw(window,color);
			startX += m;
		}
	}

	
}

void PrimitiveRenderer::drawRectangle(Point2D p1, int sizeX, int sizeY, Color color, RenderWindow* window)
{
	RectangleShape shape;
	shape.setPosition(p1.getX(), p1.getY());
	shape.setSize(Vector2f(sizeX, sizeY));
	shape.setOutlineThickness(1);
	shape.setFillColor(Color(0, 0, 0, 0));
	shape.setOutlineColor(color);
	window->draw(shape);
}
void PrimitiveRenderer::drawTriangle(Point2D p1, int size, Color color, RenderWindow* window)
{
	CircleShape circle(size,3);
	circle.setPosition(p1.getX(), p1.getY());
	circle.setFillColor(Color(0, 0, 0, 0));
	circle.setOutlineThickness(1);
	circle.setOutlineColor(color);
	window->draw(circle);
}


void PrimitiveRenderer::drawCircle(Point2D p1, int size, RenderWindow* window,Color color)
{
	CircleShape circle(size);
	circle.setPosition(p1.getX(), p1.getY());
	circle.setFillColor(Color(0, 0, 0, 0));
	circle.setOutlineThickness(1);
	circle.setOutlineColor(color);
	window->draw(circle);
}

void PrimitiveRenderer::drawPolygon(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window,bool isOpen)
{
	Vertex* points = new Vertex[pointsNumber+1];

	for (int i = 0;i < pointsNumber;i++)
	{
		points[i] = Vertex(Vector2f(pointTab[i].getX(), pointTab[i].getY()), color);
	}
	if (!isOpen)
	{
		points[pointsNumber] = points[0];
		window->draw(points, pointsNumber + 1, LinesStrip);
	}
	else
	{
		window->draw(points, pointsNumber, LinesStrip);
	}

	
	delete[] points;
}

