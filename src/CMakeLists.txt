# add the executable
add_executable(MinTest Main.cpp)

target_link_libraries(MinTest PUBLIC subs)

install(TARGETS MinTest DESTINATION bin)
