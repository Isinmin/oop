#define _USE_MATH_DEFINES 


#pragma once;
#include <math.h>
#include <random>
#include "StepShared.h"
#include "StepVector.h"
#include "Shape.h"
#include "Rhombus.h"
#include "Square.h"
#include "Trapezium.h"
#include "Dot.h"

using namespace std;

Shape *generate_random_square(long int BORDER = 777){
	std::vector<Dot> corners(4);

	double first_angle = rand() % BORDER;
	double second_angle = first_angle + M_PI / 2;
	double side = rand() % BORDER + 1;
	corners[0] = { Dot(rand() % 10, rand() % 10) };
	corners[1] = { Dot(corners[0].x + side*cos(first_angle), corners[0].y + side*sin(first_angle)) };
	corners[2] = { Dot(corners[1].x + side*cos(second_angle), corners[1].y + side*sin(second_angle)) };
	corners[3] = { Dot(corners[0].x + side*cos(second_angle), corners[0].y + side*sin(second_angle)) };

	return new Square(corners);
}

Shape *generate_random_rhombus(long int BORDER = 777) {
	std::vector<Dot> corners(4);

	double first_angle = rand() % 100;
	double second_angle = first_angle + M_PI / 2;
	double side = rand() % BORDER + 1;
	corners[0] = { Dot(rand() % 10, rand() % 10) };
	corners[1] = { Dot(corners[0].x + side*cos(first_angle), corners[0].y + side*sin(first_angle)) };
	corners[2] = { Dot(corners[1].x + side*cos(second_angle), corners[1].y + side*sin(second_angle)) };
	corners[3] = { Dot(corners[0].x + side*cos(second_angle), corners[0].y + side*sin(second_angle)) };

	return new Rhombus(corners);
}
Shape *generate_random_trapezium(long int BORDER = 777) {
	std::vector<Dot> corners(4);

	double first_angle = rand() % 100;
	double first_side = rand() % BORDER + 1;
	double second_side = rand() % BORDER + 1;

	corners[0] = { Dot(rand() % 10, rand() % 10) };
	corners[1] = { Dot(rand() % 10, rand() % 10) };
	corners[2] = { Dot(corners[1].x + first_side*cos(first_angle), corners[1].y + first_side*sin(first_angle)) };
	corners[3] = { Dot(corners[0].x + second_side*cos(first_angle), corners[0].y + second_side*sin(first_angle)) };

	return new Trapezium(corners);
}

Shape* generate_random_shape()
{
	int rnd = rand() % 3;

	switch (rnd)
	{
	case 0:
		return generate_random_square();
	case 1:
		return generate_random_trapezium();
	case 2:
		return generate_random_rhombus();
	default:
		return NULL;
	}
}

stepik::vector< stepik::shared_ptr<Shape> > generate_shapes(unsigned int n)
{
	stepik::vector< stepik::shared_ptr<Shape> > Shapes(n);

	for (unsigned int i = 0; i < n; i++)
	{
		Shapes[i] = stepik::shared_ptr<Shape>(generate_random_shape());
	}

	return Shapes;
}


bool predicate(const stepik::shared_ptr<Shape> &a) {
	std::vector<Dot> my_square = { Dot(0, 0), Dot(0, 5), Dot(5, 5), Dot(5, 0) };
	Square square(my_square);
	Shape *b = new Square(square);
	return b->common_side(a.get());
}

