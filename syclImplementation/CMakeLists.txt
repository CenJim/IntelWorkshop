cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_COMPILER /opt/intel/oneapi/compiler/latest/bin/icx)
set(CMAKE_CXX_COMPILER /opt/intel/oneapi/compiler/latest/bin/icpx)

project(SquareWaveGenerator)



FIND_PACKAGE(IntelSYCL REQUIRED)



# Add the executable
add_executable(square_wave_generator fourierSycl.cpp)

# If your SYCL application depends on specific libraries or requires special compiler flags,
# you can set them like this:
target_compile_options(square_wave_generator PRIVATE -fsycl)
ADD_SYCL_TO_TARGET(square_wave_generator)

# Custom target for running the C++ program and the Python script post-build
add_custom_target(run ALL
    COMMAND ./square_wave_generator
    COMMAND python3 ../plot_script.py
    DEPENDS square_wave_generator
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running SYCL program and then plotting results with Python script"
)