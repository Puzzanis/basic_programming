#include "MagicCarpet.h"


float MagicCarpet::movement(int distance) {
	float res_distance{0.0};
	float res_time{ 0.0 };
	if (distance < 1000) {
		res_distance += distance;
	}
	else if (distance >= 1000 && distance < 5000) {
		res_distance += distance*0.97;
	}
	else if (distance >= 5000 && distance < 10000) {
		res_distance += distance * 0.90;
	}
	else {
		res_distance += distance * 0.95;
	}
	res_time = res_distance / speed_;

	last_race_ = res_time;
	return res_time;
}

MagicCarpet::MagicCarpet()
{
	name_ = "Ковёр-самолёт";
	speed_ = 10;
}

std::string MagicCarpet::get_name() { return name_; }
int MagicCarpet::get_type() { return type_; };
float MagicCarpet::get_last_race() { return last_race_; };
