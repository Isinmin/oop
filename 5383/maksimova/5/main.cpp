#include "Lab5.h"
#include "StepVector.h"
#include <locale>
#include "StepShared.h"
#include <windows.h>
 #define _SCL_SECURE_NO_WARNINGS  
//алгоритмы пришлось вынести в отдельные функции


int main() {
	setlocale(LC_ALL, "");
	//Алгоритмы из моего задания имеются в <algorithm>

//******* Проверка что все элементы диапазона удовлетворяют определенному критерию. ********

	//Генерируем случайные фигуры в количестве 1000 шт.
	stepik::vector< stepik::shared_ptr<Shape> > shapes = generate_shapes(1000);

	//Проверяем, выполним ли предикат для всех элементов контейнера. 
	if (std::all_of(shapes.begin(), shapes.end(), predicate)) {
		std::cout << "[Error] vse elementy imeyut obshuyu storonu" <<std::endl;
	}
	else {
		std::cout << "[Ok] ne vse elementy imeyut obshuyu storonu" << std::endl;
	}

//******* Заменить элементы, соответствующие критерию, копируя весь диапазон. *******


	stepik::vector< stepik::shared_ptr<Shape> > new_shapes(1000);// новый контейнер куда скопируется


	//ручные тесты

	Shape *sq1 = new Square({ Dot(1, 1), Dot(1, 3), Dot(3, 3), Dot(3, 1) }, Color());
	Shape *sq2 = new Square({ Dot(3, 1), Dot(3, 3), Dot(5,3), Dot(5, 1) }, Color());

	Shape *tr1 = new Trapezium({ Dot(0, 0), Dot(2, 2), Dot(5, 2), Dot(7, 0) }, Color());
	Shape *tr2 = new Trapezium({ Dot(-3, 0), Dot(-1, 3), Dot(1, 3), Dot(3, 0) }, Color());

	Shape *rh1 = new Rhombus({ Dot(1, 1), Dot(2, 1 + sqrt(3)), Dot(4, 1 + sqrt(3)), Dot(3, 1) }, Color());
	Shape *rh2 = new Rhombus({ Dot(3, 1), Dot(4, 1 + sqrt(3)), Dot(6, 1 + sqrt(3)), Dot(5, 1) }, Color());

	
	stepik::vector< stepik::shared_ptr<Shape> > bad_vector;
	std::vector<Dot> my_square = { Dot(1, 1), Dot(1, 3), Dot(3, 3), Dot(3, 1) }; // Тот самый квадрат
	stepik::shared_ptr<Shape> real_square(new Square(my_square));
	bad_vector.push_back(stepik::shared_ptr<Shape>(sq1));
	bad_vector.push_back(stepik::shared_ptr<Shape>(sq2));
	bad_vector.push_back(stepik::shared_ptr<Shape>(tr1));
	bad_vector.push_back(stepik::shared_ptr<Shape>(tr2));
	bad_vector.push_back(stepik::shared_ptr<Shape>(rh1));
	bad_vector.push_back(stepik::shared_ptr<Shape>(rh2));


	if (std::all_of(bad_vector.begin(), bad_vector.end(), predicate)) {
		std::cout << "[Error] vse elementy imeyut obshuyu storonu" << std::endl;
	}
	else {
		std::cout << "[Ok] ne vse elementy imeyut obshuyu storonu" << std::endl;
	}
		stepik::vector< stepik::shared_ptr<Shape> > new_vector = bad_vector;
		std::replace_copy_if(bad_vector.begin(), bad_vector.end(), new_vector.begin(),
			predicate, real_square);
		std::cout << "modificiruyushiy" << std::endl;
		std::cout << "*****Do*****" << std::endl;

		for (auto &elem : bad_vector) {
			std::cout << *elem << " ";
		}
	
		std::cout << "*****Posle*****" << std::endl;
		for (auto &elem : new_vector) {
			if (elem.get())
				std::cout << *elem << " ";
		}
		vector<Dot> a = { Dot(0, 0), Dot(0, 5), Dot(5, 5), Dot(5, 0) };
		vector<Dot> b = { Dot(0, 5), Dot(2, 3), Dot(3, 3), Dot(5, 5) };
		vector<Dot> c = { Dot(0, 5), Dot(2, 7), Dot(3, 7), Dot(5, 5) };
		Square square(a);
		Trapezium trapezium1(b);
		Trapezium trapezium2(c);
	Shape *Sq = new Square (square);
	Shape *Tr1 = new Trapezium(trapezium1);
	Shape *Tr2 = new Trapezium(trapezium2);

	stepik::vector< stepik::shared_ptr<Shape> > good_vector;
	good_vector.push_back(stepik::shared_ptr<Shape>(Sq));
	good_vector.push_back(stepik::shared_ptr<Shape>(Tr1));
	good_vector.push_back(stepik::shared_ptr<Shape>(Tr2));

	
	if (std::all_of(good_vector.begin(), good_vector.end(), predicate)) {
		std::cout << "[Ok] vse elementy imeyut obshuyu storonu" << std::endl;
	}
	else {
		std::cout << "[Error] ne vse elementy imeyut obshuyu storonu" << std::endl;
	}
	std::cout << " modificiruyushiy" << std::endl;
	std::cout << "*****Do*****" << std::endl;
	stepik::vector< stepik::shared_ptr<Shape> > new_good_vector (3);
	for (auto &elem : good_vector) {
		std::cout << *elem << " ";
	}
	std::replace_copy_if(good_vector.begin(), good_vector.end(), new_good_vector.begin(),
		predicate, real_square);
	std::cout << "*****Posle*****" << std::endl;
	for (auto &elem : new_good_vector) {
		if(elem.get())
			std::cout << *elem << " ";
	}

	system("pause");
	return 0;
}