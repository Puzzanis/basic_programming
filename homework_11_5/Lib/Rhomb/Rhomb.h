﻿#ifndef RHOMB_H
#define RHOMB_H

#include "../Shape/Shape.h"

// Ромб  
class Rhomb : public Shape
{
protected:
	void check_geometr_figure() override; // функция проверки правильности геометрической фигуры
public:
	Rhomb(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D);
};

#endif