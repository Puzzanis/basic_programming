#include <iostream>
#include "Shape.h"

void print(Shape& fig)
{
	std::cout << fig.getName() << ':' << '\n';
	bool print = fig.get_is_right_figure();
	if (fig.get_printing_is_allowed()) {
		std::cout << ((print) ? "Правильная" : "Неправильная") << '\n';
		std::cout << "Количество сторон: " << fig.getSides_count() << ':' << '\n';
		if (fig.getSides_count() > 0)
		{
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
			std::cout << "Создан\n";
		}
		std::cout << '\n';
	}
	
}
