
#ifndef Trapezium_h
#define Trapezium_h
#include "Shape.h"
class Trapezium :public Shape {
public:
	static bool is_trapezium(const std::vector<Dot>& corners); // проверка на ромб

															   //конструктор
	Trapezium(std::vector<Dot> points, Color color = Color(), double angle = 0) :Shape(points, color, angle) {
		this->corners = points;
		this->name = "Trapezium";
	}


	void print(std::ostream& OS) const override; // Вывод
};
#endif Trapezium_h