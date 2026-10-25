#include <iostream>

class Triangle {
private:
    // Private member variables to store angles
    double angleA, angleB, angleC, totalAngle;

public:
    // Constructor: initializes angles and computes total
    Triangle(double A, double B, double C) {
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A + B + C;
    }

    // Setter method: allows updating angles after object creation
    void setAngles(double A, double B, double C) {
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A + B + C;
    }

    // Validates if the angles form a proper triangle
    // Conditions: sum must equal 180, and all angles > 0
    const bool validateTriangle() {
        return (totalAngle == 180 && angleA > 0 && angleB > 0 && angleC > 0);
    }

    // Classifies the triangle based on its angles
    std::string classifyTriangle() {
        if (!validateTriangle()) return "Not a valid triangle";

        // Right triangle: one angle exactly 90
        if (angleA == 90 || angleB == 90 || angleC == 90)
            return "Right triangle";
        // Obtuse triangle: one angle greater than 90
        else if (angleA > 90 || angleB > 90 || angleC > 90)
            return "Obtuse triangle";
        // Acute triangle: all angles less than 90
        else
            return "Acute triangle";
    }
};

int main() {
    // Example: 40 + 30 + 110 = 180, valid triangle
    Triangle set1(40, 30, 110);

    // Validate and classify
    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
        std::cout << "Type: " << set1.classifyTriangle() << std::endl;
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
}
