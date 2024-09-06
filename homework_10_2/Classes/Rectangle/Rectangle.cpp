#include "Rectangle.h"
#include "../Error/Error.h"

void Rectangle::check_geometr_figure() // функция проверки правильности геометрической фигуры
{
	if (sides_count == 4 && corner_A == 90 && corner_B == 90 && corner_C == 90 && corner_D == 90 && side_length_a == side_length_c && side_length_b == side_length_d)
	{
		printing_is_allowed = true;
	}
	else {
		if (corner_A != 90) {
			throw Error("Ошибка создания фигуры. Причина: Угл \"A\" не равен 90\n");
		}
		if (corner_B != 90) {
			throw Error("Ошибка создания фигуры. Причина: Угл \"B\" не равен 90\n");
		}
		if (corner_C != 90) {
			throw Error("Ошибка создания фигуры. Причина: Угл \"C\" не равен 90\n");
		}
		if (corner_D != 90) {
			throw Error("Ошибка создания фигуры. Причина: Угл \"D\" не равен 90\n");
		}
		if (side_length_b != side_length_d) {
			throw Error("Ошибка создания фигуры. Причина: Стороны \"b\" и \"d\" не равены\n");
		}if (side_length_a != side_length_c) {
			throw Error("Ошибка создания фигуры. Причина: Стороны \"а\" и \"c\" не равены\n");
		}
	}
}

Rectangle::Rectangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
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
