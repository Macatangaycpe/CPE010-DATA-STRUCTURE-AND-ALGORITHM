#include <iostream>
double kelvinToFahrenheit(double kelvin) {
    return (kelvin - 273.15) * 9/5 + 32;
}
int main() {
    double kelvin = 300;
    std::cout << kelvin << " K = " << kelvinToFahrenheit(kelvin) << " °F" << std::endl;
    return 0;
}
