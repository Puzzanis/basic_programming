#include "Fraction.h"


Fraction::Fraction(int numerator, int denominator) : numerator_{ numerator }, denominator_{ denominator } {}

int Fraction::get_numerator() { return numerator_; }
int Fraction::get_denominator() { return denominator_; }

//overload the operator '=='
bool Fraction::Fraction::operator==(Fraction& fract) {
	return (get_numerator() == fract.get_numerator() && get_denominator() == fract.get_denominator());
}
//overload the operator '!='
bool Fraction::operator!=(Fraction& fract) {
	return (get_numerator() != fract.get_numerator() && get_denominator() != fract.get_denominator());
}
//overload the operator '<'
bool Fraction::operator<(Fraction& fract) {
	return (get_numerator() < fract.get_numerator() && get_denominator() < fract.get_denominator());
}
//overload the operator '>'
bool Fraction::operator>(Fraction& fract) {
	return (get_numerator() > fract.get_numerator() && get_denominator() > fract.get_denominator());
}
//overload the operator '<='
bool Fraction::operator<= (Fraction & fract){
	return (get_numerator() <= fract.get_numerator() && get_denominator() <= fract.get_denominator());
}
//overload the operator '>='
bool Fraction::Fraction::operator>=(Fraction& fract) {
	return (get_numerator() >= fract.get_numerator() && get_denominator() >= fract.get_denominator());
}
