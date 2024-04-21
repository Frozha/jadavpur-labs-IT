#include <iostream>
#include <stdexcept>
#include<string>
int main() {
    try {
        int number;
        std::cout << "Enter an integer: ";
        std::cin >> number;

        if (number % 2 == 0) {
            throw number;  // Throw an integer exception if the number is even
        } else {
            throw std::to_string(number);  // Throw a string exception if the number is odd
        }
    } catch (int evenNumber) {
        std::cerr << "Caught an integer exception: Even number (" << evenNumber <<")"<< std::endl;
    } catch (const std::string& oddNumber) {
        // Catch block for string exception
        std::cerr << "Caught a string exception: Odd number (" << oddNumber << ")" << std::endl;
    } catch (...) {
        std::cerr << "Caught an unexpected exception." << std::endl;
    }

    return 0;
}

