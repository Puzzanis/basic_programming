#pragma once

#include <iostream>
#include <vector>

class GroundVehicle {
protected:
	std::string name_{};
	int speed_{};							// ��������
	int time_before_rest_{};				// ����� �������� �� ������
	std::vector<float> duration_of_rest_{};	// ������������ ������
	int number_of_rest_intervals_{};		// ���������� ���������� ������

public:
	virtual ~GroundVehicle() {};
	virtual float movement(int distance) = 0;
};
