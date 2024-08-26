#include <iostream>
#include "Shape.h"

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
