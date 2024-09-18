#pragma once

#include <iostream>
#include <string>
#include "../../Air_vehicle/AirVehicle.h"

class Broom : public AirVehicle{
public:
	Broom();
	float movement(int distance) override;
	std::string get_name() override;
	int get_type() override;
	float get_last_race() override;
};