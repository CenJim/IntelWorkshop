# IntelWorkshop



## Overview

This project demonstrates the generation of a square wave using Fourier series approximation. It consists of a C++ program to calculate the wave and a Python script to plot the results.

## Prerequisites

- CMake version 3.10 or higher
- An installation of the Intel C++ Compiler (icpx)
- Python 3.x with the following packages:
  - `numpy`
  - `matplotlib`

Ensure that you have the above prerequisites installed on your system before proceeding.

## Building and Running the single threading c++ implementation

1. **Build your own single-threading implementation**

   First, clone the repository to your Cloud environment and run the following command:

   ```bash
   git clone https://git.ecdf.ed.ac.uk/s2160679/intelworkshop.git
   cd c++Implementation
   mkdir build
   cd build
   cmake ..
   make run 
   ```

2. **Complete the SYCL implementation**

   Go to the `syclImplementation` directory and complete the task and compare your result with the pre-compiled `Syclexecutable` in the `answear` directory 
   

3. **Offload the SYCL to GPU and CPU**

    Once you finished you can run your implementation on both GPU and CPU using the following command 


   ```bash
   export ONEAPI_DEVICE_SELECTOR=*:cpu 
   or
   export ONEAPI_DEVICE_SELECTOR=*:gpu 
   ```
