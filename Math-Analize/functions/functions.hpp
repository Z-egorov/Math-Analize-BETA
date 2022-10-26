#ifndef _MA_ALL_FUNCTIONS__
#define _MA_ALL_FUNCTIONS__

#include "function/function.hpp"
#include <stdexcept>

namespace MA {

    namespace functions {

        class linear : public virtual function {

            public:

            linear(int k=0, int b=0, int lim_a=0, int lim_b=0) : k_{k}, b_{b} { set_limits(lim_a, lim_b); }

            float Newton() const override {
                float integral;
                integral = (k_ * (pow(limit_b, 2)/2) +  b_ * limit_b) - (k_ * (pow(limit_a, 2)/2) + b_ * limit_a);
                return integral;
            }

            std::vector<float> Solve() const override { std::vector<float> solves; solves.push_back(k_/b_); return solves; }
            std::vector<float> Derivative_solve() const override { throw std::logic_error("No solves"); }

            private:

            float f(float x) const override { return k_* x + b_; }
            float derivative_f(float x) const override { return k_; }
            
            const int k_;
            const int b_;


        };

        class quadratic : public virtual function {

            public:

            quadratic(int a, int b, int c, int lim_a, int lim_b) : a_{a}, b_{b}, c_{c} { set_limits(lim_a, lim_b); }

            float Newton() const override {
                float integral;
                integral = (a_ * (pow(limit_b, 3)/3) + b_ * (pow(limit_b, 2)/2) + c_ * limit_b) - (a_ * (pow(limit_a, 3)/3) + b_ * (pow(limit_a, 2)/2) + c_ * limit_a);
                return integral;
            }

            std::vector<float> Solve() const override {
                std::vector<float> solves;
                float D = pow(b_, 2) - 4*a_*c_;
                if(D < 0) return {};
                if (D == 0) solves.push_back((-b_+sqrt(D))/2*a_);
                else {
                    solves.push_back((-b_+sqrt(D))/2*a_);
                    solves.push_back((-b_-sqrt(D))/2*a_);
                }
                
                return solves;
            } 
            
            std::vector<float> Derivative_solve() const override {
                std::vector<float> derivative_solves;
                derivative_solves.push_back(-b_/2*a_);
                return derivative_solves;
            }

            private:

            float f(float x) const { return a_ * pow(x, 2) + b_*x + c_; }
            float derivative_f(float x) const override { return 2*a_ + b_; }

           

            const int a_;
            const int b_;
            const int c_;

        };

        class power : public virtual function {

            public:

            power(int n, int lim_a, int lim_b) : n_{n} { set_limits(lim_a, lim_b); }

            float Newton() const override {
                float integral;
                integral = (pow(limit_b, n_+1))/n_+1;
                return integral;
            }

            std::vector<float> Solve() const override { return {0}; }
            std::vector<float> Derivative_solve() const override { return {0}; }
            
            private:

            float f(float x) const override { return pow(x, n_); }

            const int n_;

        };

        class fractional_linear : public virtual function {

            public:

            fractional_linear(int a, int b, int c, int d, int lim_a, int lim_b) : a_{a}, b_{b}, c_{c}, d_{d} { set_limits(lim_a, lim_b); }

            float Newton() const override { throw std::logic_error("Can not be calculated with this method. Try another one"); }

            std::vector<float> Solve() const override {
                std::vector<float> solves;
                solves.push_back(-b_/a_);
                
                return solves;
            }
            std::vector<float> Derivative_solve() const override { return {0}; }

            private:

            float f(float x) { return (a_ * x + b_) / (c_ * x + d_); }
            float derivative_f(float x) const override { return (a_*d_ - b_*c_) / (pow(c_*x + d_, 2)); }
            
            const int a_;
            const int b_;
            const int c_;
            const int d_;

        };

        class exponential : public virtual function{

            public:

            exponential(int a, int lim_a, int lim_b) : a_{a} { set_limits(lim_a, lim_b); }

            float Newton() const override {
                float integral = 0;
                integral = ((1/log1p(a_)) * pow(a_, limit_b) - (1/log1p(a_)) * pow(a_, limit_a));
                return integral;
            }

            std::vector<float> Solve() const override { throw std::logic_error("No solves"); }
            std::vector<float> Derivative_solve() const override { throw std::logic_error("No solves"); }


            private:

            float f(float x) const override { return pow(a_, x); }
            virtual float derivative_f(float x) const override { return pow(a_, x) * log1p(a_); }

            const int a_;

        };

        // class trigonometric : virtual public function {
        //     public:

        //     void Newton() const override {
        //         float integral;
        //         integral = 0;
        //         std::cout << integral << '\n';
        //     }


        //     private:


        // };

    } // namespace functions
} // namespace MA

#endif
