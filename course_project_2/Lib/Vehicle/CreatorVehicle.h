#pragma once
#include <string>
#include "AbstractVehicle.h"
#include "../Ground/Camel/Camel.h"
#include "../Ground/CamelFast/CamelFast.h"
#include "../Ground/Centaur/Centaur.h"
#include "../Ground/Boots/Boots.h"
#include "../Air/MagicCarpet/MagicCarpet.h"
#include "../Air/Eagle/Eagle.h"
#include "../Air/Broom/Broom.h"



class CreatorVechicle : public AbstractFactoryVehicle {
public:
	GroundVehicle* CreateCamel() const override {
		return  new Camel{};
	}
	GroundVehicle* CreateCamelFast() const override {
		return  new CamelFast{};
	}
	GroundVehicle* CreateCentaur() const override {
		return  new Centaur{};
	}
	GroundVehicle* CreateBoots() const override {
		return  new Boots{};
	}
	AirVehicle* CreateMagicCarpet() const override {
		return  new MagicCarpet{};
	}
	AirVehicle* CreateEagle() const override {
		return  new Eagle{};
	}
	AirVehicle* CreateBroom() const override {
		return  new Broom{};
	}
};