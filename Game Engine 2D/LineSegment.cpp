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

void LineSegment::draw(RenderWindow* window,Color color, int thickness)
{
    PrimitiveRenderer::drawLine(first, second, window,color,thickness);
}

void LineSegment::translate(int x, int y)
{
    TransformableObject::translate(first.getXRef(), first.getYRef(), x, y);
    TransformableObject::translate(second.getXRef(), second.getYRef(), x, y);
}

void LineSegment::rotate(int px, int py, int angle)
{
    TransformableObject::rotate(first.getXRef(), first.getYRef(), px, py, angle);
    TransformableObject::rotate(second.getXRef(), second.getYRef(), px, py, angle);
}

void LineSegment::rotate(int angle)
{
    TransformableObject::rotate(first.getXRef(), first.getYRef(), 0, 0, angle);
    TransformableObject::rotate(second.getXRef(), second.getYRef(), 0, 0, angle);
}

void LineSegment::scale(int px, int py, float kx, float ky)
{
    TransformableObject::scale(first.getXRef(), first.getYRef(), px, py, kx, ky);
    TransformableObject::scale(second.getXRef(), second.getYRef(), px, py, kx, ky);
}

void LineSegment::scale(float kx, float ky)
{
    TransformableObject::scale(first.getXRef(), first.getYRef(), 0, 0, kx, ky);
    TransformableObject::scale(second.getXRef(), second.getYRef(), 0, 0, kx, ky);
}
