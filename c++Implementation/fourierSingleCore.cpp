#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream> 

int main()
{
    const int tSize = 100000;
    const int totalIterations = tSize + 1;
    const double frequencyMultiplier = 2 * 2 * M_PI;
    const double delta = 1.0 / (tSize - 1);

    std::vector<double> t(tSize);

    // Generate linspace equivalent for t
    for (int i = 0; i < tSize; ++i)
    {
        t[i] = i * delta;
    }

    auto startTime = std::chrono::high_resolution_clock::now();

    std::vector<double> y(tSize, 0.0);
    for (int i = 1; i < totalIterations; i += 2)
    {
        for (int j = 0; j < tSize; ++j)
        {
            y[j] += (1.0 / i) * std::sin(frequencyMultiplier * i * t[j]);
        }
    }

    for (double &val : y)
    {
        val *= 4 / M_PI;
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> executionTime = endTime - startTime;

    std::cout << "Execution Time: " << executionTime.count() << " seconds" << std::endl;

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
