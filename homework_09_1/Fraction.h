#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	int numerator_{};
	int denominator_{};

public:
	Fraction(int numerator, int denominator);

	int get_numerator();
	int get_denominator();

	bool operator==(Fraction& fract);  //overload the operator '=='
	bool operator!=(Fraction& fract);  //overload the operator '!='
	bool operator<(Fraction& fract);   //overload the operator '<'
	bool operator>(Fraction& fract);   //overload the operator '>'
	bool operator<= (Fraction& fract); //overload the operator '<='
	bool operator>=(Fraction& fract);  //overload the operator '>='
};

#endif // !FRACTION_H