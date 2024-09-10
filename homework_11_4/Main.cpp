#include <iostream>
#include "Shape.h"
#include "Error.h"
#include "Print.h"
#include "Triangle.h"
#include "Right_angled_triangle.h"
#include "Isosceles_triangle.h"
#include "Equilateral_triangle.h"
#include "Quadrangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include "Rhomb.h"

int main() {
	setlocale(LC_ALL, "rus");  //setting the language standard

	ShapeLib::Shape shape{};
	ShapeLib::print(shape);

	// �����������
	ShapeLib::Triangle triangle{ 10, 20, 30, 50, 60, 70 };
	ShapeLib::print(triangle);
	// ������������� �����������
	ShapeLib::Right_angled_triangle r{ 10, 20, 40, 30, 50, 90 };
	ShapeLib::print(r);
	// �������������� �����������
	ShapeLib::Isosceles_triangle i{ 10, 20, 10, 50, 60, 50 };
	ShapeLib::print(i);
	// �������������� �����������
	ShapeLib::Equilateral_triangle e{ 20, 20, 20, 60, 60, 60 };
	ShapeLib::print(e);
	// ���������������
	ShapeLib::Quadrangle q{ 10, 20, 30, 50, 100, 80, 100, 80 };
	ShapeLib::print(q);
	// �������������
	ShapeLib::Rectangle re{ 10, 20, 10, 20, 90, 90, 90, 90 };
	ShapeLib::print(re);
	// �������
	ShapeLib::Square s{ 50, 50, 50, 50, 90, 90, 90, 90 };
	ShapeLib::print(s);
	// ��������������
	ShapeLib::Parallelogram p{ 50, 90, 50, 90, 30, 60, 30, 60 };
	ShapeLib::print(p);
	// ����
	ShapeLib::Rhomb rhomb{ 10, 10, 10, 10, 30, 60, 30, 60 };
	ShapeLib::print(rhomb);
	system("pause");

	return EXIT_SUCCESS;
}