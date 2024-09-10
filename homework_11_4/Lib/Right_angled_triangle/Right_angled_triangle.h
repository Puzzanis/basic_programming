#ifndef RIGHT_ANGLED_TRIANGLE_H
#define RIGHT_ANGLED_TRIANGLE_H

#include "../Shape/Shape.h"

#ifdef SHAPECLASSESLIB_EXPORTS
#define SHAPE __declspec(dllexport)
#else
#define SHAPE __declspec(dllimport)
#endif

// Прямоугольный треугольник
class Right_angled_triangle : public Shape
{
protected:
	void check_geometr_figure() override; // функция проверки правильности геометрической фигуры

public:
	SHAPE Right_angled_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C);
};

#endif