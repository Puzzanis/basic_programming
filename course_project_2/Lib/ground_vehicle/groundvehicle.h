#pragma once

#include <iostream>

class GroundVehicle {
protected:
	std::string name_{};
	int speed_{};					 // ��������
	int time_before_rest_{};		 // ����� �������� �� ������
	int duration_of_rest_{};		 // ������������ ������
	int number_of_rest_intervals_{}; // ���������� ���������� ������

public:
	virtual int movement(int distance) = 0;
};
