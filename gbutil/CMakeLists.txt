add_library(gbutil src/StringStuff.cpp)

#target_include_directories(gbutil PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_include_directories(gbutil PUBLIC "${PROJECT_SOURCE_DIR}/gbutil/include")