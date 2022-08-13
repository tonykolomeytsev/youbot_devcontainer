PROJECT(youbot_project_name)
CMAKE_MINIMUM_REQUIRED(VERSION 3.1)

## enable C++ 11
SET(CMAKE_CXX_STANDARD 11)

## check required prerequisites
SET(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/external/cmake_modules")
SET(Boost_USE_STATIC_LIBS ON)
SET(Boost_ADDITIONAL_VERSIONS "1.39" "1.39.0" "1.40" "1.40.0" "1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0" "1.44" "1.44.0" "1.45" "1.45.0" "1.46" "1.46.0")
FIND_PACKAGE(Boost REQUIRED COMPONENTS thread date_time filesystem system)
FIND_LIBRARY(YouBotDriver REQUIRED)
FIND_LIBRARY(soem REQUIRED)

## preprocessor definitions
SET(CMAKE_C_FLAGS_DEBUG "-fPIC -Wall -g")
SET(CMAKE_CXX_FLAGS_DEBUG "-fPIC -Wall -g")

## build parameters and paths
SET(CMAKE_BUILD_TYPE Debug) #enable debug mode (e.g. for embedded gdb in eclipse )
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin CACHE PATH "Configure the executable output path.")

## Set include directories
INCLUDE_DIRECTORIES(
	${Boost_INCLUDE_DIR}
)

## Compile and link
ADD_EXECUTABLE(youbot_project_name
  	src/main.cpp
)

TARGET_LINK_LIBRARIES(youbot_project_name
	YouBotDriver
	${Boost_LIBRARIES}
	pthread
	soem
)
