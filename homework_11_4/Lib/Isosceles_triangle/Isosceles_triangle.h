#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H

#include "../Shape/Shape.h"

#ifdef SHAPECLASSESLIB_EXPORTS
#define SHAPE __declspec(dllexport)
#else
#define SHAPE __declspec(dllimport)
#endif

// Равнобедренный треугольник
class Isosceles_triangle : public Shape
{
protected:
	void check_geometr_figure() override; // функция проверки правильности геометрической фигуры

public:
	SHAPE Isosceles_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C);
};

#endif
