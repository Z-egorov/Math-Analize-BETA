#include <iostream>
#include <cmath>
#include <vector>

enum class functions { LINEAR=0, QUADRATIC=1, POWER=2, EXP=3, FRAC=4 };

float f0(float x) { return 3*x + 2; }
float f1(float x) { return x*x + 6*x + 9; }
float f2(float x) { return pow(x, 3); }
float f3(float x) { return pow(2, x); }
float f4(float x) { return (3 * x + 2)/(2 * x + 1); }

float solve(functions f) {
    switch(f) {
        case functions::LINEAR:
            return -2/3;

        case functions::QUADRATIC:
            return -3;

        case functions::POWER:
            return 0;

        case functions::EXP:
            break;

        case functions::FRAC:
            return -2/3;

    }


}

std::vector<float> extremums(functions f) {
        std::vector<float> extrems;
        std::vector<float> extrems_points;
        switch(f) {
        case functions::LINEAR:

            extrems = {};
            extrems_points = {};

        case functions::QUADRATIC:

            extrems = {-6/18};
            extrems_points = {extrems[0]};

        case functions::POWER:

            extrems = {};
            extrems_points = {};

        case functions::EXP:

            extrems = {};
            extrems_points = {};

        case functions::FRAC:
            extrems = {};
            extrems_points = {};

    }
}

int main() {
    

    return 0;
}
