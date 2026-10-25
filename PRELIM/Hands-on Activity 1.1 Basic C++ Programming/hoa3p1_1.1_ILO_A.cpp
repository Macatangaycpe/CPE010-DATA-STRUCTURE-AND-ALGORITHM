#include <iostream>

// Function prototypes (declared before main for clarity)
void displaySum(int x, int y);       
bool isGreater(int a, int b);        
bool logicalOperations(bool p, bool q); 

int main() {
    int num1 = 10, num2 = 20;        
    bool val1 = true, val2 = false;  

    // Call function to display sum of num1 and num2
    displaySum(num1, num2);

    // Check if num1 is greater than num2
    if (isGreater(num1, num2)) {
        std::cout << num1 << " is greater than " << num2 << std::endl;
    } else {
        std::cout << num1 << " is not greater than " << num2 << std::endl;
    }

    // Perform logical operations on val1 and val2
    if (logicalOperations(val1, val2)) {
        std::cout << "Logical operations executed successfully." << std::endl;
    }

    return 0; // End of program
}

// Function definition: prints the sum of two integers
void displaySum(int x, int y) {
    std::cout << "Sum of " << x << " and " << y << " is: " << (x + y) << std::endl;
}

// Function definition: returns true if a > b
bool isGreater(int a, int b) {
    return (a > b);
}

// Function definition: demonstrates logical operators
bool logicalOperations(bool p, bool q) {
    // Logical AND
    std::cout << "p AND q: " << (p && q) << std::endl;
    // Logical OR
    std::cout << "p OR q: " << (p || q) << std::endl;
    // XOR (bitwise exclusive OR works fine with bools)
    std::cout << "p XOR q: " << (p ^ q) << std::endl;
    // Logical NOT
    std::cout << "NOT p: " << (!p) << std::endl;
    std::cout << "NOT q: " << (!q) << std::endl;

    // Always returns true (could be improved to return something meaningful)
    return true;
}
