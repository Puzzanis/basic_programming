#pragma once

#include "Shape.h"

#ifdef SHAPELIB_EXPORTS
#define SHAPELIB_API __declspec(dllexport)
#else
#define SHAPELIB_API __declspec(dllimport)
#endif

namespace ShapeLib {
	SHAPELIB_API void print(Shape& fig);
}