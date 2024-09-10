# CMakeList.txt: проект CMake для homework_11_3; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("homework_11_4")

set(SOURCES
	Main.cpp
)

set(SOURCES_LIB
	Lib/Equilateral_triangle/Equilateral_triangle.cpp
	Lib/Shape/Shape.cpp 
	Lib/Error/Error.cpp 
	Lib/Isosceles_triangle/Isosceles_triangle.cpp 
	Lib/Parallelogram/Parallelogram.cpp 
	Lib/Print/Print.cpp 
	Lib/Quadrangle/Quadrangle.cpp 
	Lib/Rectangle/Rectangle.cpp 
	Lib/Rhomb/Rhomb.cpp 
	Lib/Right_angled_triangle/Right_angled_triangle.cpp 
	Lib/Square/Square.cpp 
	Lib/Triangle/Triangle.cpp
)

set(HEADER_LIB
	Lib/Equilateral_triangle/Equilateral_triangle.h
	Lib/Shape/Shape.h 
	Lib/Error/Error.h
	Lib/Isosceles_triangle/Isosceles_triangle.h
	Lib/Parallelogram/Parallelogram.h 
	Lib/Print/Print.h 
	Lib/Quadrangle/Quadrangle.h
	Lib/Rectangle/Rectangle.h 
	Lib/Rhomb/Rhomb.h 
	Lib/Right_angled_triangle/Right_angled_triangle.h
	Lib/Square/Square.h
	Lib/Triangle/Triangle.h
)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (${PROJECT_NAME} ${SOURCES})

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(ShapeClassesLib SHARED ${HEADER_LIB} ${SOURCES_LIB})
target_link_libraries(homework_11_4 ShapeClassesLib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET homework_11_4 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
