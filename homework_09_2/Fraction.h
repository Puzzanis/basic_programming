#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	int numerator_{};
	int denominator_{};
	int fract_nod(int a, int b); // нахождение НОД

public:
	Fraction(int numerator, int denominator);

	int get_numerator() const;
	int get_denominator() const;

	Fraction reduce();							//функция сокращения дроби
	Fraction operator+(const Fraction& fract);  //пергрузка оператора '+'
	Fraction operator-(const Fraction& fract);  //пергрузка оператора '-'
	Fraction operator*(const Fraction& fract);  //пергрузка оператора '*'
	Fraction operator/(const Fraction& fract);  //пергрузка оператора '/'
	Fraction& operator++();		//пергрузка оператора '++' - префикс
	Fraction operator++(int);	//пергрузка оператора '++' - постфикс
	Fraction& operator--();		//пергрузка оператора '--' - префикс
	Fraction operator--(int);	//пергрузка оператора '--' - постфикс
};

#endif // !FRACTION_H