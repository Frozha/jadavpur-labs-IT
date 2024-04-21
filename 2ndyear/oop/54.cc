#include <iostream>
#include <stdexcept>
#include<string>
class Motor {
public:
    Motor() {
        throw std::runtime_error("Motor troubles");
    }
};

class Car {
public:
    Car() try : motor() {
        std::cout << "Car is successfully initialized." << std::endl;
    } catch (const std::exception& ex) {
        std::cerr << "Car initialization failed: " << ex.what() << std::endl;
        throw;  // Rethrow the exception
    }

private:
    Motor motor;
};

class Garage {
public:
    Garage() try : car() {
        std::cout << "Garage is successfully initialized." << std::endl;
    } catch (const std::exception& ex) {
        // Catch block for Car initialization exception
        std::cerr << "Garage initialization failed: " << ex.what() << std::endl;
        throw std::runtime_error("Garage initialization failed");
    }

private:
    Car car;
};

int main() {
    try {
        Garage garage;
    } catch (const std::exception& ex) {
        std::cerr << "Main caught exception: " << ex.what() << std::endl;
    }

}

