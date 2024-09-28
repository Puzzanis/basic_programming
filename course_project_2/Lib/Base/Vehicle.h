#pragma once

#include <iostream>
#include <vector>

class Vehicle {									// скорость

public:
	virtual ~Vehicle() {};
	virtual float movement(const int& distance) = 0;
	virtual std::string& get_name() const = 0;
	virtual int get_type() const = 0;
	virtual float get_last_race() const = 0;
};