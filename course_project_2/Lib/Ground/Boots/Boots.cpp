#include <cmath>
#include "Boots.h"


float Boots::movement(const int& distance) {
	double fractpart; // ������� �����
	double intpart;   // ����� �����
	float res_time = (float)distance / (float)speed_;

	fractpart = std::modf((res_time / time_before_rest_), &intpart);
	number_of_rest_intervals_ = (fractpart > 0) ? intpart : intpart - 1;

	if (number_of_rest_intervals_ > 1) {
		for (int i = 0; i < number_of_rest_intervals_; i++) {
			float tmp = (i <= (duration_of_rest_.size() - 1)) ? duration_of_rest_[i] : duration_of_rest_.back();
			res_time += tmp;
		}
	}
	else {
		res_time = number_of_rest_intervals_ * duration_of_rest_[0];
	}
	last_race_ = res_time;
	return res_time;
}
Boots::Boots()
{
	name_ = "�������-���������";
	speed_ = 6 ;
	time_before_rest_ = 60;
	duration_of_rest_ = { 10,5 };
}

std::string& Boots::get_name() { return name_; }
int Boots::get_type() const { return type_; };
float Boots::get_last_race() const { return last_race_; };
