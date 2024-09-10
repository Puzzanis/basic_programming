#include <iostream>
#include <string>
#include "Lib\Shape\Shape.h"
#include "Lib\Triangle\Triangle.h"
#include "Lib\Quadrangle\Quadrangle.h"
#include "Lib\Right_angled_triangle\Right_angled_triangle.h"
#include "Lib\Isosceles_triangle\Isosceles_triangle.h"
#include "Lib\Equilateral_triangle\Equilateral_triangle.h"
#include "Lib\Rectangle\Rectangle.h"
#include "Lib\Square\Square.h"
#include "Lib\Parallelogram\Parallelogram.h"
#include "Lib\Rhomb\Rhomb.h"
#include "Lib\Print\Print.h"

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard
	Shape Shape{};
	print(Shape);

	// Треугольник
	Triangle triangle{ 10, 20, 30, 50, 60, 70 };
	print(triangle);
	// Прямоугольный треугольник
	Right_angled_triangle r{ 10, 20, 40, 30, 50, 90 };
	print(r);
	// Равнобедренный треугольник
	Isosceles_triangle i{ 10, 20, 10, 50, 60, 50 };
	print(i);
	// Равносторонний треугольник
	Equilateral_triangle e{ 20, 20, 20, 60, 60, 60 };
	print(e);
	// Четырехугольник
	Quadrangle q{ 10, 20, 30, 50, 100, 80, 100, 80 };
	print(q);
	// Прямоугольник
	Rectangle re{ 10, 20, 10, 20, 90, 90, 90, 90 };
	print(re);
	// Квадрат
	Square s{ 50, 50, 50, 50, 90, 90, 90, 90 };
	print(s);
	// Параллелограмм
	Parallelogram p{ 50, 90, 50, 90, 30, 60, 30, 60 };
	print(p);
	// Ромб
	Rhomb rhomb{ 10, 10, 10, 10, 30, 60, 30, 60 };
	print(rhomb);
	system("pause");
	return EXIT_SUCCESS;
}
