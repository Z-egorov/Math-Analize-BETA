#include <iostream>
#include <vector>

float f(float x) { return x*x + 6*x + 9; }

int main () {

    float a = 0, b = 10;
    int n = 10;

    std::vector<float> X;
    std::vector<float> Y;

    float h = ((b-a) / (2*n));

    for (int i = 0; i <= 2*n; i++) {
        for (float j = 0; j <= 2*n; j += h)
            X.push_back(j);
        Y.push_back(f(X[i]));
    }

    float y_even_sum = 0;
    float y_odd_sum = 0;

    for (int i = 2; i < 2*n-1; i +=2)
        y_even_sum += Y[i];
    for (int i = 1; i <= 2*n-1; i+=2)
        y_odd_sum += Y[i];

    float integral = 0;
    integral = (h/3) * ((Y[0] + Y[2*n]) + 2*y_even_sum + 4*y_odd_sum);
    
    std::cout << integral << '\n';

    return 0;
}