#pragma once

#include <iostream>
#include <string>
#include "../../Air_vehicle/AirVehicle.h"

class Eagle : public AirVehicle {
public:
	Eagle();
	float movement(int distance) override;
};