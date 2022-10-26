#ifndef _WORK_MA_FUNCTION__
#define _WORK_MA_FUNCTION__

#include <iostream>
#include <cmath>
#include <vector>

namespace work_MA {

class function {
            public:

                virtual float Newton() const {
                    float integral;
                    integral = 0;

                    return integral;
                }

                float Trapezoid() {
                    int a = limit_a, b = limit_b;
                    int n = 10;

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
                    return integral;

                }

                float Simpson() {
                    float a = limit_a, b = limit_b;
                    int n = 10;

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

                    return integral;
                }

                std::vector<float> Derivative_points() {
                    float dx = 0.1f;

                    for (float i = limit_a; i <= limit_b; i += dx)
                        X.push_back(i); 

                    for (int i = 0; i <= limit_b; i++)
                        Y.push_back((f(X[i]+dx)-f(X[i]))/dx);
                    
                    return Y;
                }
                
                std::vector<float> Function_points() {
                    for (int i = limit_a; i <= limit_b; i++) {
                        X.push_back(i);
                        Y.push_back(f(X[i]));                      
                    }

                    return Y;
                }

                std::string Evenness() { return (f(-1) == f(1)) ? "even" : (f(-1) == -f(1)) ? "odd" : (f(-1) == f(1) && f(-1) == -f(1)) ? "even and odd" : "not even and not odd"; }

                virtual std::vector<float> Solve() const { return {}; }
                virtual std::vector<float> Derivative_solve() const { return {}; }

                float Calculate_point(float x) { return f(x); }
                float Calculate_derivative_point(float x) { return derivative_f(x); }

            protected:

                std::vector<float> X;
                std::vector<float> Y;

                virtual float f(float x) const { return 0; }
                virtual float derivative_f(float x) const { return 0; }

                int limit_a;
                int limit_b;

                void set_limits(int limit_a_, int limit_b_) { limit_a = limit_a_; limit_b = limit_b_; }

        };
}

namespace MA {
    using ::work_MA::function;
}

#endif