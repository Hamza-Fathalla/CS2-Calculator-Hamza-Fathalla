cmake_minimum_required(VERSION 3.10)
project(CS2Calculator)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
    calculator.cpp
    test.cpp
)

add_executable(calculator ${SOURCES})
