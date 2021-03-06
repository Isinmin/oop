#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "polygon.h"
#include "triangle.h"

class Rectangle : public Polygon
{
public:
    // center - координаты верхней левой вершины
    Rectangle(const Point2d& vertex, double _upperSide, double _leftSide, double angle = 0);

    double area() const;
    double perimeter() const;

    void scale(double scale = 1);

    double getUpperSide() const;
    double getLeftSide() const;

    static void split(Rectangle* rect, Triangle* part1, Triangle* part2);

private:
    // Стороны прямоугольника
    double upperSide, leftSide;
};

#endif // RECTANGLE_H
