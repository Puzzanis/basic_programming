#pragma once

#include <iostream>
#include <string>
#include "../../Air_vehicle/AirVehicle.h"

class Broom : public AirVehicle {
public:
	Broom();
	float movement(int distance) override;
};