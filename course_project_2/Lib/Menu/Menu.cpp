#include "Menu.h"

//проверка на ввод числа
void checking_number(int& num) {
	std::string inputNum;
	while (true)
	{
		std::cin >> inputNum;
		try {
			num = std::stoi(inputNum);
			break;
		}
		catch (std::invalid_argument) {
			print_chars(std::string("Недопустимый ввод. Введите число!\n"));
			print_chars(std::string("Повторите ввод: "));
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}
		catch (std::out_of_range) {
			print_chars(std::string("Недопустимый ввод!\n"));
			print_chars(std::string("Повторите ввод: "));
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}
		catch (...)
		{
			//Если будет выброшено какое-то исключение, которое не обработано выше, то говорим, что возникла неизвестная ошибка
			print_chars(std::string("Неизвестная ошибка! \n"));
			print_chars(std::string("Повторите ввод: "));
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}

	}
}

//печать символов побуквенно ;-)
void print_chars(std::string& text) {
	for (int i = 0; i < text.length(); i++) {
		std::cout << text[i];
		Sleep(10);
	}
}

//меню выбора типа транспортного средства
int introduction() {
	for (int i = 1; i < (sizeof(intro) / sizeof(intro[0])); i++) {
		print_chars(std::to_string(intro[i].item) + ". " + intro[i].text + "\n");
	}

	int type_race{};
	print_chars(std::string("Выберите тип гонки: "));
	checking_number(type_race);
	while (type_race > 3 || type_race < 1 ) {
		print_chars(std::string("Вы выбрали неправильный тип гонки!\n"));
		print_chars(std::string("Выберите тип гонки: "));
		checking_number(type_race);
	}

	return type_race;
};

int last_request() {
	int answer{};
	print_chars(std::string("1. Провести еще одну гонку\n"));
	print_chars(std::string("2. Выйти\n"));
	print_chars(std::string("Выберите действие: "));
	checking_number(answer);
	while (answer <= 0 || answer > 2) {
		print_chars(std::string("Вы выбрали неправильный тип гонки!\n"));
		print_chars(std::string("Выберите действие: "));
		checking_number(answer);
	}

	return answer;
}

//меню выбора длины дистанции
int request_length_distance() {
	int distance{};
	print_chars(std::string("Укажите длину дистанции (должна быть положительной): "));
 	checking_number(distance);
	while (distance <= 0) {
		print_chars(std::string("Вы ввели неправильную длину дистанции!\n"));
		print_chars(std::string("Укажите длину дистанции (должна быть положительной): "));
		checking_number(distance);
	}

	return distance;
};

//меню регистрации транспортных средств согласно типу транспорного средства
int registration(int size) {
	int answer{};

	if (!size) {
		print_chars(std::string("Должно быть зарегестрировано хотя бы 2 траспортых средства\n"));
		print_chars(std::string("1. Зарегестрировать транспорт\n"));
		print_chars(std::string("Выберите действие: "));
		checking_number(answer);
		while (answer != 1) {
			print_chars(std::string("Вы выбрали неправильный вариaнт!\n"));
			print_chars(std::string("Выберите действие: "));
			checking_number(answer);
		}
	}
	else {
		print_chars(std::string("1. Зарегестрировать транспорт\n"));
		print_chars(std::string("2. Начать гонку\n"));
		print_chars(std::string("Выберите действие: "));
		checking_number(answer);
		while (answer != 1 && answer != 2) {
			print_chars(std::string("Вы выбрали неправильный вариaнт!\n"));
			print_chars(std::string("Выберите действие: "));
			checking_number(answer);
		}
	}
	return answer;
};

int choose_vehicle(std::vector< Vehicle* > names, int size) {
	int choose{};

	for (int i = 0; i < size; i++) {
		print_chars(std::to_string(i + 1) + ". " + names[i]->get_name() + '\n');
	}

	print_chars(std::string("0. ") + std::string("Закончить регистрацию") + '\n');
	print_chars(std::string("Выберите транспорт или 0 для окончания процесса регистрации: "));
	checking_number(choose);
	return choose;
}

void registration_vehicles(std::vector<int>& arr_choose_vehicle, std::vector<Vehicle*>& vehicles, int& distance, int& type_race, int& answer) {
	int choose{ -1 };
	print(vehicles, arr_choose_vehicle, type_race, distance);
	for (;;) {
		correct_choise(choose, vehicles, arr_choose_vehicle, type_race, distance);
		choose = choose_vehicle(vehicles, vehicles.size());
		if (choose == 0 && arr_choose_vehicle.size() > 1) break;
		system("cls");
	}
}

//проверка правильности введенных данных
void correct_choise(int& choose, std::vector<Vehicle*>& vehicles, std::vector<int>& arr_choose_vehicle, int& type_race, int& distance) {
	if (choose > 0 && choose - 1 < vehicles.size()) {
		if (vehicles[choose - 1]->get_type() == type_race || type_race == 3) {
			if (arr_choose_vehicle.size() > 0) {
				for (int value : arr_choose_vehicle) {
					if (value == choose) {
						print_chars(vehicles[value - 1] ->get_name() + std::string(" уже зарегистрирован!") + '\n');
						print(vehicles, arr_choose_vehicle, type_race, distance);
						return;
					}
				}
			}
			arr_choose_vehicle.push_back(choose);
			print_chars(vehicles[choose - 1]->get_name() + std::string(" успешно зарегистрирован!") + '\n');
			print(vehicles, arr_choose_vehicle, type_race, distance);
			
		}
		else {
			print_chars(std::string("Попытка зарегистрировать неправильный тип транспортного средства!\n"));
			print(vehicles, arr_choose_vehicle, type_race, distance);
		}	
	}
	else if (choose == 0 && arr_choose_vehicle.size() < 2) {
		print_chars(std::string("Необходимо зарегистрировать минимум 2 транспортных средства!\n"));
		print(vehicles, arr_choose_vehicle, type_race, distance);
	}
	else if (choose > 0 && (choose - 1 >= vehicles.size())) {
		print_chars(std::string("Выбранный транспорт не соответствует перечню доступных ТС!\n"));
		print(vehicles, arr_choose_vehicle, type_race, distance);
	}
	
}

//печать о выбранном типе гонки, дистанции и зарегестрированных ТС
void print(std::vector<Vehicle*> vehicles, std::vector<int> arr_choose_vehicle, int type_race, int distance) {
	print_chars(intro[type_race].text + std::string(". Расстояние: ") + std::to_string(distance) + '\n');
	if (arr_choose_vehicle.size() > 0) {
		print_chars(std::string("Зарегистрированные транспортные средства: "));
		for (int i = 0; i < arr_choose_vehicle.size(); i++) {
			print_chars(std::string(((i > 0) ? ", " : "")));
			std::cout << vehicles[arr_choose_vehicle[i] - 1]->get_name();
		}
		print_chars(std::string("\n"));
	};
}