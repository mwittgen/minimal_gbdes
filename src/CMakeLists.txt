# add the executable
add_executable(MinTest Main.cpp)

target_link_libraries(MinTest PUBLIC subs)
#target_link_libraries(MinTest PUBLIC ${GB_PACKAGES}/astrometry/obj/Atrometry.o)

install(TARGETS MinTest DESTINATION bin)
