#include "Rhombus.h"
#include "Shape.h"
#include <iostream>



bool Rhombus::is_rhombus(const std::vector<Dot>& v) {
	bool flag = false;
	for (int i = 0; i < v.size(); i++) {

		if (!float_comparison(
			v[i].distance(v[(i + 1) % v.size()]),
			v[(i + 1) % v.size()].distance(v[(i + 2) % v.size()])))
		{
			return false;
		}
	}
	return true;
}
void Rhombus::print(std::ostream& OS) const {
	OS << "RHOMBUS" << std::endl;
	OS << "Color: " << (int) color.R << " " << (int) color.G << " " << (int) color.B << std::endl;
	OS << "id: " << id << std::endl;
}


