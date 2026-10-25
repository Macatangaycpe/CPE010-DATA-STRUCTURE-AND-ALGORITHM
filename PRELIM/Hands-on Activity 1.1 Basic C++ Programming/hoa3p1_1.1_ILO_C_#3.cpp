#include <iostream>
#include <cmath>
double distance(double x1, double y1, double x2, double y2) {
    return std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));
}
int main() {
    std::cout << "Distance: " << distance(2, 3, 7, 8) << std::endl;
    return 0;
}
