#pragma once

#include <iostream>
#include <vector>

class AirVehicle {
protected:
	std::string name_{};
	int speed_{};										// ��������

public:
	virtual ~AirVehicle() {};
	virtual float movement(int distance) = 0;
};
