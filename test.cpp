#include <iostream>
#include <string>
#include <sstream>
#include <climits>
#include <cfloat>
#include <iomanip>
#include <math.h>
#include <limits>

int main()
{
    std::stringstream ss("5");
    double x;
    ss >> x;
    char	leftOver;
    if (ss >> leftOver)
        std::cout << "hello" << std::endl;
    std::cout << x << std::endl;
}