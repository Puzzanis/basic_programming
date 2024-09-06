#ifndef QUADRANGLE_H
#define QUADRANGLE_H

#include "../Shape/Shape.h"

// Четырехугольник - базовый класс
class Quadrangle : public Shape
{
protected:
	void check_geometr_figure() override; // функция проверки правильности геометрической фигуры

public:
	Quadrangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D);
};

#endif