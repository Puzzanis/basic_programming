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
	Lib/Ground/CamelFast/CamelFast.cpp
	Lib/Ground/Centaur/Centaur.cpp
	Lib/Ground/Boots/Boots.cpp
	Lib/Air/MagicCarpet/MagicCarpet.cpp
	Lib/Air/Eagle/Eagle.cpp
	Lib/Air/Broom/Broom.cpp
)

set(HEADER_LIB
	Lib/Ground_vehicle/groundvehicle.h
	Lib/Air_vehicle/AirVehicle.h
	Lib/Ground/Camel/Camel.h
	Lib/Ground/CamelFast/CamelFast.h
	Lib/Vehicle/AbstractVehicle.h
	Lib/Vehicle/CreatorVehicle.h
	Lib/Ground/Centaur/Centaur.h
	Lib/Ground/Boots/Boots.h
	Lib/Air/MagicCarpet/MagicCarpet.h
	Lib/Air/Eagle/Eagle.h
	Lib/Air/Broom/Broom.h
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
