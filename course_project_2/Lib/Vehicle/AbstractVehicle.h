#pragma once
#include "../Ground_vehicle/groundvehicle.h"
#include "../Air_vehicle/AirVehicle.h"

class AbstractFactoryVehicle {
public:
	virtual GroundVehicle* CreateCamel() const = 0;
	virtual GroundVehicle* CreateCamelFast() const = 0;
	virtual GroundVehicle* CreateCentaur() const = 0;
	virtual GroundVehicle* CreateBoots() const = 0;
	virtual AirVehicle* CreateMagicCarpet() const = 0;
	virtual AirVehicle* CreateEagle() const = 0;
	virtual AirVehicle* CreateBroom() const = 0;
};