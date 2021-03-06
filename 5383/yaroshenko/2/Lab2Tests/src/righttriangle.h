#ifndef RIGHTTRIANGLE_H
#define RIGHTTRIANGLE_H

#include "triangle.h"

class RightTriangle : public Triangle
{
public:
    RightTriangle(const Point2d& vertex, double leftSide, double downSide, double angle = 0);

    double area() const;
};

#endif // RIGHTTRIANGLE_H
