# CMakeList.txt: проект CMake для sqlcpp_homework_5_01; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.20)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("sqlcpp_homework_5_01")

file(GLOB src "include/*.h" "./*.cpp")


# Добавьте источник в исполняемый файл этого проекта.
add_executable (${PROJECT_NAME} ${src})

add_subdirectory(E:/C++/libpqxx-7.10.0 libpq-build)
target_compile_features(sqlcpp_homework_5_01 PRIVATE cxx_std_17)
target_link_libraries(sqlcpp_homework_5_01 pqxx)
if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET sqlcpp_homework_5_01 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
