#pragma once
#include "../Ground_vehicle/groundvehicle.h"
#include "../Air_vehicle/AirVehicle.h"

class AbstractFactoryVehicle {
public:
	virtual Vehicle* CreateCamel() const = 0;
	virtual Vehicle* CreateCamelFast() const = 0;
	virtual Vehicle* CreateCentaur() const = 0;
	virtual Vehicle* CreateBoots() const = 0;
	virtual Vehicle* CreateMagicCarpet() const = 0;
	virtual Vehicle* CreateEagle() const = 0;
	virtual Vehicle* CreateBroom() const = 0;
};