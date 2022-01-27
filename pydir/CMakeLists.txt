cmake_minimum_required(VERSION 3.14)
project(minimal_py)

find_package(pybind11 REQUIRED)

include_directories("../include")

set(PYTHON_MODULE_EXTENSION ".so")

pybind11_add_module(example testpybind.cpp)

target_link_libraries(example PUBLIC gbutil::gbutil)
target_link_libraries(example PUBLIC subs)

install(TARGETS example DESTINATION "${PROJECT_SOURCE_DIR}")
