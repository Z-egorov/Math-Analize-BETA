#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

float f(float x) { return pow(x, 2); }

// derivative - производная
// differentiation - дифференцирование

int main() {
    
    std::vector<float> X;
    std::vector<float> Y;

    float dx = 0.1f;
    int n = 10;

    for (float i = 0; i <= n; i += dx)
        X.push_back(i); 

    for (int i = 0; i <= n; i++)
        Y.push_back((f(X[i]+dx)-f(X[i]))/dx);

    return 0;
}