#include "Triangle.h"
#include "Error.h"

namespace ShapeLib {
	void Triangle::check_geometr_figure()// ������� �������� ������������ �������������� ������
	{
		if (sides_count == 3 and corner_A + corner_B + corner_C == 180)
		{
			printing_is_allowed = true;
		}
		else {
			if (corner_A + corner_B + corner_C != 180) {
				throw Error("������ �������� ������. �������: ����� ����� �� ����� 180\n");
			}
		}
	}


	Triangle::Triangle(int set_side_length_a, int set_side_length_b, int set_side_length_c, int set_corner_A, int set_corner_B, int set_corner_C)
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
}