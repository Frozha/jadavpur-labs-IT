#include <iostream>
#include <typeinfo>

class Vehicle {
public:
    virtual void display() const = 0;  // Pure virtual function, making Vehicle a polymorphic class
    virtual ~Vehicle() {}
};

class Bus : public Vehicle {
public:
    void display() const {
        std::cout << "\nThis is a Bus." << std::endl;
    }
};

class Car : public Vehicle {
public:
    void display() const  {
        std::cout << "\nThis is a Car." << std::endl;
    }
};

class Bike : public Vehicle {
public:
    void display() const  {
        std::cout << "\nThis is a Bike." << std::endl;
    }
};

int main() {
    Vehicle* vehicles[] = {new Bus(), new Car(), new Bike()};

    for (const auto& vehicle : vehicles) {
        // Illustrating dynamic_cast
        if (dynamic_cast<Bus*>(vehicle)) {
            std::cout << "Dynamic Cast: This is a Bus." << std::endl;
            vehicle->display();
        } else if (dynamic_cast<Car*>(vehicle)) {
            std::cout << "Dynamic Cast: This is a Car." << std::endl;
            vehicle->display();
        } else if (dynamic_cast<Bike*>(vehicle)) {
            std::cout << "Dynamic Cast: This is a Bike." << std::endl;
            vehicle->display();
        }

        // Illustrating typeid
        std::cout << "Type ID: " << typeid(*vehicle).name() << std::endl;

        std::cout << "---------------------" << std::endl;
        delete vehicle;
    }

    return 0;
}

