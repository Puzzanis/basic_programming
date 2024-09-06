#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
/*
функция возвращает длину переданной строки, если эта длина не равна значению переданного параметра forbidden_length 
иначе выбрасывать исключение.
*/
int function(std::string str, int forbidden_length);

#endif