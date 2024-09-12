#pragma once

#include <iostream>
#include <string>
#include "../../Ground_vehicle/groundvehicle.h"

class Centaur : public GroundVehicle {
public:
	Centaur();
	float movement(int distance) override;
};