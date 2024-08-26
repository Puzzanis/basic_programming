#include "Shape.h"

bool Shape::check_geometr_figure() // функция проверки правильности геометрической фигуры
{
	if (sides_count == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

std::string Shape::getName() { return name; }
int Shape::Shape::get_side_length_a() { return side_length_a; }
int Shape::get_side_length_b() { return side_length_b; }
int Shape::get_side_length_c() { return side_length_c; }
int Shape::get_side_length_d() { return side_length_d; }

int Shape::get_corner_A() { return corner_A; }
int Shape::get_corner_B() { return corner_B; }
int Shape::get_corner_C() { return corner_C; }
int Shape::get_corner_D() { return corner_D; }

int Shape::getSides_count() { return sides_count; }
bool Shape::get_isQuadrangle() { return isQuadrangle; }
bool Shape::get_is_right_figure() { return check_geometr_figure(); }