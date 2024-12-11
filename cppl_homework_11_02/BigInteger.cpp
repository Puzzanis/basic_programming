#include "BigInteger.h"



BigInteger::BigInteger(std::string value)
{
	if (value[0] == '-')
	{
		isNegative = true;
		value = value.substr(1);
	}

	for (long i = value.length()-1; i > -1; --i)
	{
		value_.push_back((isNegative) ? ((-1)*(value[i] - '0')) : (value[i] - '0'));
	}

}

//конструктор копирования
BigInteger::BigInteger(const BigInteger& bigInt) = default;

// операция присваивания
BigInteger& BigInteger::operator=(const BigInteger& bigInt)
{
	*this = bigInt;
	return *this;
}

// арифметические операции
BigInteger BigInteger::operator+(BigInteger& bigInt)
{
	auto size_{0};
	if (this->value_.size() > bigInt.value_.size())
	{
		size_ = this->value_.size();
		auto diff = this->value_.size() - bigInt.value_.size();
		while (this->value_.size() > bigInt.value_.size())
		{
			bigInt.value_.push_back(0);
		}
	}
	else
	{
		size_ = bigInt.value_.size();
		auto diff = bigInt.value_.size() - this->value_.size();
		while (this->value_.size() <  bigInt.value_.size())
		{
			this->value_.push_back(0);
		}
	}


	for (int i = 0; i < size_; i++) {								//сначала сложим числа поразрядно,
		this->value_[i] += bigInt.value_[i];       //игнорируя переполнения
	}

	for (int i = 0; i < size_ - 1; i++) {    //а затем поочередно выполним переносы
		if (this->value_[i] >= 10) {         //для каждого разряда
			this->value_[i] -= 10;
			this->value_[i + 1]++;
		}
		if (this->value_[i] < 0) {         //для каждого разряда
			if (this->value_[i] > -10)
			{
				this->value_[i] += 10;
				this->value_[i + 1]--;
			}
			else
			{
				this->value_[i] *= -1;
				this->value_[i] -= 10;
				this->value_[i + 1]--;
			}
			
		}
	}


	return *this;
}
//BigInteger BigInteger::operator*(const BigInteger& bigInt) const
//{
//	return bigInt;
//}