#include <sycl/sycl.hpp>
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream> 

int main() {

  const int tSize = 100000;
  const int totalIterations = tSize+1;
  const float frequencyMultiplier = 2 * 2 * M_PI;
  const float delta = 1.0 / (tSize - 1);
  
  std::vector<float> t(tSize, 0);
  std::vector<float> y(tSize, 0.0);

  // Generate linspace equivalent for t
  for (int i = 0; i < tSize; ++i)
  {
     t[i] = i * delta;
  }
  
  // Create buffers for 't' and 'y'
  
  sycl::queue myQueue;
  sycl::buffer<float, 1> tBuffer(t.data(), sycl::range<1>(tSize));
  sycl::buffer<float, 1> yBuffer(y.data(), sycl::range<1>(tSize));
  
  std::cout << "Running on "
        << myQueue.get_device().get_info<sycl::info::device::name>()
        << "\n";
  
  auto startTime = std::chrono::high_resolution_clock::now();
  
  
  
 
  myQueue.submit([&](sycl::handler& cgh) {
       auto tAccessor = tBuffer.get_access<sycl::access::mode::read>(cgh);
        auto yAccessor = yBuffer.get_access<sycl::access::mode::write>(cgh);
        
        cgh.parallel_for<class ParallelSummation>(
            sycl::range<1>(tSize), 
            [=](sycl::item<1> item) 
            {

           //ToDo: Implement the parallel summation
            
            });
    });

  myQueue.wait_and_throw();
    

 
  myQueue.update_host(yBuffer.get_access()); 
  auto endTime = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> executionTime = endTime - startTime;
  std::cout << "Execution Time: " << executionTime.count() << " seconds" << std::endl;
  
   for (float &val : y)
   {
        val *= 4 / M_PI;
   }
  
  // Calculating the area using the trapezoidal rule
    double area = 0.0;
    for (int i = 0; i < tSize - 1; ++i)
    {
        area += 0.5 * (std::abs(y[i]) + std::abs(y[i + 1])) * (t[i + 1] - t[i]);
    }
    double gap = 1 - area;

    std::cout << "area: " << area << std::endl;
    std::cout << "gap: " << gap << std::endl;

    std::ofstream outFile("output.txt");
    for (int i = 0; i < tSize; ++i)
    {
        outFile << t[i] << "\t" << y[i] << std::endl;
    }
    outFile.close();
    
    std::cout << "Data written to output.txt" << std::endl;

  return 0;
} 

