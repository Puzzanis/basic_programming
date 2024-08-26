#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "Shape.h"

// Равнобедренный треугольник
class Isosceles_triangle : public Shape
	{
	protected:
		bool check_geometr_figure() override; // функция проверки правильности геометрической фигуры

	public:
		Isosceles_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C);
	};

#endif
