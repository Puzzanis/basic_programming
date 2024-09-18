#pragma once

#include <iostream>

#include <string>
#include <vector>
#include "../Base/Vehicle.h"

struct menuItem {
	int item;
	std::string text;
};

menuItem intro[] = {
	{ 0, "����� ���������� � �������� ���������!" },
	{ 1, "����� ��� ��������� ����������" },
	{ 2, "����� ��� ���������� ����������" },
	{ 3, "����� ��� ��������� � ���������� ����������" }
};

int introduction();
int request_length_distance();
int registration(int size);
int choose_vehicle(std::vector< Vehicle* > names, int size);
void registration_vehicles(std::vector<int>& arr_choose_vehicle, std::vector<Vehicle*>& vehicles, int& distance, int& type_race, int& answer);
void correct_choise(int& choose, std::vector<Vehicle*>& vehicles, std::vector<int>& arr_choose_vehicle, int& type_race, int& distance);
void checking_number(int& num);			//�������� �� ���� �����
void print(std::vector<Vehicle*> vehicles, std::vector<int> arr_choose_vehicle, int type_race, int distance);
int last_request();