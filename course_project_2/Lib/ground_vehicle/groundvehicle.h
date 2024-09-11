#pragma once

#include <iostream>

class GroundVehicle {
protected:
	std::string name_{};
	int speed_{};					 // скорость
	int time_before_rest_{};		 // время движения до отдыха
	int duration_of_rest_{};		 // длительность отдыха
	int number_of_rest_intervals_{}; // количество интервалов отдыха

public:
	virtual int movement(int distance) = 0;
};
