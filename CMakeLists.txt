cmake_minimum_required(VERSION 2.8)

project(rain)

add_definitions(
    -DARDUINO
    -DF_CPU=16000000
)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/common.h
)

include_directories(
    /home/tully/Arduino/arduino-1.0.6/hardware/arduino/cores/arduino/
    /home/tully/Arduino/arduino-1.0.6/hardware/arduino/variants/standard/
)

#add_subdirectory("${PROJECT_SOURCE_DIR}/FastLED")

add_avr_executable(rain ${SOURCE} ${HEADERS})

#install(TARGETS rain RUNTIME DESTINATION bin)
