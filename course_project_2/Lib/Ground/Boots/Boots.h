#pragma once

#include <iostream>
#include <string>
#include "../../Ground_vehicle/groundvehicle.h"

class Boots : public GroundVehicle {
public:
	Boots();
	float movement(int distance) override;
	std::string get_name() override;
	int get_type() override;
	float get_last_race() override;
};