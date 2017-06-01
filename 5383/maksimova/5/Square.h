#pragma once
#ifndef Square_h
#define Square_h
#include "Rhombus.h"

class Square :public Rhombus {
public:
	static bool is_square(const std::vector<Dot>& corners); // проверка на ромб

																  //конструктор
	Square(std::vector<Dot> points, Color color=Color(), double angle = 0) :Rhombus(points, color, angle) {
		this->corners = points;
		this->name = "Square";
	}


	void print(std::ostream& OS) const override; // Вывод
};
#endif Square_h
