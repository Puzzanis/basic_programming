# CMakeList.txt: проект CMake для homework_10_2; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("homework_10_2")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (homework_10_2 "homework_10_2.cpp"  "Classes/Equilateral_triangle/Equilateral_triangle.cpp" "Classes/Shape/Shape.h" "Classes/Shape/Shape.cpp" "Classes/Error/Error.h" "Classes/Error/Error.cpp" "Classes/Isosceles_triangle/Isosceles_triangle.h" "Classes/Isosceles_triangle/Isosceles_triangle.cpp" "Classes/Parallelogram/Parallelogram.h" "Classes/Parallelogram/Parallelogram.cpp" "Classes/Print/Print.h" "Classes/Print/Print.cpp" "Classes/Quadrangle/Quadrangle.h" "Classes/Quadrangle/Quadrangle.cpp" "Classes/Rectangle/Rectangle.h" "Classes/Rectangle/Rectangle.cpp" "Classes/Rhomb/Rhomb.h" "Classes/Rhomb/Rhomb.cpp" "Classes/Right_angled_triangle/Right_angled_triangle.h" "Classes/Right_angled_triangle/Right_angled_triangle.cpp" "Classes/Square/Square.h" "Classes/Square/Square.cpp" "Classes/Triangle/Triangle.h" "Classes/Triangle/Triangle.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET homework_10_2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
