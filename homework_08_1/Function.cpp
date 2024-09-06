#include <iostream>

/*
функция возвращает длину переданной строки, если эта длина не равна значению переданного параметра forbidden_length
иначе выбрасывать исключение.
*/
int function(std::string str, int forbidden_length) {
    return (str.length() != forbidden_length) ? str.length() : 
                                                throw std::exception("Вы ввели слово запретной длины! До свидания");
}