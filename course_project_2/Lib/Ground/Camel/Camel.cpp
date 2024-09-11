#include "Camel.h"

int Camel::movement(int distance) {
	int tmp_time = distance / speed_;
	int number_of_rest_intervals_ = ((tmp_time % time_before_rest_) > 0) ? tmp_time / time_before_rest_ : (tmp_time / time_before_rest_) - 1;

	if (number_of_rest_intervals_ > 1) {
		for (int i = 0; i < number_of_rest_intervals_; i++) {
			int tmp = (i == 0) ? 5 : 8;
			tmp_time += tmp;
		}
	}
	else { 
		tmp_time = number_of_rest_intervals_ * 5;
	}
	return tmp_time;
}

Camel::Camel(std::string name, int speed, int time_before_rest, int duration_of_rest)
{
	name_ = name;
	speed_ = speed;
	time_before_rest_ = time_before_rest;
	duration_of_rest_ = duration_of_rest;
}