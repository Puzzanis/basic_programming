#include <math.h>
#include <algorithm>
#include "Fraction.h"


Fraction::Fraction(int numerator, int denominator) : numerator_{ numerator }, denominator_{ denominator } {}

int Fraction::get_numerator() const { return numerator_; }
int Fraction::get_denominator() const { return denominator_; }

// нахождение НОД
int Fraction::fract_nod(int a, int b) {
	if (b == 0) return a;
	return fract_nod(b, a % b);
}

//функция сокращения дроби
Fraction Fraction::reduce() {
	int a = std::max(abs(get_numerator()), abs(get_denominator())), b = std::min(abs(get_numerator()), abs(get_denominator()));
	int sgn; //знак нашей дроби
	if (get_numerator() * get_numerator() >= 0) sgn = 1;
	else sgn = -1;
	int nod = fract_nod(a, b);
	return Fraction(sgn * (abs(get_numerator()) / nod), abs(get_denominator()) / nod);
}

//пергрузка оператора '+'
Fraction Fraction::operator+(const Fraction& fract) {
	return Fraction((get_numerator() * fract.get_denominator()) + (fract.get_numerator() * get_denominator()), get_denominator() * fract.get_denominator()).reduce();
}
//пергрузка оператора '-'
Fraction Fraction::operator-(const Fraction& fract) {
	return Fraction((get_numerator() * fract.get_denominator()) - (fract.get_numerator() * get_denominator()), get_denominator() * fract.get_denominator()).reduce();
}
//пергрузка оператора '*'
Fraction Fraction::operator*(const Fraction& fract) {
	return Fraction(get_numerator() * fract.get_numerator() , get_denominator() * fract.get_denominator()).reduce();
}
//пергрузка оператора '/'
Fraction Fraction::operator/(const Fraction& fract) {
	return Fraction(get_numerator() * fract.get_denominator() , get_denominator() * fract.get_numerator()).reduce();
}
//пергрузка оператора '++'  - префикс
Fraction& Fraction::operator++() {
	numerator_ = numerator_ + denominator_;
	return *this;
}

//пергрузка оператора '++'  - постфикс
Fraction Fraction::operator++(int) {
	Fraction temp{ *this };
	++(*this);
	return temp;
}
//пергрузка оператора '--'  - префикс
Fraction& Fraction::operator--() {
	numerator_ = numerator_ - denominator_;
	return *this;
}

//пергрузка оператора '--'  - постфикс
Fraction Fraction::operator--(int) {
	Fraction temp{ *this };
	--(*this);
	return temp;
}

