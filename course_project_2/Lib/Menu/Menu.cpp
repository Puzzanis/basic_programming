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
			std::cout << "Недопустимый ввод. Введите число!" << std::endl;
			std::cout << "Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}
		catch (std::out_of_range) {
			std::cout << "Недопустимый ввод!" << std::endl;
			std::cout << "Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}
		catch (...)
		{
			//Если будет выброшено какое-то исключение, которое не обработано выше, то говорим, что возникла неизвестная ошибка
			std::cout << "Неизвестная ошибка! \n";
			std::cout << "Повторите ввод: ";
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}

	}
}

//меню выбора типа транспортного средства
int introduction() {
	std::cout << intro[0].text << std::endl;
	for (int i = 1; i < (sizeof(intro) / sizeof(intro[0])); i++) {
		std::cout << intro[i].item << ". " << intro[i].text << std::endl;
	}

	int type_race{};
	std::cout << "Выберите тип гонки: ";
	checking_number(type_race);
	while (type_race > 3 || type_race < 1 ) {
		std::cout << "Вы выбрали неправильный тип гонки!" << std::endl;
		std::cout << "Выберите тип гонки: ";
		checking_number(type_race);
	}

	return type_race;
};

int last_request() {
	int answer{};
	std::cout << "1. Провести еще одну гонку" << std::endl;
	std::cout << "2. Выйти" << std::endl;
	std::cout << "Выберите тип гонки: ";
	checking_number(answer);
	while (answer <= 0 || answer > 2) {
		std::cout << "Вы выбрали неправильный тип гонки!" << std::endl;
		std::cout << "Выберите тип гонки: ";
		checking_number(answer);
	}

	return answer;
}

//меню выбора длины дистанции
int request_length_distance() {
	int distance{};
	std::cout << "Укажите длину дистанции (должна быть положительной): ";
 	checking_number(distance);
	while (distance <= 0) {
		std::cout << "Вы ввели неправильную длину дистанции!" << std::endl;
		std::cout << "Укажите длину дистанции (должна быть положительной): ";
		checking_number(distance);
	}

	return distance;
};

//меню регистрации транспортных средств согласно типу транспорного средства
int registration(int size) {
	int answer{};

	if (!size) {
		std::cout << "Должно быть зарегестрировано хотя бы 2 траспортых средства" << std::endl;
		std::cout << "1. Зарегестрировать транспорт" << std::endl;
		std::cout << "Выберите действие: ";
		checking_number(answer);
		while (answer != 1) {
			std::cout << "Вы выбрали неправильный вариaнт!" << std::endl;
			std::cout << "Выберите действие: ";
			checking_number(answer);
		}
	}
	else {
		std::cout << "1. Зарегестрировать транспорт" << std::endl;
		std::cout << "2. Начать гонку" << std::endl;
		std::cout << "Выберите действие: ";
		checking_number(answer);
		while (answer != 1 && answer != 2) {
			std::cout << "Вы выбрали неправильный вариaнт!" << std::endl;
			std::cout << "Выберите действие: ";
			checking_number(answer);
		}
	}
	return answer;
};

int choose_vehicle(std::vector< Vehicle* > names, int size) {
	int choose{};

	for (int i = 0; i < size; i++) {
		std::cout << i + 1 << ". " << names[i]->get_name() << std::endl;
	}

	std::cout << "0" << ". " << "Закончить регистрацию" << std::endl;
	std::cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
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
						std::cout << vehicles[value - 1] ->get_name() << " уже зарегистрирован!" << std::endl;
						print(vehicles, arr_choose_vehicle, type_race, distance);
						return;
					}
				}
			}
			arr_choose_vehicle.push_back(choose);
			std::cout << vehicles[choose - 1]->get_name() << " успешно зарегистрирован!" << std::endl;
			print(vehicles, arr_choose_vehicle, type_race, distance);
			
		}
		else {
			std::cout << "Попытка зарегистрировать неправильный тип транспортного средства!" << std::endl;
			print(vehicles, arr_choose_vehicle, type_race, distance);
		}	
	}
	else if (choose == 0 && arr_choose_vehicle.size() < 2) {
		std::cout << "Необходимо зарегистрировать минимут 2 транспортных средства!" << std::endl;
		print(vehicles, arr_choose_vehicle, type_race, distance);
	}
	else if (choose > 0 && (choose - 1 >= vehicles.size())) {
		std::cout << "Выбранный транспорт не соответствует перечню доступных ТС!" << std::endl;
		print(vehicles, arr_choose_vehicle, type_race, distance);
	}
	
}

//печать о выбранном типе гонки, дистанции и зарегестрированных ТС
void print(std::vector<Vehicle*> vehicles, std::vector<int> arr_choose_vehicle, int type_race, int distance) {
	std::cout << intro[type_race].text << ". Расстояние: " << distance << std::endl;
	if (arr_choose_vehicle.size() > 0) {
		std::cout << "Зарегистрированные транспортные средства: ";
		for (int i = 0; i < arr_choose_vehicle.size(); i++) {
			std::cout << ((i > 0) ? ", " : "");
			std::cout << vehicles[arr_choose_vehicle[i] - 1]->get_name();
		}
		std::cout << std::endl;
	};
}