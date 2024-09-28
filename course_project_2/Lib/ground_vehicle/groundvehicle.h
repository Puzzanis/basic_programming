#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Base/Vehicle.h"

class GroundVehicle: public Vehicle {
protected:
	std::string name_;
	int speed_{};							// ��������
	int time_before_rest_{};				// ����� �������� �� ������
	std::vector<float> duration_of_rest_{};	// ������������ ������
	int number_of_rest_intervals_{};		// ���������� ���������� ������
	int type_{ 1 };
	float last_race_{0.0};

public:
	GroundVehicle() = default;
	~GroundVehicle() {};
};
