#include "CamelFast.h"

float CamelFast::movement(const int& distance) {
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

CamelFast::CamelFast()
{
	name_ = "�������-���������" ;
	speed_= 40 ;
	time_before_rest_ = 10;
	duration_of_rest_ = { 5, 6.5, 8 };
}

std::string& CamelFast::get_name()  { return name_; }
int CamelFast::get_type() const { return type_; };
float CamelFast::get_last_race() const { return last_race_; };