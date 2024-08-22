#include <iostream>
#include <string>


class Figure
{
protected:
	std::string name{};
	int side_length_a{};
	int side_length_b{};
	int side_length_c{};
	int side_length_d{};

	int corner_A{};
	int corner_B{};
	int corner_C{};
	int corner_D{};

	bool isQuadrangle{ false }; //признак четырехугольника

public:
	std::string getName() { return name; }
	int get_side_length_a() { return side_length_a; }
	int get_side_length_b() { return side_length_b; }
	int get_side_length_c() { return side_length_c; }
	int get_side_length_d() { return side_length_d; }

	int get_corner_A() { return corner_A; }
	int get_corner_B() { return corner_B; }
	int get_corner_C() { return corner_C; }
	int get_corner_D() { return corner_D; }
	bool get_isQuadrangle() { return isQuadrangle; }

};

// Треугольник
class Triangle: public Figure
{
public:
	Triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, float set_corner_A, float set_corner_B, float set_corner_C)
	{
		name = "Треугольник";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;
		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
		
	}
};
// Четырехугольник - базовый класс
class Quadrangle: public Figure
{
public:
	Quadrangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, float set_corner_A, float set_corner_B, float set_corner_C, float set_corner_D)
	{
		name = "Четырехугольник";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;
		side_length_d = set_side_length_d;
		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
		corner_D = set_corner_D;
		isQuadrangle = true;
	}
};

// Прямоугольный треугольник
class Right_angled_triangle : public Figure
{
public:
	Right_angled_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, float set_corner_A, float set_corner_B) 
	{
		name = "Прямоугольный треугольник";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = 90;
	}
};

// Равнобедренный треугольник
class Isosceles_triangle : public Figure
{
public:
	Isosceles_triangle(int set_side_length_a, int set_side_length_b, float set_corner_A, float set_corner_B)
	{
		name = "Равнобедренный треугольник";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_a;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_A;
	}
};
// Равносторонний треугольник
class Equilateral_triangle : public Figure
{
public:
	Equilateral_triangle(int set_side_length_a, float set_corner_A)
	{
		name = "Равносторонний треугольник";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_a;
		side_length_c = set_side_length_a;

		corner_A = set_corner_A;
		corner_B = set_corner_A;
		corner_C = set_corner_A;
	}
};
// Прямоугольник 
class Rectangle : public Figure
{
public:
	Rectangle(int set_side_length_a, int set_side_length_b)
	{
		name = "Прямоугольник";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_a;
		side_length_d = set_side_length_b;
		isQuadrangle = true;

		corner_A = corner_B = corner_C = corner_D = 90;

	}
};

// Квадрат  
class Square : public Figure
{
public:
	Square(int set_side_length_a)
	{
		name = "Квадрат";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_a;
		side_length_c = set_side_length_a;
		side_length_d = set_side_length_a;
		isQuadrangle = true;

		corner_A = corner_B = corner_C = corner_D = 90;
	}
};
// Параллелограмм  
class Parallelogram : public Figure
{
public:
	Parallelogram(int set_side_length_a, int set_side_length_b, float set_corner_A, float set_corner_B) 
	{
		name = "Параллелограмм";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_a;
		side_length_d = set_side_length_b;
		isQuadrangle = true;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_A;
		corner_D = set_corner_B;
	}
};
// Ромб  
class Rhomb : public Figure
{
public:
	Rhomb(int set_side_length_a, float set_corner_A, float set_corner_B) 
	{
		name = "Ромб";
		side_length_a = side_length_b = side_length_c = side_length_d = set_side_length_a;
		isQuadrangle = true;
		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_A;
		corner_D = set_corner_B;
	}
};

void print(Figure& fig)
{
	std::cout << fig.getName() << ':' << '\n';
	std::cout << "Стороны: " << "a=" << fig.get_side_length_a() << " b=" << fig.get_side_length_b() << " c=" << fig.get_side_length_c();
	if (fig.get_isQuadrangle())
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
	std::cout << '\n';
}

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

	// Треугольник
	Triangle triangle{ 10, 20, 30, 50, 60, 70 };
	print(triangle);
	// Прямоугольный треугольник
	Right_angled_triangle r{10, 20, 30, 50, 50};
	print(r);
	// Равнобедренный треугольник
	Isosceles_triangle i{ 10, 20, 50, 60 };
	print(i);
	// Равносторонний треугольник
	Equilateral_triangle e{ 20, 60 };
	print(e);
	// Четырехугольник
	Quadrangle q{ 10, 20, 30, 40, 50, 60, 70, 80 };
	print(q);
	// Прямоугольник
	Rectangle re{ 10, 20 };
	print(re);
	// Квадрат
	Square s{ 50 };
	print(s);
	// Параллелограмм
	Parallelogram p{ 50, 90, 30, 60 };
	print(p);
	// Ромб
	Rhomb rhomb{ 50, 30, 60 };
	print(rhomb);

	return EXIT_SUCCESS;
}