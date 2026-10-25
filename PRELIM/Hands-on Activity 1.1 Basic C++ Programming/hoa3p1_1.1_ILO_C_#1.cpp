#include <iostream>
int main() {
    int a = 5, b = 10, value;
    value = a;
    a = b;
    b = value;
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;
    return 0;
}
