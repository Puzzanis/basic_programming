#include "Error.h"

namespace ShapeLib {
	Error::Error(std::string setError) : error{ setError } {}
	const char* Error::what() const noexcept { return error.c_str(); }
}