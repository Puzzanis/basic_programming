#pragma once

#include <iostream>
#include <vector>

class GroundVehicle {
protected:
	std::string name_{};
	int speed_{};							// скорость
	int time_before_rest_{};				// время движения до отдыха
	std::vector<float> duration_of_rest_{};	// длительность отдыха
	int number_of_rest_intervals_{};		// количество интервалов отдыха

public:
	virtual ~GroundVehicle() {};
	virtual float movement(int distance) = 0;
};
