# add the executable
add_executable(MinTest Main.cpp)

target_link_libraries(MinTest PUBLIC subs gbutil::gbutil)
#target_link_libraries(MinTest PUBLIC ${GB_PACKAGES}/astrometry/obj/Atrometry.o)

install(TARGETS MinTest DESTINATION bin)
