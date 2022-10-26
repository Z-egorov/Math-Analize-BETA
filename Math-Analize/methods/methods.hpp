#ifndef _MA_METHODS__
#define _MA_METHODS__

#include "../functions/functions.hpp"
#include "../options/options.hpp"
#include <map>

namespace MA {

    namespace methods {

        float Calculate_integral(CALCULATING_METHOD calculating_methods, function* f) { 
            switch (calculating_methods) {
                case CALCULATING_METHOD::NEWTON:
                    return f -> Newton();
                    break;
                case CALCULATING_METHOD::TRAPEZOID:
                    return f -> Trapezoid();
                    break;
                case CALCULATING_METHOD::SIMPSON:
                    return f -> Simpson();
                    break;
                default:
                    return f -> Newton();
                    break;
            }
        }

        std::vector<float> Calculate_derivative_points(function* f) { return f -> Derivative_points(); }
        
        std::map<float, std::string> Calculate_extremum_points(function* f) {
            std::map<float, std::string> extremum_points;
            std::vector<float> solves = f -> Derivative_solve();
            try {

                for (int i = 0; i < solves.size(); i++)
                    if (f -> Calculate_derivative_point(solves[i] - 0.1) < 0 && f -> Calculate_derivative_point(solves[i] + 0.1) > 0)
                        extremum_points.insert(std::pair<float, std::string>(solves[i], "MINIMUM POINT"));
                    else if (f -> Calculate_derivative_point(solves[i] - 0.1) > 0 && f -> Calculate_derivative_point(solves[i] + 0.1) < 0)
                        extremum_points.insert(std::pair<float, std::string>(solves[i], "MAXIMUM POINT"));
                    else if ((f -> Calculate_point(solves[i] - 0.1)) > (f -> Calculate_point(solves[i])) && (f -> Calculate_point(solves[i] + 0.1)) > (f -> Calculate_point(solves[i])))
                        extremum_points.insert(std::pair<float, std::string>(solves[i], "MINIMUM POINT"));
                    else if ((f -> Calculate_point(solves[i] - 0.1)) < (f -> Calculate_point(solves[i])) && (f -> Calculate_point(solves[i] + 0.1) < f -> Calculate_point(solves[i])))
                        extremum_points.insert(std::pair<float, std::string>(solves[i], "MAXIMUM POINT"));
            } catch (std::logic_error) { throw std::logic_error("Function has no extremum points\n"); }

            return extremum_points;
        }

        std::map<float, std::string> Calculate_extremums(function* f) {
            std::map<float, std::string> extremum_points = methods::Calculate_extremum_points(f);
            std::map<float, std::string> extremums;
            auto it = extremum_points.begin();
            extremums.insert(std::pair<float, std::string>(f -> Calculate_point(it -> first), it -> second));

            return extremums;
        }

    } // namespace methods
} // namespace MA

#endif
