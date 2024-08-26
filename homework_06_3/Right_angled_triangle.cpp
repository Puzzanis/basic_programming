#include "Right_angled_triangle.h"

// Прямоугольный треугольник
bool Right_angled_triangle::check_geometr_figure() // функция проверки правильности геометрической фигуры
{
	if (sides_count == 3 && corner_C == 90)
	{
		return true;
	}
	else {
		return false;
	}
}

Right_angled_triangle::Right_angled_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C)
{
	name = "Прямоугольный треугольник";
	sides_count = 3;
	side_length_a = set_side_length_a;
	side_length_b = set_side_length_b;
	side_length_c = set_side_length_c;

	corner_A = set_corner_A;
	corner_B = set_corner_B;
	corner_C = set_corner_C;
}
