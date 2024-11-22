#pragma once

#include<iostream>
#include <exception>

template<class T>
class Table
{
private:
    int row_{ 0 };
    int col_{ 0 };
    T** arr1_;
public:
    Table(int row, int col) :row_{ row }, col_{ col }
    {
        arr1_ = new T * [row_] {};
        for (int i = 0; i < row_; i++)
        {
            arr1_[i] = new T[col_]{};
        }
    };

    //перегрузка второй пары []
    class Proxy {
    private:
        int* _array;
        int size_{ 0 };
    public:
        Proxy(T* _array, int size) : _array{ _array }, size_{ size } { }

        T& operator[](int index) {
            if (index >= size_ || index < 0) throw std::out_of_range("second index out of range index");
            return _array[index];
        }
    };

    Proxy operator[](const int i) {
        if (i >= row_ || i < 0) throw std::out_of_range("first index out of range");
        return Proxy(arr1_[i], col_);
    };

    Proxy operator[](const int i) const {
        return Proxy(arr1_[i], col_);
    };

    void getSize()
    {
        std::cout << "Size Of Array: " << row_ << " x " << col_ << std::endl << std::endl;
    };

    ~Table()
    {
        for (unsigned i = 0; i < row_; i++)
        {
            delete[] arr1_[i];
        }

        delete[] arr1_;
    };
};