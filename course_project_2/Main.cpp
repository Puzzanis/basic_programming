#include <iostream>
#include "Lib/Vehicle/CreatorVehicle.h"

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

	CreatorVechicle* fabric = new CreatorVechicle();
	GroundVehicle* camel = fabric->CreateCamel();
	std::cout << "Верблюд: " << camel->movement(4500) << std::endl;

	GroundVehicle* camelfast = fabric->CreateCamelFast();
	std::cout << "Верблюд-быстроход: " << camelfast->movement(4500) << std::endl;

	GroundVehicle* centaur = fabric->CreateCentaur();
	std::cout << "Кентавр: " << centaur->movement(4500) << std::endl;
	
	GroundVehicle* boots = fabric->CreateBoots();
	std::cout << "Ботинки-вездеходы: " << boots->movement(4500) << std::endl;

	AirVehicle* magiccarpet = fabric->CreateMagicCarpet();
	std::cout << "Ковёр-самолёт: " << magiccarpet->movement(4500) << std::endl;

	AirVehicle* eagle = fabric->CreateEagle();
	std::cout << "Орел: " << eagle->movement(4500) << std::endl;

	AirVehicle* broom = fabric->CreateBroom();
	std::cout << "Метла: " << broom->movement(4500) << std::endl;

	delete camel;
	delete camelfast;
	delete centaur;
	delete boots;
	delete magiccarpet;
	delete eagle;
	delete broom;

	delete fabric;
	return EXIT_SUCCESS;
}
