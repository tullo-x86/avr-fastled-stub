cmake_minimum_required(VERSION 2.8)

project(rain)

add_definitions(
    -DARDUINO
    -DF_CPU=16000000
    -DNEED_CXX_BITS
)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/common.h
)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/FastLED/
    /home/tully/Arduino/arduino-1.0.6/hardware/arduino/cores/arduino/
    /home/tully/Arduino/arduino-1.0.6/hardware/arduino/variants/standard/
)

file(GLOB FASTLED_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/FastLED/*.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/FastLED/*.h
)

#file(GLOB WIRING_SOURCE
#  ${CMAKE_CURRENT_SOURCE_DIR}/wiring/*.c
#  ${CMAKE_CURRENT_SOURCE_DIR}/wiring/*.h
#)

add_avr_executable(rain ${FASTLED_SOURCE} ${SOURCE} ${HEADERS})

#install(TARGETS rain RUNTIME DESTINATION bin)