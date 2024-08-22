#include <iostream>
#include <string>


class Figure
{
protected:
	std::string name{"Фигура"};
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
//	bool is_right_figure{ false }; // флаг правильной фигуры

	virtual bool check_geometr_figure() // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}

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

	int getSides_count() { return sides_count; }
	bool get_isQuadrangle() { return isQuadrangle; }
	bool get_is_right_figure() { return check_geometr_figure(); }

};

// Треугольник
class Triangle : public Figure
{
protected:
	bool check_geometr_figure() override // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 3 and corner_A + corner_B + corner_C == 180)
		{
			return true;
		}
		else {
			return false;
		}
	}
public:
	Triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C)
	{
		name = "Треугольник";
		sides_count = 3;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;
		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
	}
};
// Четырехугольник - базовый класс
class Quadrangle : public Figure
{
protected:
	bool check_geometr_figure() override // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 4 && corner_A + corner_B + corner_C + corner_D == 360)
		{
			return true;
		}
		else {
			return false;
		}
	}
public:
	Quadrangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
	{
		name = "Четырехугольник";
		sides_count = 4;
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
protected:
	bool check_geometr_figure() override // функция проверки правильности геометрической фигуры
	{
		if (sides_count == 3 && corner_C == 90)
		{
			return true;
		}
		else {
			return false;
		}
	}
public:
	Right_angled_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C)
	{
		name = "Прямоугольный треугольник";
		sides_count = 3;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
	}
};

// Равнобедренный треугольник
class Isosceles_triangle : public Figure
{
protected:
	bool check_geometr_figure() override // функция проверки правильности геометрической фигуры
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
class Equilateral_triangle : public Figure
{
protected:
	bool check_geometr_figure() override // функция проверки правильности геометрической фигуры
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
class Rectangle : public Figure
{
protected:
	bool check_geometr_figure() override // функция проверки правильности геометрической фигуры
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
class Square : public Figure
{
protected:
	bool check_geometr_figure() override // функция проверки правильности геометрической фигуры
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
class Parallelogram : public Figure
{
protected:
	bool check_geometr_figure() override // функция проверки правильности геометрической фигуры
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
class Rhomb : public Figure
{
protected:
	bool check_geometr_figure() override // функция проверки правильности геометрической фигуры
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

void print(Figure& fig)
{
	std::cout << fig.getName() << ':' << '\n';
	std::cout << ((fig.get_is_right_figure())?"Правильная":"Неправильная") << '\n';
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
	Figure figure{};
	print(figure);
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
	Quadrangle q{ 10, 20, 30, 40, 50, 60, 70, 80 };
	print(q);
	// Прямоугольник
	Rectangle re{ 10, 20, 10, 20, 91, 90, 90, 90 };
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

	return EXIT_SUCCESS;
}