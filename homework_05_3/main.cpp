#include <iostream>
#include <string>


class Figure
{
protected:
	std::string name{"������"};
	int sides_count{};
	int side_length_a{};
	int side_length_b{};
	int side_length_c{};
	int side_length_d{};

	int corner_A{};
	int corner_B{};
	int corner_C{};
	int corner_D{};

	bool isQuadrangle{ false }; //������� ����������������

	virtual bool check_geometr_figure() // ������� �������� ������������ �������������� ������
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

// �����������
class Triangle : public Figure
{
protected:
	bool check_geometr_figure() override // ������� �������� ������������ �������������� ������
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
		name = "�����������";
		sides_count = 3;
		side_length_a = set_side_length_a;
		side_length_b = set_side_length_b;
		side_length_c = set_side_length_c;
		corner_A = set_corner_A;
		corner_B = set_corner_B;
		corner_C = set_corner_C;
	}
};
// ��������������� - ������� �����
class Quadrangle : public Figure
{
protected:
	bool check_geometr_figure() override // ������� �������� ������������ �������������� ������
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
		name = "���������������";
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

// ������������� �����������
class Right_angled_triangle : public Figure
{
protected:
	bool check_geometr_figure() override // ������� �������� ������������ �������������� ������
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
		name = "������������� �����������";
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
class Isosceles_triangle : public Figure
{
protected:
	bool check_geometr_figure() override // ������� �������� ������������ �������������� ������
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
class Equilateral_triangle : public Figure
{
protected:
	bool check_geometr_figure() override // ������� �������� ������������ �������������� ������
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
class Rectangle : public Figure
{
protected:
	bool check_geometr_figure() override // ������� �������� ������������ �������������� ������
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
class Square : public Figure
{
protected:
	bool check_geometr_figure() override // ������� �������� ������������ �������������� ������
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
class Parallelogram : public Figure
{
protected:
	bool check_geometr_figure() override // ������� �������� ������������ �������������� ������
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
class Rhomb : public Figure
{
protected:
	bool check_geometr_figure() override // ������� �������� ������������ �������������� ������
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

void print(Figure& fig)
{
	std::cout << fig.getName() << ':' << '\n';
	std::cout << ((fig.get_is_right_figure())?"����������":"������������") << '\n';
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
	Figure figure{};
	print(figure);
	// �����������
	Triangle triangle{ 10, 20, 30, 50, 60, 70 };
	print(triangle);
	// ������������� �����������
	Right_angled_triangle r{ 10, 20, 40, 30, 50, 90 };
	print(r);
	// �������������� �����������
	Isosceles_triangle i{ 10, 20, 10, 50, 60, 50 };
	print(i);
	// �������������� �����������
	Equilateral_triangle e{ 20, 20, 20, 60, 60, 60 };
	print(e);
	// ���������������
	Quadrangle q{ 10, 20, 30, 40, 50, 60, 70, 80 };
	print(q);
	// �������������
	Rectangle re{ 10, 20, 10, 20, 91, 90, 90, 90 };
	print(re);
	// �������
	Square s{ 50, 50, 50, 50, 90, 90, 90, 90 };
	print(s);
	// ��������������
	Parallelogram p{ 50, 90, 50, 90, 30, 60, 30, 60 };
	print(p);
	// ����
	Rhomb rhomb{ 10, 10, 10, 10, 30, 60, 30, 60 };
	print(rhomb);

	return EXIT_SUCCESS;
}