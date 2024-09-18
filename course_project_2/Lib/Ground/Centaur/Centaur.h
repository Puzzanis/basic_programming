#pragma once

#include <iostream>
#include <string>
#include "../../Ground_vehicle/groundvehicle.h"

class Centaur : public GroundVehicle {
public:
	Centaur();
	float movement(int distance) override;
	std::string get_name();
	int get_type() override;
	float get_last_race() override;
};