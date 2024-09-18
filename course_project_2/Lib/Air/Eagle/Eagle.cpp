#include "Eagle.h"


float Eagle::movement(int distance) {
	float res_distance = distance * 0.94;
	float res_time{ 0.0 };
	res_time = res_distance / speed_;
	last_race_ = res_time;
	return res_time;
}

Eagle::Eagle()
{
	name_ = "Îð¸ë";
	speed_ = 8;
}

std::string Eagle::get_name() { return name_; }
int Eagle::get_type() { return type_; };
float Eagle::get_last_race() { return last_race_; };
