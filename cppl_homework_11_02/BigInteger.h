#ifndef BIGINTEGER_H
#define BIGINTEGER_H

#include <bitset>
#include <iostream>
#include <string>
#include <vector>

class BigInteger
{
private:
	std::vector<int> value_;	// контейнер для хранения числа
	bool isNegative{ false };   // флаг отрицательности
public:
	BigInteger() = default;									// конструктор умолчания (число равно нулю)
	//BigInteger(long x);							// конструктор преобразования из обычного целого числа
	explicit BigInteger(std::string value);					// конструктор преобразования из строки
	BigInteger(const BigInteger& bigInt);			// конструктор копирования

	//void changingSign(BigInteger& bigInt);
	// операция присваивания
	BigInteger& operator=(const BigInteger& bigInt);

	// арифметические операции
	BigInteger operator+(BigInteger& bigInt);
	//BigInteger operator-(const BigInteger& bigInt) const;
	//BigInteger operator*(const BigInteger& bigInt) const;
};

#endif