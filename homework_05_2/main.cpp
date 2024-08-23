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

	bool isQuadrangle{ false }; //������� ����������������

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

// �����������
class Triangle: public Figure
{
public:
	Triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C)
	{
		name = "�����������";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;
		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
		
	}
};
// ��������������� - ������� �����
class Quadrangle: public Figure
{
public:
	Quadrangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
	{
		name = "���������������";
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

// ������������� �����������
class Right_angled_triangle : public Figure
{
public:
	Right_angled_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B) 
	{
		name = "������������� �����������";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = 90;
	}
};

// �������������� �����������
class Isosceles_triangle : public Figure
{
public:
	Isosceles_triangle(int set_side_length_a, int set_side_length_b, int set_corner_A, int set_corner_B)
	{
		name = "�������������� �����������";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_a;

		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_A;
	}
};
// �������������� �����������
class Equilateral_triangle : public Figure
{
public:
	Equilateral_triangle(int set_side_length_a, int set_corner_A)
	{
		name = "�������������� �����������";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_a;
		side_length_c = set_side_length_a;

		corner_A = set_corner_A;
		corner_B = set_corner_A;
		corner_C = set_corner_A;
	}
};
// ������������� 
class Rectangle : public Figure
{
public:
	Rectangle(int set_side_length_a, int set_side_length_b)
	{
		name = "�������������";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_a;
		side_length_d = set_side_length_b;
		isQuadrangle = true;

		corner_A = corner_B = corner_C = corner_D = 90;

	}
};

// �������  
class Square : public Figure
{
public:
	Square(int set_side_length_a)
	{
		name = "�������";
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_a;
		side_length_c = set_side_length_a;
		side_length_d = set_side_length_a;
		isQuadrangle = true;

		corner_A = corner_B = corner_C = corner_D = 90;
	}
};
// ��������������  
class Parallelogram : public Figure
{
public:
	Parallelogram(int set_side_length_a, int set_side_length_b, int set_corner_A, int set_corner_B) 
	{
		name = "��������������";
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
// ����  
class Rhomb : public Figure
{
public:
	Rhomb(int set_side_length_a, int set_corner_A, int set_corner_B) 
	{
		name = "����";
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
	std::cout << "�������: " << "a=" << fig.get_side_length_a() << " b=" << fig.get_side_length_b() << " c=" << fig.get_side_length_c();
	if (fig.get_isQuadrangle())
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
	std::cout << '\n';
}

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

	// �����������
	Triangle triangle{ 10, 20, 30, 50, 60, 70 };
	print(triangle);
	// ������������� �����������
	Right_angled_triangle r{10, 20, 30, 50, 50};
	print(r);
	// �������������� �����������
	Isosceles_triangle i{ 10, 20, 50, 60 };
	print(i);
	// �������������� �����������
	Equilateral_triangle e{ 20, 60 };
	print(e);
	// ���������������
	Quadrangle q{ 10, 20, 30, 40, 50, 60, 70, 80 };
	print(q);
	// �������������
	Rectangle re{ 10, 20 };
	print(re);
	// �������
	Square s{ 50 };
	print(s);
	// ��������������
	Parallelogram p{ 50, 90, 30, 60 };
	print(p);
	// ����
	Rhomb rhomb{ 50, 30, 60 };
	print(rhomb);

	return EXIT_SUCCESS;
}