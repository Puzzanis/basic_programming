#include "Eagle.h"


float Eagle::movement(int distance) {
	float res_distance = distance * 0.94;
	float res_time{ 0.0 };
	res_time = res_distance / speed_;

	return res_time;
}

Eagle::Eagle()
{
	name_ = "Îð¸ë";
	speed_ = 8;
}