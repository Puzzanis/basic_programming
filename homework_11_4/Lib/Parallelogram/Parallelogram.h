#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H

#include "../Shape/Shape.h"

#ifdef SHAPECLASSESLIB_EXPORTS
#define SHAPE __declspec(dllexport)
#else
#define SHAPE __declspec(dllimport)
#endif

// Параллелограмм  
class Parallelogram : public Shape
{
protected:
	void check_geometr_figure() override;// функция проверки правильности геометрической фигуры
public:
	SHAPE Parallelogram(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D);
};

#endif