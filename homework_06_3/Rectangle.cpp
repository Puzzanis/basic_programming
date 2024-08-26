#include "Rectangle.h"

bool Rectangle::check_geometr_figure() // функция проверки правильности геометрической фигуры
{
	if (sides_count == 4 && corner_A == 90 && corner_B == 90 && corner_C == 90 && corner_D == 90 && side_length_a == side_length_c && side_length_b == side_length_d)
	{
		return true;
	}
	else {
		return false;
	}
}

Rectangle::Rectangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
{
	name = "Прямоугольник";
	sides_count = 4;
	side_length_a = set_side_length_a;
	side_length_b = set_side_length_b;
	side_length_c = set_side_length_c;
	side_length_d = set_side_length_d;
	isQuadrangle = true;

	corner_A = set_corner_A;
	corner_B = set_corner_B;
	corner_C = set_corner_C;
	corner_D = set_corner_D;
}
