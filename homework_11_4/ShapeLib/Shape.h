#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

#ifdef SHAPELIB_EXPORTS
#define SHAPELIB_API __declspec(dllexport)
#else
#define SHAPELIB_API __declspec(dllimport)
#endif

namespace ShapeLib {
	class Shape
	{
	protected:
		std::string name{ "Фигура" };
		int sides_count{};
		int side_length_a{};
		int side_length_b{};
		int side_length_c{};
		int side_length_d{};

		int corner_A{};
		int corner_B{};
		int corner_C{};
		int corner_D{};

		bool isQuadrangle{ false }; //признак четырехугольника
		bool printing_is_allowed{ false }; //печать разрешена

		SHAPELIB_API virtual void check_geometr_figure(); // функция проверки правильности геометрической фигуры

	public:
		SHAPELIB_API std::string getName();
		SHAPELIB_API int get_side_length_a();
		SHAPELIB_API int get_side_length_b();
		SHAPELIB_API int get_side_length_c();
		SHAPELIB_API int get_side_length_d();
					 
		SHAPELIB_API int get_corner_A();
		SHAPELIB_API int get_corner_B();
		SHAPELIB_API int get_corner_C();
		SHAPELIB_API int get_corner_D();
					 
		SHAPELIB_API int getSides_count();
		SHAPELIB_API bool get_isQuadrangle();
		SHAPELIB_API bool get_is_right_figure();
		SHAPELIB_API bool get_printing_is_allowed();
	};
}
#endif