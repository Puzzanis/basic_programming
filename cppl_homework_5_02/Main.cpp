#include <iostream>
#include "Table.h"


int main()
{
    setlocale(LC_ALL, "ru");

	Table<int> T1(7, 7);

    try
    {
        //заполняем объект T1
        T1[6][6] = 990;
        T1[5][6] = 880;

        //доступ к элементам объекта T1 разными операторами () и []
        std::cout << T1[6][6] << "\n";
        std::cout << T1[5][6] << "\n";

        T1.getSize();
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

	return EXIT_SUCCESS;
}