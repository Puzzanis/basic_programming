#pragma once

#include <iostream>
#include <string>
#include "../../Air_vehicle/AirVehicle.h"

class MagicCarpet : public AirVehicle {
public:
	MagicCarpet();
	float movement(int distance) override;
};