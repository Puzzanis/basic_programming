#pragma once

#include <iostream>

template<class T>
class Vector
{
private:
	T* vec_;
	int indx_{ 0 };
	int actual_size_{15};
public:
	Vector() 
	{
		vec_ = new T[actual_size_];
	};

	~Vector()
	{
		delete[] vec_;
	};

	T at(int index)
	{
		return vec_[index];
	}

	void push_back(T value)
	{
		if (indx_ < actual_size_)
		{
			vec_[indx_] = value;
			indx_++;
		}
		else
		{
			actual_size_ *= 2;
			auto* new_arr = new T[actual_size_];
			for (int i = 0; i < indx_; i++)
			{
				new_arr[i] = vec_[i];
			}
			delete[] vec_;
			new_arr[indx_] = value;
			vec_ = new_arr;
		}
	}

	int capacity() const
	{
		return this->actual_size_;
	}

	int size() const
	{
		return indx_;
	}
};
