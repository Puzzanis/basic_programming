#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape
{
protected:
	std::string name{ "Фигура" };
	int sides_count{};
	int side_length_a{};
	int side_length_b{};
	int side_length_c{};
	int side_length_d{};

	int corner_A{};
	int corner_B{};
	int corner_C{};
	int corner_D{};

	bool isQuadrangle{ false }; //признак четырехугольника
	bool printing_is_allowed{ false }; //печать разрешена

	virtual void check_geometr_figure(); // функция проверки правильности геометрической фигуры

public:
	std::string getName();
	int get_side_length_a();
	int get_side_length_b();
	int get_side_length_c();
	int get_side_length_d();

	int get_corner_A();
	int get_corner_B();
	int get_corner_C();
	int get_corner_D();

	int getSides_count();
	bool get_isQuadrangle();
	bool get_is_right_figure();
	bool get_printing_is_allowed();
};

#endif