#pragma once

#include <iostream>
#include <string>
#include "../../Ground_vehicle/groundvehicle.h"

class CamelFast : public GroundVehicle {
public:
	CamelFast();
	float movement(const int& distance) override;
	std::string& get_name() override;
	int get_type() const override;
	float get_last_race() const override;
};