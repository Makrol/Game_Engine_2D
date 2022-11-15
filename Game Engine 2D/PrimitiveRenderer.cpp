#include "PrimitiveRenderer.h"
#include <iostream>
bool PrimitiveRenderer::isColision(Point2D& p1, Point2D& p2, Point2D& p3, Point2D& p4)
{
	long s1 = p1.getX() * p3.getY() + p3.getX() * p4.getY() + p4.getX() * p1.getY() - p3.getY() * p4.getX() - p4.getY() * p1.getX() - p1.getY() * p3.getX();
	long s2 = p2.getX() * p3.getY() + p3.getX() * p4.getY() + p4.getX() * p2.getY() - p3.getY() * p4.getX() - p4.getY() * p2.getX() - p2.getY() * p3.getX();
	long s3 = p3.getX() * p1.getY() + p1.getX() * p2.getY() + p2.getX() * p3.getY() - p1.getY() * p2.getX() - p2.getY() * p3.getX() - p3.getY() * p1.getX();
	long s4 = p4.getX() * p1.getY() + p1.getX() * p2.getY() + p2.getX() * p4.getY() - p1.getY() * p2.getX() - p2.getY() * p4.getX() - p4.getY() * p1.getX();

	if ((s1 < 0 && s2>0 && s3 > 0 && s4 < 0) || (s1 > 0 && s2 < 0 && s3 < 0 && s4 > 0))
		return true;
	return false;
}
void PrimitiveRenderer::drawLine(Point2D p1, Point2D p2, RenderWindow* window, Color color,int thickness)
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
			Point2D(i, startY).draw(window,color, thickness);
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
			Point2D(startX, i).draw(window,color, thickness);
			startX += m;
		}
	}

	
}

void PrimitiveRenderer::drawRectangle(Point2D p1, int sizeX, int sizeY, Color border,Color fill, RenderWindow* window,int thickness)
{
	RectangleShape shape;
	shape.setPosition(p1.getX(), p1.getY());
	shape.setSize(Vector2f(sizeX, sizeY));
	shape.setOutlineThickness(thickness);
	shape.setFillColor(fill);
	shape.setOutlineColor(border);
	window->draw(shape);
}
void PrimitiveRenderer::drawTriangle(Point2D p1, int size, Color border, Color fill, RenderWindow* window,int thickness)
{
	CircleShape circle(size,3);
	circle.setPosition(p1.getX(), p1.getY());
	circle.setFillColor(fill);
	circle.setOutlineThickness(thickness);
	circle.setOutlineColor(border);
	window->draw(circle);
}


void PrimitiveRenderer::drawCircle(Point2D p1, int size, RenderWindow* window, Color border, Color fill, int thickness)
{
	CircleShape circle(size);
	circle.setPosition(p1.getX(), p1.getY());
	circle.setFillColor(fill);
	circle.setOutlineThickness(thickness);
	circle.setOutlineColor(border);
	window->draw(circle);
}

void PrimitiveRenderer::drawPolygon(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window,int thickness)
{
	for (int i = 0;i <= pointsNumber;i++)
	{
		if (i > 1)
		{
			int j = 0;
			while ((j+1) < i)
			{
				if (isColision(pointTab[j], pointTab[j + 1], pointTab[i - 1], pointTab[i]))
					return;
				j++;
			}
		}
	}
	PrimitiveRenderer::drawBrokenLine(pointTab, color, pointsNumber, window,false, thickness);
}

void PrimitiveRenderer::drawCircle8Symmetry(Point2D p1, int radius,RenderWindow *window,Color color,int thickness)
{
	int x, y;
	int xSym, ySym;
	int xAbs, yAbs;
	if (radius <= 0)
		return;
	float step = (float)1 / radius;
	for (float i = 0;i < M_PI_4;i += step)
	{
		x = p1.getX() + radius * cos(i) + 0.5;
		y = p1.getY() + radius * sin(i) + 0.5;
		xAbs = abs(p1.getX() - x);
		yAbs = abs(p1.getY() - y);
		xSym = x - (xAbs + xAbs);
		ySym = y - (yAbs + yAbs);

		Point2D(x,y).draw(window,color,thickness);
		Point2D(x,ySym).draw(window,color,thickness);
		Point2D(xSym, y).draw(window,color, thickness);
		Point2D(xSym, ySym).draw(window,color, thickness);
		Point2D(p1.getX()+ yAbs, p1.getY()+ xAbs).draw(window,color,thickness);
		Point2D(p1.getX()+ yAbs, p1.getY()- xAbs).draw(window,color,thickness);
		Point2D(p1.getX()- yAbs, p1.getY()- xAbs).draw(window,color,thickness);
		Point2D(p1.getX()- yAbs, p1.getY()+ xAbs).draw(window,color,thickness);
		
	}
}

void PrimitiveRenderer::drawEllipse4Symmetry(Point2D p1, int radiusX, int radiusY, RenderWindow* window, Color color, int thickness)
{
	int x, y;
	int xSym, ySym;
	int xAbs, yAbs;
	if (radiusX <= 0 || radiusY <0)
		return;
	float stepY = (float)1 / radiusY;
	float stepX = (float)1 / radiusX;
	float step=stepY;

	if (radiusX * radiusX * (p1.getX() + radiusX * cos(0) + 0.5) > radiusY * radiusY * (p1.getY() + radiusY * sin(0) + 0.5))
		step = stepX;
	else
		step = stepY;

	float i = 0;
	while(i<M_PI_2)
	{
		x = p1.getX() + radiusX * cos(i) + 0.5;
		y = p1.getY() + radiusY * sin(i) + 0.5;

		if (radiusX * radiusX * x > radiusY * radiusY * y)
			i += stepX;
		else
			i += stepY;

		xAbs = abs(p1.getX() - x);
		yAbs = abs(p1.getY() - y);
		xSym = x - (xAbs + xAbs);
		ySym = y - (yAbs + yAbs);

		Point2D(x, y).draw(window, color, thickness);
		Point2D(x, ySym).draw(window, color, thickness);
		Point2D(xSym, y).draw(window, color, thickness);
		Point2D(xSym, ySym).draw(window, color, thickness);
	}
}

void PrimitiveRenderer::drawBrokenLine(Point2D pointTab[], Color color, int pointsNumber, RenderWindow* window, bool isOpen,int thickness)
{
	for (int i = 1; i < pointsNumber; i++)
		PrimitiveRenderer::drawLine(pointTab[i - 1], pointTab[i], window, color, thickness);
	if (!isOpen)
		PrimitiveRenderer::drawLine(pointTab[pointsNumber-1], pointTab[0], window, color, thickness);
}

void PrimitiveRenderer::floodFill(Point2D start, Color filColor, RenderWindow* window)
{
	Point2D p;
	
	
	Vector2u windowSize = window->getSize();
	Texture texture;
	texture.create(windowSize.x, windowSize.y);
	texture.update(*window);
	Image tmp = texture.copyToImage();

	Color baseColor = tmp.getPixel(start.getX(), start.getY());

	std::stack<Point2D> stack;
	stack.push(start);
	while (!stack.empty())
	{
		
		p.setX(stack.top().getX());
		p.setY(stack.top().getY());
		stack.pop();
		if (tmp.getPixel(p.getX(), p.getY()) == filColor)
			continue;
		if (tmp.getPixel(p.getX(), p.getY()) != baseColor)
			continue;

		p.draw(window, filColor,1);
		tmp.setPixel(p.getX(), p.getY(), filColor);

		if(p.getY() - 1>0)
			stack.push(Point2D(p.getX(), p.getY()-1));

		if (p.getY() + 1 < windowSize.y)
			stack.push(Point2D(p.getX(), p.getY()+1));

		if (p.getX() - 1 > 0)
			stack.push(Point2D(p.getX()-1, p.getY()));

		if (p.getX() + 1 < windowSize.x)
			stack.push(Point2D(p.getX()+1, p.getY()));
		
	}

}
void PrimitiveRenderer::boundryFill(Point2D start, Color filColor, Color borderColor, RenderWindow* window)
{
	Point2D p;


	Vector2u windowSize = window->getSize();
	Texture texture;
	texture.create(windowSize.x, windowSize.y);
	texture.update(*window);
	Image tmp = texture.copyToImage();



	std::stack<Point2D> stack;
	stack.push(start);
	while (!stack.empty())
	{

		p.setX(stack.top().getX());
		p.setY(stack.top().getY());
		stack.pop();
		if (tmp.getPixel(p.getX(), p.getY()) == filColor)
			continue;
		if (tmp.getPixel(p.getX(), p.getY()) == borderColor)
			continue;

		p.draw(window, filColor,1);
		tmp.setPixel(p.getX(), p.getY(), filColor);

		if (p.getY() - 1 > 0)
			stack.push(Point2D(p.getX(), p.getY() - 1));

		if (p.getY() + 1 < windowSize.y)
			stack.push(Point2D(p.getX(), p.getY() + 1));

		if (p.getX() - 1 > 0)
			stack.push(Point2D(p.getX() - 1, p.getY()));

		if (p.getX() + 1 < windowSize.x)
			stack.push(Point2D(p.getX() + 1, p.getY()));

	}

}

