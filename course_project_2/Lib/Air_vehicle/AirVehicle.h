#pragma once

#include <iostream>
#include <vector>
#include "../Base/Vehicle.h"

class AirVehicle : public Vehicle {
protected:
	std::string name_{""};
	int speed_{};										// скорость
	const int type_{2};
	float last_race_{ 0.0 };
public:
	~AirVehicle() {};
};
