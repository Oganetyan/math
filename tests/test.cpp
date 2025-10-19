#include <iostream>
#include <cmath>
#include "../include/math/math.hpp"

int main()
{
    std::cout << "=== Triganometric test start ===" << std::endl
              << "Sin test: " << math::sin(math::PI / 4.0) << " " << std::sin(M_PI / 4.0) << std::endl
              << "Cos test: " << math::cos(math::PI / 4.0) << " " << std::cos(M_PI / 4.0) << std::endl
              << "Tan test: " << math::tan(math::PI / 4.0) << " " << std::tan(M_PI / 4.0) << std::endl
              << "=== Triganometric test compited ===" << std::endl;

    std::cout << std::endl;
    
    std::cout << "=== Powers functions test start ===" << std::endl
              << "Exponenta test: " <<math::exp(1.5) << " " << std::exp(1.5) << std::endl
              << "Ln test: " <<math::ln(math::E) << " " << std::log(M_E) << std::endl
              << "Pow test: " <<math::pow(math::PI, math::E) << " " << std::pow(M_PI, M_E) << std::endl
              << "Log test: " <<math::log(2,1024) << " " << std::log2(1024) << std::endl
              << "=== Powers functions test complited === " <<std::endl;

        return 0;
}