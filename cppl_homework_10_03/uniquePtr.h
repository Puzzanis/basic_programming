#pragma once

#include<iostream>

template<class T>
class uniquePtr
{
private:
	T* ptr_ = nullptr;

public:
	uniquePtr() = default;
	explicit uniquePtr(T* ptr): ptr_(ptr) {};

	uniquePtr(uniquePtr&& second) noexcept : ptr_(second.ptr_)
	{
		second.ptr_ = nullptr;
	}

	~uniquePtr() 
	{ 
		delete ptr_; 
		std::cout << "destructor called\n";
	};

	//Перегружен оператор * для получения объекта
	T& operator*() const
	{
		return *ptr_;
	}

	T* operator->() const
	{
		return ptr_;
	}

	//Запрещен конструктор копирования
	uniquePtr(const uniquePtr&) = delete;

	//Запрещен оператор присваивания
	T& operator= (const T& second) = delete;

	//освобождает владение и возвращает сырой указатель
	T* release() noexcept
	{
		T* _tmp = ptr_;
		ptr_ = nullptr;
		return _tmp;
	}

};