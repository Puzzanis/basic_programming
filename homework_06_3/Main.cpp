#include <iostream>
#include <string>
#include "Shape.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "Right_angled_triangle.h"

// �������������� �����������
class Isosceles_triangle : public Shape
{
protected:
	bool check_geometr_Shape() // ������� �������� ������������ �������������� ������
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
		name = "�������������� �����������";
		sides_count = 3;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
	}
};
// �������������� �����������
class Equilateral_triangle : public Shape
{
protected:
	bool check_geometr_Shape() // ������� �������� ������������ �������������� ������
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
		name = "�������������� �����������";
		sides_count = 3;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
	}
};
// ������������� 
class Rectangle : public Shape
{
protected:
	bool check_geometr_Shape() // ������� �������� ������������ �������������� ������
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
		name = "�������������";
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

// �������  
class Square : public Shape
{
protected:
	bool check_geometr_Shape() // ������� �������� ������������ �������������� ������
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
		name = "�������";
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
// ��������������  
class Parallelogram : public Shape
{
protected:
	bool check_geometr_Shape() // ������� �������� ������������ �������������� ������
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
		name = "��������������";
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
// ����  
class Rhomb : public Shape
{
protected:
	bool check_geometr_figure() // ������� �������� ������������ �������������� ������
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
		name = "����";
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
	std::cout << ((fig.get_is_right_figure()) ? "����������" : "������������") << '\n';
	std::cout << "���������� ������: " << fig.getSides_count() << ':' << '\n';
	if (fig.getSides_count() > 0)
	{
		std::cout << "�������: " << "a=" << fig.get_side_length_a() << " b=" << fig.get_side_length_b() << " c=" << fig.get_side_length_c();
		if (fig.get_isQuadrangle() > 0)
		{
			std::cout << " d=" << fig.get_side_length_d() << '\n';
		}
		else
		{
			std::cout << '\n';
		}

		std::cout << "����: " << "A=" << fig.get_corner_A() << " B=" << fig.get_corner_B() << " C=" << fig.get_corner_C();
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
	// �����������
	Triangle triangle{ 10, 20, 30, 50, 60, 70 };
	print(triangle);
	// ������������� �����������
	Right_angled_triangle r{ 10, 20, 40, 30, 50, 90 };
	print(r);
	//// �������������� �����������
	//Isosceles_triangle i{ 10, 20, 10, 50, 60, 50 };
	//print(i);
	//// �������������� �����������
	//Equilateral_triangle e{ 20, 20, 20, 60, 60, 60 };
	//print(e);
	// ���������������
	Quadrangle q{ 10, 20, 30, 50, 100, 80, 100, 80 };
	print(q);
	//// �������������
	//Rectangle re{ 10, 20, 10, 20, 91, 90, 90, 90 };
	//print(re);
	//// �������
	//Square s{ 50, 50, 50, 50, 90, 90, 90, 90 };
	//print(s);
	//// ��������������
	//Parallelogram p{ 50, 90, 50, 90, 30, 60, 30, 60 };
	//print(p);
	//// ����
	//Rhomb rhomb{ 10, 10, 10, 10, 30, 60, 30, 60 };
	//print(rhomb);

	return EXIT_SUCCESS;
}