#include "Quadrangle.h"
#include "Error.h"

namespace ShapeLib {
	// ���������������
	void Quadrangle::check_geometr_figure() // ������� �������� ������������ �������������� ������
	{
		if (sides_count == 4 && corner_A + corner_B + corner_C + corner_D == 360)
		{
			printing_is_allowed = true;
		}
		else {
			if (corner_A + corner_B + corner_C + corner_D != 360) {
				throw Error("������ �������� ������. �������: ����� ����� �� ����� 360\n");
			}
		}
	}
	Quadrangle::Quadrangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_side_length_d, int set_corner_A, int set_corner_B, int set_corner_C, int set_corner_D)
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

}