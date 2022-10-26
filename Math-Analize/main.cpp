#include <iostream>
#include "Math_Analize.hpp"

using namespace MA;

int main() {

    functions::quadratic* func = new functions::quadratic(1,6,9,0,10);
    functions::linear* func2 = new functions::linear(1, 1, 0, 10);
    functions::power* func3 = new functions::power(3, 0, 10);
    functions::exponential* func4 = new functions::exponential(2, 0, 10);
    functions::fractional_linear* func5 = new functions::fractional_linear(2, 3, 1, 2, 0, 10);
    functions::quadratic* func6 = new functions::quadratic(1, 0, 0, 0, 10);

    std::cout << methods::Calculate_integral(CALCULATING_METHOD::TRAPEZOID, func) << " - Integral of quadratic function. Trapezoid\n";
    std::cout << '\n';
    std::cout << methods::Calculate_integral(CALCULATING_METHOD::NEWTON, func2) << " - Integral of linear function. Newton\n";
    std::cout << '\n';
    std::cout << methods::Calculate_integral(CALCULATING_METHOD::SIMPSON, func3) << " - Integral of power function. Simpson\n";
    std::cout << '\n';
    std::cout << methods::Calculate_integral(CALCULATING_METHOD::NEWTON, func4) << " - Integral of exponential function. Newton\n";
    std::cout << '\n';
    // std::cout << methods::calculate_integral(CALCULATING_METHOD::NEWTON, func5) << '\n'; // logic error
    
    std::cout << "Extremum points of a function number 1\n";
    for (auto m : methods::Calculate_extremum_points(func)) std::cout << m.first << " - " << m.second << '\n';
    std::cout << '\n';
    std::cout << "Extremums of a function number 1\n";
    for (auto m : methods::Calculate_extremums(func)) std::cout << m.first << " - " << m.second << '\n';
    std::cout << '\n';
    std::cout << "Derivative points of quadratic function:\n\n";
    
    for (auto c : methods::Calculate_derivative_points(func6)) std::cout << c << '\n';
    
    std::cout << "\nQuadratic function number 6 is " << func6 -> Evenness() << '\n';
    std::cout << '\n';

    delete func, func2, func3, func4, func5, func6;
    return 0;
}