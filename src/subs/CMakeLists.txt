add_library(subs Instrument.cpp)

target_include_directories(subs PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(subs PUBLIC gbutil::gbutil)
#target_include_directories(subs PUBLIC ${GB_PACKAGES}/astrometry/include/)
#target_link_libraries(MinTest PUBLIC ${GB_PACKAGES}/astrometry/obj/Astrometry.o)
