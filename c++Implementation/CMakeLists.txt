cmake_minimum_required(VERSION 3.10)
project(SquareWaveGenerator)

# Set C++ compiler
set(CMAKE_CXX_COMPILER icpx)

# Add the executable
add_executable(squareWaveGenerator fourierSingleCore.cpp)

# Custom target for running the Python script post-build
add_custom_target(run ALL
    COMMAND ./squareWaveGenerator
    COMMAND python3 ../plot_script.py
    DEPENDS squareWaveGenerator
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
    COMMENT "Running C++ program and then plotting results with Python script")