cmake_minimum_required(VERSION 3.10)

project(answer)

# Custom target for running the Python script post-build
add_custom_target(run ALL
    COMMAND .././answer
    COMMAND python3 ../plot_script.py
    # DEPENDS answear
    WORKING_DIRECTORY ${CMAKE_PROJECT_DIR}
    COMMENT "Running C++ program and then plotting results with Python script")