#include "Broom.h"


float Broom::movement(int distance) {
	int interval_count = distance / 1000;
	float tmp = ((100 - interval_count) / 100.0);
	float res_distance = distance * tmp;
	float res_time{ 0.0 };
	res_time = res_distance / speed_;

	return res_time;
}

Broom::Broom()
{
	name_ = "Метла";
	speed_ = 20;
}