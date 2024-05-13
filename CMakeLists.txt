cmake_minimum_required(VERSION 3.25)
project(DemoProject)

set(CMAKE_CXX_STANDARD 17)

# important setting for accessing the eigen library
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
find_package(Boost REQUIRED)
include_directories(${BOOst_INCLUDE_DIR})
message("${CMAKE_MODULE_PATH}")
message("${EIGEN3_INCLUDE_DIR}")





add_executable(untitled main.cpp Node.cpp Node.h Resistance.cpp Resistance.h Component.cpp Component.h Branch.cpp Branch.h VoltageSource.cpp VoltageSource.h CurrentSource.cpp CurrentSource.h CircuitException.cpp CircuitException.h Operators.h Voltage.cpp Voltage.h Circuit.cpp Circuit.h Current.cpp Current.h ElectricatPropertyObserver.h ElectricalProperty.cpp ElectricalProperty.h)


