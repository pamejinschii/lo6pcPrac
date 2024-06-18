#include <iostream>
#include <cmath>
#include <vector>

double f(const std::vector<double>& x) {
    return exp(x[0]*x[0] + x[1]*x[1]) + log(4 + x[1]*x[1] + 2*x[2]*x[2]);
}

std::vector<double> coordinate_descent(double alpha, int max_iter) {
    std::vector<double> x = {0, 0, 0}; // Начальная точка
    for (int iter = 0; iter < max_iter; ++iter) {
        for (int i = 0; i < x.size(); ++i) {
            std::vector<double> x_temp = x;
            x_temp[i] += alpha;
            if (f(x_temp) < f(x)) {
                x[i] += alpha;
            } else {
                x[i] -= alpha;
            }
        }
    }
    return x;
}

int main() {
    double alpha = 0.01;
    int max_iter = 1000;
    std::vector<double> optimum = coordinate_descent(alpha, max_iter);

    std::cout << "Оптимальая точка: ";
    for (double val : optimum) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    std::cout << "оптимальное значение  функции: " << f(optimum) << std::endl;

    return 0;
}
