cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(simulated_airport_environnement)

# Repertoire du projet

SET(CMAKE_CURRENT_PROJECT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/..)

# Find packages

find_package(gazebo REQUIRED)

list(APPEND CMAKE_CXX_FLAGS "${GAZEBO_CXX_FLAGS}")

# include appropriate directories
include_directories(${GAZEBO_INCLUDE_DIRS})
include_directories(include)
link_directories(${GAZEBO_LIBRARY_DIRS})

# Source file of project
file(GLOB_RECURSE SRC_FILES *.cc)

# Set plugins outpout path
SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_PROJECT_DIR}/plugins)
SET(CMAKE_CURRENT_SOURCE_DIR)

# Create libraries and executables

foreach(_path ${SRC_FILES})
  get_filename_component(_name ${_path} NAME_WE)
  add_library(${_name} SHARED ${_path})
  target_link_libraries(${_name} ${GAZEBO_LIBRARIES})
endforeach()
