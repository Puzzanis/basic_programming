#include <cmath>
#include "Centaur.h"


float Centaur::movement(int distance) {
	double fractpart; // дробная часть
	double intpart;   // целая часть
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
	return res_time;
}

Centaur::Centaur()
{
	name_ = "Кентавр";
	speed_ = 15;
	time_before_rest_ = 8;
	duration_of_rest_ = { 2 };
}