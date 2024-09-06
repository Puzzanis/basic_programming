#ifndef ERROR_DEFINE_SHAPE_H
#define ERROR_DEFINE_SHAPE_H

#include <iostream>
#include <exception>
#include <string>

class Error : public std::exception
{
private:
	std::string error{ "" };
public:
	Error(std::string setError);

	const char* what() const noexcept override;
};

#endif

