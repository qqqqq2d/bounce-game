cmake_minimum_required(VERSION 3.10)

# Project name and version
project(YourProjectName VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(prog main.cpp)

# Find the SFML package and link the required libraries
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Link SFML libraries to the executable
target_link_libraries(prog sfml-graphics sfml-window sfml-system)

# Add compile options for strict ISO C++ and warnings
target_compile_options(prog PRIVATE -Wall -Wextra -pedantic)
