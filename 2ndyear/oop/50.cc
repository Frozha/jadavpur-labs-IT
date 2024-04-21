#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    try {
        int numerator, denominator;

        std::cout << "Enter numerator: ";
        std::cin >> numerator;

        std::cout << "Enter denominator: ";
        std::cin >> denominator;

        // Check for division by zero
        if (denominator == 0) {
            throw std::string("Division by zero is not allowed.");
        }

        // Perform the division
        double result = static_cast<double>(numerator) / denominator;

        // Display the result
        std::cout << "Result of division: " << result << std::endl;
    } catch (std::string a) {
        // Catch and handle the Exception
        std::cerr << "Exception caught: " << a << std::endl;
    }

    return 0;
}

