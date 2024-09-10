#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

#ifdef SHAPECLASSESLIB_EXPORTS
#define SHAPE __declspec(dllexport)
#else
#define SHAPE __declspec(dllimport)
#endif

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
	SHAPE std::string getName();
	SHAPE int get_side_length_a();
	SHAPE int get_side_length_b();
	SHAPE int get_side_length_c();
	SHAPE int get_side_length_d();

	SHAPE int get_corner_A();
	SHAPE int get_corner_B();
	SHAPE int get_corner_C();
	SHAPE int get_corner_D();

	SHAPE int getSides_count();
	SHAPE bool get_isQuadrangle();
	SHAPE bool get_is_right_figure();
	SHAPE bool get_printing_is_allowed();
};

#endif