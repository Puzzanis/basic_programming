﻿#pragma once
#include "Shape.h"

// Прямоугольный треугольник
class Right_angled_triangle : public Shape
{
protected:
	bool check_geometr_figure() override; // функция проверки правильности геометрической фигуры

public:
	Right_angled_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C);
};

