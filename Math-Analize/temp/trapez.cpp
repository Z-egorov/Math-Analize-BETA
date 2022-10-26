#include <iostream>
#include <vector>

float f(float x) { return x*x + 6*x + 9; }

int main () {

    int a = 0, b = 10;
    int n = 10;

    std::vector<float> X;
    std::vector<float> Y;

    float h = (b-a) / n;

    for (int i = 0; i <= n; i++) {
        X.push_back(a + i*h);
        Y.push_back(f(X[i]));
    }

    float y_sum = 0;
    for (int i = 0; i < n-1; i++) {
        y_sum += Y[i+1];
    }

    float integral = 0;

    integral = h *((Y[0] + Y[n])/2 + y_sum); 
    std::cout << integral << '\n';

    return 0;
}
