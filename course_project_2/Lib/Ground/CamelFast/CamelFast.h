#pragma once

#include <iostream>
#include <string>
#include "../../Ground_vehicle/groundvehicle.h"

class CamelFast : public GroundVehicle {
public:
	CamelFast();
	float movement(int distance) override;
};