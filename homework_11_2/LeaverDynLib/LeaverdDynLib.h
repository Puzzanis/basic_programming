#ifndef LEAVERDDYNLIB_H
#define LEAVERDDYNLIB_H

#include <iostream>

#ifdef LEAVERDDYNLIB_EXPORTS
#define LEAVER_API __declspec(dllexport)
#else
#define LEAVER_API __declspec(dllimport)
#endif

namespace LeaverdDynLib
{
	class LEAVER_API Leaver
	{
	public:
		void leave(std::string name);
	};
}

#endif