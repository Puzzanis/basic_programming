#pragma once

#include "Shape.h"

#ifdef SHAPELIB_EXPORTS
#define SHAPELIB_API __declspec(dllexport)
#else
#define SHAPELIB_API __declspec(dllimport)
#endif

namespace ShapeLib {
	// Параллелограмм  
	class Parallelogram : public Shape
	{
	protected:
		void check_geometr_figure() override;// функция проверки правильности геометрической фигуры
	public:
		SHAPELIB_API Parallelogram(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D);
	};
}