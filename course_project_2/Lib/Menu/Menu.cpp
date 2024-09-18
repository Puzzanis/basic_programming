#include "Menu.h"

//�������� �� ���� �����
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
			std::cout << "������������ ����. ������� �����!" << std::endl;
			std::cout << "��������� ����: ";
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}
		catch (std::out_of_range) {
			std::cout << "������������ ����!" << std::endl;
			std::cout << "��������� ����: ";
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}
		catch (...)
		{
			//���� ����� ��������� �����-�� ����������, ������� �� ���������� ����, �� �������, ��� �������� ����������� ������
			std::cout << "����������� ������! \n";
			std::cout << "��������� ����: ";
			std::cin.clear();
			std::cin.ignore(10, '\n');
			continue;
		}

	}
}

//���� ������ ���� ������������� ��������
int introduction() {
	std::cout << intro[0].text << std::endl;
	for (int i = 1; i < (sizeof(intro) / sizeof(intro[0])); i++) {
		std::cout << intro[i].item << ". " << intro[i].text << std::endl;
	}

	int type_race{};
	std::cout << "�������� ��� �����: ";
	checking_number(type_race);
	while (type_race > 3 || type_race < 1 ) {
		std::cout << "�� ������� ������������ ��� �����!" << std::endl;
		std::cout << "�������� ��� �����: ";
		checking_number(type_race);
	}

	return type_race;
};

int last_request() {
	int answer{};
	std::cout << "1. �������� ��� ���� �����" << std::endl;
	std::cout << "2. �����" << std::endl;
	std::cout << "�������� ��� �����: ";
	checking_number(answer);
	while (answer <= 0 || answer > 2) {
		std::cout << "�� ������� ������������ ��� �����!" << std::endl;
		std::cout << "�������� ��� �����: ";
		checking_number(answer);
	}

	return answer;
}

//���� ������ ����� ���������
int request_length_distance() {
	int distance{};
	std::cout << "������� ����� ��������� (������ ���� �������������): ";
 	checking_number(distance);
	while (distance <= 0) {
		std::cout << "�� ����� ������������ ����� ���������!" << std::endl;
		std::cout << "������� ����� ��������� (������ ���� �������������): ";
		checking_number(distance);
	}

	return distance;
};

//���� ����������� ������������ ������� �������� ���� ������������ ��������
int registration(int size) {
	int answer{};

	if (!size) {
		std::cout << "������ ���� ���������������� ���� �� 2 ���������� ��������" << std::endl;
		std::cout << "1. ���������������� ���������" << std::endl;
		std::cout << "�������� ��������: ";
		checking_number(answer);
		while (answer != 1) {
			std::cout << "�� ������� ������������ ����a��!" << std::endl;
			std::cout << "�������� ��������: ";
			checking_number(answer);
		}
	}
	else {
		std::cout << "1. ���������������� ���������" << std::endl;
		std::cout << "2. ������ �����" << std::endl;
		std::cout << "�������� ��������: ";
		checking_number(answer);
		while (answer != 1 && answer != 2) {
			std::cout << "�� ������� ������������ ����a��!" << std::endl;
			std::cout << "�������� ��������: ";
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

	std::cout << "0" << ". " << "��������� �����������" << std::endl;
	std::cout << "�������� ��������� ��� 0 ��� ��������� �������� �����������: ";
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

//�������� ������������ ��������� ������
void correct_choise(int& choose, std::vector<Vehicle*>& vehicles, std::vector<int>& arr_choose_vehicle, int& type_race, int& distance) {
	if (choose > 0 && choose - 1 < vehicles.size()) {
		if (vehicles[choose - 1]->get_type() == type_race || type_race == 3) {
			if (arr_choose_vehicle.size() > 0) {
				for (int value : arr_choose_vehicle) {
					if (value == choose) {
						std::cout << vehicles[value - 1] ->get_name() << " ��� ���������������!" << std::endl;
						print(vehicles, arr_choose_vehicle, type_race, distance);
						return;
					}
				}
			}
			arr_choose_vehicle.push_back(choose);
			std::cout << vehicles[choose - 1]->get_name() << " ������� ���������������!" << std::endl;
			print(vehicles, arr_choose_vehicle, type_race, distance);
			
		}
		else {
			std::cout << "������� ���������������� ������������ ��� ������������� ��������!" << std::endl;
			print(vehicles, arr_choose_vehicle, type_race, distance);
		}	
	}
	else if (choose == 0 && arr_choose_vehicle.size() < 2) {
		std::cout << "���������� ���������������� ������� 2 ������������ ��������!" << std::endl;
		print(vehicles, arr_choose_vehicle, type_race, distance);
	}
	else if (choose > 0 && (choose - 1 >= vehicles.size())) {
		std::cout << "��������� ��������� �� ������������� ������� ��������� ��!" << std::endl;
		print(vehicles, arr_choose_vehicle, type_race, distance);
	}
	
}

//������ � ��������� ���� �����, ��������� � ������������������ ��
void print(std::vector<Vehicle*> vehicles, std::vector<int> arr_choose_vehicle, int type_race, int distance) {
	std::cout << intro[type_race].text << ". ����������: " << distance << std::endl;
	if (arr_choose_vehicle.size() > 0) {
		std::cout << "������������������ ������������ ��������: ";
		for (int i = 0; i < arr_choose_vehicle.size(); i++) {
			std::cout << ((i > 0) ? ", " : "");
			std::cout << vehicles[arr_choose_vehicle[i] - 1]->get_name();
		}
		std::cout << std::endl;
	};
}