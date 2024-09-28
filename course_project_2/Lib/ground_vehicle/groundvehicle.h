#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "../Base/Vehicle.h"

class GroundVehicle: public Vehicle {
protected:
	std::string name_;
	int speed_{};							// скорость
	int time_before_rest_{};				// время движения до отдыха
	std::vector<float> duration_of_rest_{};	// длительность отдыха
	int number_of_rest_intervals_{};		// количество интервалов отдыха
	int type_{ 1 };
	float last_race_{0.0};

public:
	GroundVehicle() = default;
	~GroundVehicle() {};
};
