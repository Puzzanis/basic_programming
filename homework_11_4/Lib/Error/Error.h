#ifndef ERROR_DEFINE_SHAPE_H
#define ERROR_DEFINE_SHAPE_H

#include <iostream>
#include <exception>
#include <string>

#ifdef SHAPECLASSESLIB_EXPORTS
#define SHAPE __declspec(dllexport)
#else
#define SHAPE __declspec(dllimport)
#endif

class Error : public std::exception
{
private:
	std::string error{ "" };
public:
	SHAPE Error(std::string setError);

	SHAPE const char* what() const noexcept override;
};

#endif

