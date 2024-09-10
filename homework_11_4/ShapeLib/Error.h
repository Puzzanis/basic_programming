#pragma once

#include <iostream>
#include <exception>
#include <string>

#ifdef SHAPELIB_EXPORTS
#define SHAPELIB_API __declspec(dllexport)
#else
#define SHAPELIB_API __declspec(dllimport)
#endif

namespace ShapeLib {
	class Error : public std::exception
	{
	private:
		std::string error{ "" };
	public:
		SHAPELIB_API Error(std::string setError);

		SHAPELIB_API const char* what() const noexcept override;
	};
}
