#include "LineSegment.h"


LineSegment::LineSegment(Point2D first, Point2D second)
{
    this->first = first;
    this->second = second;
}

Point2D LineSegment::getFirst()
{
    return first;
}

Point2D LineSegment::getSecond()
{
    return second;
}

void LineSegment::setFirst(Point2D point)
{
    first = point;
}

void LineSegment::setSecond(Point2D point)
{
    second = point;
}

void LineSegment::drawDefault(RenderWindow* window,Color color)
{
    Vertex line[] =
    {
        Vertex(Vector2f(first.getX(),first.getY()),color),
        Vertex(Vector2f(second.getX(),second.getY()),color)
    };
    window->draw(line, 2, Lines);
}

void LineSegment::drawProgressive(RenderWindow* window,Color color)
{
    PrimitiveRenderer::drawLine(first, second, window,color);
}
