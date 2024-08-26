#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "Right_angled_triangle.h"

// Равнобедренный треугольник
class Isosceles_triangle : public Shape
{
protected:
	bool check_geometr_Shape() // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 3 && corner_A == corner_C && side_length_a == side_length_c)
		{
			return true;
		}
		else {
			return false;
		}
	}
public:
	Isosceles_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C)
	{
		name = "Равнобедренный треугольник";
		sides_count = 3;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
	}
};
// Равносторонний треугольник
class Equilateral_triangle : public Shape
{
protected:
	bool check_geometr_Shape() // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 3 && corner_A == 60 && corner_B == 60 && corner_C == 60 && side_length_a == side_length_b && side_length_b == side_length_c)
		{
			return true;
		}
		else {
			return false;
		}
	}
public:
	Equilateral_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C)
	{
		name = "Равносторонний треугольник";
		sides_count = 3;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
	}
};
// Прямоугольник 
class Rectangle : public Shape
{
protected:
	bool check_geometr_Shape() // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 4 && corner_A == 90 && corner_B == 90 && corner_C == 90 && corner_D == 90 && side_length_a == side_length_c && side_length_b == side_length_d)
		{
			return true;
		}
		else {
			return false;
		}
	}
public:
	Rectangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
	{
		name = "Прямоугольник";
		sides_count = 4;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;
		side_length_d = set_side_length_d;
		isQuadrangle = true;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
		corner_D = set_corner_D;
	}
};

// Квадрат  
class Square : public Shape
{
protected:
	bool check_geometr_Shape() // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 4 && corner_A == 90 && corner_B == 90 && corner_C == 90 && corner_D == 90 && side_length_a == side_length_b && side_length_c == side_length_d && side_length_a == side_length_c)
		{
			return true;
		}
		else {
			return false;
		}
	}
public:
	Square(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
	{
		name = "Квадрат";
		sides_count = 4;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;
		side_length_d = set_side_length_d;
		isQuadrangle = true;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
		corner_D = set_corner_D;
	}
};
// Параллелограмм  
class Parallelogram : public Shape
{
protected:
	bool check_geometr_Shape() // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 4 && corner_A == corner_C && corner_B == corner_D && side_length_a == side_length_c && side_length_b == side_length_d)
		{
			return true;
		}
		else {
			return false;
		}
	}
public:
	Parallelogram(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
	{
		name = "Параллелограмм";
		sides_count = 4;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;
		side_length_d = set_side_length_d;
		isQuadrangle = true;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
		corner_D = set_corner_D;
	}
};
// Ромб  
class Rhomb : public Shape
{
protected:
	bool check_geometr_figure() // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 4 && corner_A == corner_C && corner_B == corner_D && side_length_a == side_length_b && side_length_c == side_length_d && side_length_a == side_length_c)
		{
			return true;
		}
		else {
			return false;
		}
	}
public:
	Rhomb(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
	{
		name = "Ромб";
		sides_count = 4;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;
		side_length_d = set_side_length_d;
		isQuadrangle = true;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
		corner_D = set_corner_D;
	}
};

void print(Shape& fig)
{
	std::cout << fig.getName() << ':' << '\n';
	std::cout << ((fig.get_is_right_figure()) ? "Правильная" : "Неправильная") << '\n';
	std::cout << "Количество сторон: " << fig.getSides_count() << ':' << '\n';
	if (fig.getSides_count() > 0)
	{
		std::cout << "Стороны: " << "a=" << fig.get_side_length_a() << " b=" << fig.get_side_length_b() << " c=" << fig.get_side_length_c();
		if (fig.get_isQuadrangle() > 0)
		{
			std::cout << " d=" << fig.get_side_length_d() << '\n';
		}
		else
		{
			std::cout << '\n';
		}

		std::cout << "Углы: " << "A=" << fig.get_corner_A() << " B=" << fig.get_corner_B() << " C=" << fig.get_corner_C();
		if (fig.get_isQuadrangle())
		{
			std::cout << " d=" << fig.get_corner_D() << '\n';
		}
		else
		{
			std::cout << '\n';
		}
	}
	std::cout << '\n';
}

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
	//// Равнобедренный треугольник
	//Isosceles_triangle i{ 10, 20, 10, 50, 60, 50 };
	//print(i);
	//// Равносторонний треугольник
	//Equilateral_triangle e{ 20, 20, 20, 60, 60, 60 };
	//print(e);
	// Четырехугольник
	Quadrangle q{ 10, 20, 30, 50, 100, 80, 100, 80 };
	print(q);
	//// Прямоугольник
	//Rectangle re{ 10, 20, 10, 20, 91, 90, 90, 90 };
	//print(re);
	//// Квадрат
	//Square s{ 50, 50, 50, 50, 90, 90, 90, 90 };
	//print(s);
	//// Параллелограмм
	//Parallelogram p{ 50, 90, 50, 90, 30, 60, 30, 60 };
	//print(p);
	//// Ромб
	//Rhomb rhomb{ 10, 10, 10, 10, 30, 60, 30, 60 };
	//print(rhomb);

	return EXIT_SUCCESS;
}