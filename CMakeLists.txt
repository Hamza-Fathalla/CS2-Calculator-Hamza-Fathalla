cmake_minimum_required(VERSION 3.10)
project(CS2_Calculator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
add_executable(calculator 
    calculator.cpp 
    test.cpp
)

# Include directories (if needed)
target_include_directories(calculator PRIVATE ${CMAKE_SOURCE_DIR})