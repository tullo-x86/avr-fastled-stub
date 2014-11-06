cmake_minimum_required(VERSION 2.8)

project(rain)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)
set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/common.h
)

#add_subdirectory("${PROJECT_SOURCE_DIR}/FastLED")

add_avr_executable(rain ${SOURCE} ${HEADERS})

#install(TARGETS rain RUNTIME DESTINATION bin)
