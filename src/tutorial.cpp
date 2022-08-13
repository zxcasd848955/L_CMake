// A simple program that computes the square root of a number
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <string>
#include <config.h>

int main(int argc, char* argv[])
{
    std::cout << "project name: " << PROJECT_NAME << " version: " << PROJECT_VER  << " major version " << PROJECT_VER_MAJOR << std::endl;
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " number" << std::endl;
        return 1;
    }

    // convert input to double
    const double inputValue = atof(argv[1]);

    // calculate square root
    const double outputValue = sqrt(inputValue);
    std::cout << "The square root of " << inputValue << " is " << outputValue
            << std::endl;
    return 0;
}
