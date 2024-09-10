#include "GreeterStatic.h"

namespace GreeterStaticLib
{
	void Greeter::greet(std::string name) {
		std::cout << "Здравствуйте, " << name << '!' << std::endl;
	}
}