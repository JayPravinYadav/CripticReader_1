#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <filesystem>
#include "read_header.hpp"
#include <boost/math/tools/roots.hpp>

int main() {
    //Testing the csv table readers
    std::vector<double> Log_nH;
    std::vector<double> Temperatures;
    std::vector<std::vector<double>> Mu_grid_slice;
    try {
        read_merged_csv("merged_table.csv", Log_nH, Temperatures, Mu_grid_slice);
        std::cout << "Read merged CSV successfully.\n";
        std::cout << "Temperatures size = " << Temperatures.size() << "\n";
        std::cout << "log_nH size = " << Log_nH.size() << "\n";
        std::cout << "Mu_grid size = " << Mu_grid_slice.size()
                  << " x " << (Mu_grid_slice.empty() ? 0 : Mu_grid_slice[0].size()) << "\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
    }
    std::cout<< "Mu_grid_slice size = " << Mu_grid_slice.size() << "\n";
    std::cout<< "Mu_grid_slice[0] size = " << Mu_grid_slice[0].size() << "\n";
    std::cout<< " mu[5][10]="<< Mu_grid_slice[5][10] << "\n";
    std::cout<< " log_nH[5]="<< Log_nH[5] << "\n";
    std::cout<< " T[10]="<< Temperatures[10] << "\n";
    std::cout<< " Check the above values manually \n";

    //Checking the boost:: bisect method
    auto f = [](double x) {
        return x * x - 2;  // Example function: f(x) = x^2 - 2
    };
        // Maximum iterations counter
    boost::uintmax_t max_iter = 50;

    // Use eps_tolerance (relative tolerance in bits of precision)
    auto tol = boost::math::tools::eps_tolerance<double>(30);
    double root1 = boost::math::tools::bisect(f, 0.0, 2.0, tol, max_iter).first;
    double root2 = boost::math::tools::bisect(f, 0.0, 2.0, tol, max_iter).second;
    std::cout << "Roots found between: " << root1 << " and " << root2 << "\n";

}