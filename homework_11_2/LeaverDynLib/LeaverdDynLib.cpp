#include "LeaverdDynLib.h"

namespace LeaverdDynLib
{
	void Leaver::leave(std::string name) {
		std::cout << "Здравствуйте, " << name << '!' << std::endl;
	}
}