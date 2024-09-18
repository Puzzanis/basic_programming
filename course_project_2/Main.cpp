#include <iostream>
#include <map>
#include <format>
#include <string>
#include "Lib/Base/Vehicle.h"
#include "Lib/Menu/Menu.h"
#include "Lib/Vehicle/CreatorVehicle.h"
#include "Lib/Sort/Sort.h"

int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

	CreatorVechicle* fabric = new CreatorVechicle();
	Vehicle* camel = fabric->CreateCamel();
	Vehicle* camelfast = fabric->CreateCamelFast();
	Vehicle* centaur = fabric->CreateCentaur();
	Vehicle* boots = fabric->CreateBoots();
	Vehicle* magiccarpet = fabric->CreateMagicCarpet();
	Vehicle* eagle = fabric->CreateEagle();
	Vehicle* broom = fabric->CreateBroom();

	
	std::vector<Vehicle*> vehicles;
	vehicles.push_back(camel);
	vehicles.push_back(camelfast);
	vehicles.push_back(centaur);
	vehicles.push_back(boots);
	vehicles.push_back(magiccarpet);
	vehicles.push_back(eagle);
	vehicles.push_back(broom);

	std::vector<int> arr_choose_vehicle; //массив для зарегистрированных ТС

	print_chars(intro[0].text);
	std::cout << std::endl;
	while (true) {
		//Обработка меню
		int type_race = introduction(); //меню выбора типа гонки
		system("cls");

		int distance = request_length_distance(); //меню выбора дистанции
		system("cls");

		//меню выбора ТС и последующий запуск гонки
		int answer{};
		while (answer != 2) {
			answer = registration(arr_choose_vehicle.size());
			system("cls");

			if (answer == 1) {
				registration_vehicles(arr_choose_vehicle, vehicles, distance, type_race, answer);
				system("cls");
			}
		}

		//расчет времени движения
		for (auto ts : arr_choose_vehicle) {
			vehicles[ts - 1]->movement(distance);
		}

		//сортировка результатов для вывода в консоль
		bubbleSort(arr_choose_vehicle, arr_choose_vehicle.size(), vehicles);
		std::string text = "Результаты гонки:\n";
		print_chars(text);

		//вывод в консоль результата гонки
		int count{};
		for (auto ts : arr_choose_vehicle) {
			std::string text = std::format("{}. {}. Время: {}\n", ++count, vehicles[ts - 1]->get_name(), vehicles[ts - 1]->get_last_race());
			print_chars(text);
			
		}
		printf("\n");

		//запрос на продолжение или выход
		answer = last_request();
		system("cls");
		
		if (answer == 2) { break; }
		else { arr_choose_vehicle.clear(); }
	}

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


