#include"complex.h"

int main() {

    Complex c1(3, 4);
    Complex c2(1, -2);
    Complex c3;

    std::cout << "Complex Number 1: " << c1 << std::endl;
    std::cout << "Complex Number 2: " << c2 << std::endl;
    std::cout << "Complex Number 3: " << c3 << std::endl;

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;
    Complex quotient = c1 / c2;

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Difference: " << difference << std::endl;
    std::cout << "Product: " << product << std::endl;
    std::cout << "Quotient: " << quotient << std::endl;

    Complex sqrtResult = c1.sqrt();
    std::cout << "Square root of c1: " << sqrtResult << std::endl;
}

