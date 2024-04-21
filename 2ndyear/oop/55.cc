#include <iostream>
#include <cmath>
#include <stdexcept>
#include<string>
class Vehicle {
public:
    Vehicle(int initialPosition) : position(initialPosition) {}

    void move(int distance) {
        position += distance;
    }

    int getPosition() const {
        return position;
    }

private:
    int position;
};

class Lane {
public:
    Lane() : vehicle1(0), vehicle2(50) {} 

    void moveVehicles(int distance);
    void checkCollision() {
        int distance = std::abs(vehicle1.getPosition() - vehicle2.getPosition());
        //distance to avoid collision
        const int collisionThreshold = 10;

        if (distance < collisionThreshold) {
          vehicle1.move(-5);
          vehicle2.move(5);
          throw std::runtime_error("Collision imminent! Distance between vehicles is too small.");
        }
    }

    

    
private:
    Vehicle vehicle1;
    Vehicle vehicle2;
};
void Lane::moveVehicles(int distance) {
        vehicle1.move(distance);
        vehicle2.move(-distance);
        checkCollision();
}
int main() {
    try {
        Lane lane;
        while(1){
          lane.moveVehicles(5);
          std::cout << "Moved both vehicles by 5 towards each other\nNo collision detected. Vehicles are safe." << std::endl;}
    } catch (const std::exception& ex) {
        std::cerr << "Exception caught: " << ex.what() << std::endl;
    }

    return 0;
}

