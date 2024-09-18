#pragma once

#include <iostream>
#include <vector>

class Vehicle {									// скорость

public:
	virtual ~Vehicle() {};
	virtual float movement(int distance) = 0;
	virtual std::string get_name() = 0;
	virtual int get_type() = 0;
	virtual float get_last_race() = 0;
};