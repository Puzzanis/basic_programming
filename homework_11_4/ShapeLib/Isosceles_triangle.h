#pragma once

#include "Shape.h"

#ifdef SHAPELIB_EXPORTS
#define SHAPELIB_API __declspec(dllexport)
#else
#define SHAPELIB_API __declspec(dllimport)
#endif

namespace ShapeLib {
	// �������������� �����������
	class Isosceles_triangle : public Shape
	{
	protected:
		void check_geometr_figure() override; // ������� �������� ������������ �������������� ������

	public:
		SHAPELIB_API Isosceles_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C);
	};

}