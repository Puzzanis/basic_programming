#include "GreeterStatic.h"

namespace GreeterStaticLib
{
	void Greeter::printMessage(std::string name) {
		std::cout << "Здравствуйте, " << name << '!' << std::endl;
	}
}