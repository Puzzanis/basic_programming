#include "Broom.h"


float Broom::movement(const int& distance) {
	int interval_count = distance / 1000;
	float tmp = ((100 - interval_count) / 100.0);
	float res_distance = distance * tmp;
	float res_time{ 0.0 };
	res_time = res_distance / speed_;
	last_race_ = res_time;
	return res_time;
}

Broom::Broom() {
	name_ = "Метла";
	int speed_ =20;
}
std::string& Broom::get_name()  { return name_; }
int Broom::get_type() const { return type_; }
float Broom::get_last_race() const { return last_race_; };