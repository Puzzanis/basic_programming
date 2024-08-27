#include <iostream>

#define MODE 1
#define ADD(a,b) (a) + (b)



int main()
{
	setlocale(LC_ALL, "rus");  //setting the language standard

#ifndef MODE
	#error djglkjf
#endif // !MODE

#if MODE == 1
	std::cout << "Работаю в боевом режиме" << std::endl;
	int first_num{};
	std::cout << "Введите число 1: "; std::cin >> first_num;
	int second_num{};
	std::cout << "Введите число 2: "; std::cin >> second_num;
	std::cout << "Результат сложения: " << ADD(first_num,second_num);
#elif MODE == 0
	std::cout << "Работаю в режиме тренировки";
#else 
	std::cout << "Неизвестный режим. Завершение работы";
#endif
	
	return EXIT_SUCCESS;
}

