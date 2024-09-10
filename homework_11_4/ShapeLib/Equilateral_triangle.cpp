#include "Equilateral_triangle.h"
#include "Error.h"

namespace ShapeLib {
	// �������������� �����������
	void Equilateral_triangle::check_geometr_figure() // ������� �������� ������������ �������������� ������
	{
		if (sides_count == 3 && corner_A == 60 && corner_B == 60 && corner_C == 60 && side_length_a == side_length_b && side_length_b == side_length_c)
		{
			printing_is_allowed = true;
		}
		else {
			if (corner_A != 60 || corner_B != 60 || corner_C != 60) {
				throw Error("������ �������� ������. �������: ���� �� ����� 60\n");
			}
			if (side_length_a != side_length_b || side_length_b != side_length_c) {
				throw Error("������ �������� ������. �������: ������� �� ����� ���� �����\n");
			}
		}
	}

	Equilateral_triangle::Equilateral_triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C)
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
}