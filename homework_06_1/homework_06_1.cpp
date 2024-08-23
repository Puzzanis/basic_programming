п»ї#include <iostream>
#include "Maths.h"


int main() {
	setlocale(LC_ALL, "rus");  //setting the language standard

	int first_number{};
	std::cout << "Р’РІРµРґРёС‚Рµ РїРµСЂРІРѕРµ С‡РёСЃР»Рѕ: "; std::cin >> first_number;
	int second_number{};
	std::cout << "Р’РІРµРґРёС‚Рµ РІС‚РѕСЂРѕРµ С‡РёСЃР»Рѕ: "; std::cin >> second_number;
	int num_func{};
	std::cout << "Р’С‹Р±РµСЂРёС‚Рµ РѕРїРµСЂР°С†РёСЋ (1 - СЃР»РѕР¶РµРЅРёРµ, 2 РІС‹С‡РёС‚Р°РЅРёРµ, 3 - СѓРјРЅРѕР¶РµРЅРёРµ, 4 - РґРµР»РµРЅРёРµ, 5 - РІРѕР·РІРµРґРµРЅРёРµ РІ СЃС‚РµРїРµРЅСЊ): "; std::cin >> num_func;


	switch (num_func)
	{
	case 1:
		std::cout << first_number << " РїР»СЋСЃ " << second_number << " = " << sum(first_number, second_number) << std::endl;
		break;
	case 2:
		std::cout << first_number << " РјРёРЅСѓСЃ " << second_number << " = " << diff(first_number, second_number) << std::endl;
		break;
	case 3:
		std::cout << first_number << " СѓРјРЅРѕР¶РёС‚СЊ " << second_number << " = " << multiplication(first_number, second_number) << std::endl;
		break;
	case 4:
		std::cout << first_number << " СЂР°Р·РґРµР»РёС‚СЊ " << second_number << " = " << division(first_number, second_number) << std::endl;
		break;
	case 5:
		std::cout << first_number << " РІ СЃС‚РµРїРµРЅРё " << second_number << " = " << pow(first_number, second_number) << std::endl;
		break;
	default:
		break;
	}
	return EXIT_SUCCESS;
}
