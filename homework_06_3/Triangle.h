#pragma once
#include "Shape.h"

class Triangle : public Shape
{	
protected:
	bool check_geometr_figure(); // функция проверки правильности геометрической фигуры
public:
	Triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C);
};

