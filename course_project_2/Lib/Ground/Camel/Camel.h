#pragma once

#include <iostream>
#include <string>
#include "../../Ground_vehicle/groundvehicle.h"

class Camel : public GroundVehicle {
public:
	Camel();
	float movement(int distance) override;
};