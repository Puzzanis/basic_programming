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
	Vehicle* CreateCamel() const override {
		return  new Camel{};
	}
	Vehicle* CreateCamelFast() const override {
		return  new CamelFast{};
	}
	Vehicle* CreateCentaur() const override {
		return  new Centaur{};
	}
	Vehicle* CreateBoots() const override {
		return  new Boots{};
	}
	Vehicle* CreateMagicCarpet() const override {
		return  new MagicCarpet{};
	}
	Vehicle* CreateEagle() const override {
		return  new Eagle{};
	}
	Vehicle* CreateBroom() const override {
		return  new Broom{};
	}
};