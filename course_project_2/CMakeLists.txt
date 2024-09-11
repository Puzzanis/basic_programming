cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("course_project_2")

set(SOURCES
	Main.cpp
)

set(SOURCES_LIB
	Lib/Ground/Camel/Camel.cpp
)

set(HEADER_LIB
	Lib/ground_vehicle/groundvehicle.h
	Lib/Ground/Camel/Camel.h
)

# Добавьте источник в исполняемый файл этого проекта.
add_executable (${PROJECT_NAME} ${SOURCES})

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(vehiclesLib SHARED ${HEADER_LIB} ${SOURCES_LIB})
target_link_libraries(${PROJECT_NAME} vehiclesLib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
