#pragma once

#include <iostream>
#include <string>
#include "../../ground_vehicle/groundvehicle.h"

class Camel : public GroundVehicle {
public:
	Camel(std::string name, int speed, int time_before_rest, int duration_of_rest);
	int movement(int distance) override;
};