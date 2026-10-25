#include <iostream>

class Triangle {
private:

    double angleA, angleB, angleC, totalAngle;

public:

    Triangle(double A, double B, double C) {
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A + B + C;
    }

    void setAngles(double A, double B, double C) {
        angleA = A;
        angleB = B;
        angleC = C;
        totalAngle = A + B + C;
    }

    const bool validateTriangle() {
        return (totalAngle == 180 && angleA > 0 && angleB > 0 && angleC > 0);
    }

    std::string classifyTriangle() {
        if (!validateTriangle()) return "Not a valid triangle";

        if (angleA == 90 || angleB == 90 || angleC == 90)
            return "Right triangle";

        else if (angleA > 90 || angleB > 90 || angleC > 90)
            return "Obtuse triangle";

        else
            return "Acute triangle";
    }
};

int main() {

    Triangle set1(40, 30, 110);

    if (set1.validateTriangle()) {
        std::cout << "The shape is a valid triangle.\n";
        std::cout << "Type: " << set1.classifyTriangle() << std::endl;
    } else {
        std::cout << "The shape is NOT a valid triangle.\n";
    }

    return 0;
}
