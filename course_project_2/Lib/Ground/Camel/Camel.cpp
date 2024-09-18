#include <cmath>
#include "Camel.h"


float Camel::movement(int distance) {
	double fractpart; // дробная часть
	double intpart;   // целая часть
	float res_time = (float)distance / (float)speed_;

	fractpart = std::modf((res_time / time_before_rest_), &intpart);
	number_of_rest_intervals_ = (fractpart > 0) ? intpart : intpart -1;

	if (number_of_rest_intervals_ > 1) {
		for (int i = 0; i < number_of_rest_intervals_; i++) {
			float tmp = (i <= (duration_of_rest_.size()-1)) ? duration_of_rest_[i] : duration_of_rest_.back();
			res_time += tmp;
		}
	}
	else { 
		res_time = number_of_rest_intervals_ * duration_of_rest_[0];
	}
	last_race_ = res_time;
	return res_time;
}

Camel::Camel()
{
	name_ = "Верблюд";
	speed_ = 10;
	time_before_rest_ = 30;
	duration_of_rest_ = { 5,8 };
}

std::string Camel::get_name() { return name_; }
int Camel::get_type() { return type_; };
float Camel::get_last_race() { return last_race_; };