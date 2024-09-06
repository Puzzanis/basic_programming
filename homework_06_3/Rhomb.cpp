#include "Rhomb.h"
#include "Error_define.h"

void Rhomb::check_geometr_figure() // функция проверки правильности геометрической фигуры
{
	if (sides_count == 4 && corner_A == corner_C && corner_B == corner_D && side_length_a == side_length_b && side_length_c == side_length_d && side_length_a == side_length_c)
	{
		printing_is_allowed = true;
	}
	else {
		if (corner_A != corner_C) {
			throw Error("Ошибка создания фигуры. Причина: Углы \"A\" и \"C\" не равены\n");
		}
		if (corner_B != corner_D) {
			throw Error("Ошибка создания фигуры. Причина: Угл \"B\" и \"D\" не равены\n");
		}

		if (side_length_a != side_length_b) {
			throw Error("Ошибка создания фигуры. Причина: Стороны \"а\" и \"b\" не равены\n");
		}
		if (side_length_c != side_length_d) {
			throw Error("Ошибка создания фигуры. Причина: Стороны \"c\" и \"d\" не равены\n");
		}
		if (side_length_a != side_length_c) {
			throw Error("Ошибка создания фигуры. Причина: Стороны \"а\" и \"c\" не равены\n");
		}
	}
}

Rhomb::Rhomb(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
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
