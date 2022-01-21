cmake_minimum_required(VERSION 3.14)

# set the project name
project(minimal)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_library(CFITSIO cfitsio REQUIRED)
find_library(YAML-CPP
             NAMES yaml-cpp
             PATHS ${PROJECT_SOURCE_DIR}/../yaml-cpp/
             PATH_SUFFIXES lib
             REQUIRED)
if(EIGEN_DIR)

endif()

add_subdirectory(gbutil)
add_subdirectory(src)
add_subdirectory(src/subs)
add_subdirectory(pydir)


