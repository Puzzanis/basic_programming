#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "Shape.h"

// Параллелограмм  
class Parallelogram : public Shape
{
protected:
	bool check_geometr_figure() override;// функция проверки правильности геометрической фигуры
public:
	Parallelogram(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D);
};

#endif