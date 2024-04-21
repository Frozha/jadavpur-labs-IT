#include <iostream>
#include <cmath>
#include<string>

class Shape {
public:
    Shape(const std::string& name) : shapeName(name) {}

    virtual ~Shape() {
        std::cout << "Destructor of Shape called." << std::endl;
    }

    virtual double area() const = 0;

    virtual void display() const {
        std::cout << "Shape: " << shapeName << std::endl;
    }

private:
    std::string shapeName;
};

class Circle : public Shape {
public:
    Circle(double radius) : Shape("Circle"), radius(radius) {}

    ~Circle(){
        std::cout << "Destructor of Circle called." << std::endl;
    }

    double area() const  {
        return M_PI * radius * radius;
    }

    void display() const  {
        Shape::display();
        std::cout << "Radius: " << radius << std::endl;
    }

private:
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(double length, double width) : Shape("Rectangle"), length(length), width(width) {}

    ~Rectangle()  {
        std::cout << "Destructor of Rectangle called." << std::endl;
    }

    double area() const  {
        return length * width;
    }

    void display() const  {
        Shape::display();
        std::cout << "Length: " << length << ", Width: " << width << std::endl;
    }

private:
    double length;
    double width;
};

class Trapezoid : public Shape {
public:
    Trapezoid(double base1, double base2, double height) : Shape("Trapezoid"), base1(base1), base2(base2), height(height) {}

    ~Trapezoid()  {
        std::cout << "Destructor of Trapezoid called." << std::endl;
    }

    double area() const  {
        return 0.5 * (base1 + base2) * height;
    }

    void display() const  {
        Shape::display();
        std::cout << "Base1: " << base1 << ", Base2: " << base2 << ", Height: " << height << std::endl;
    }

private:
    double base1;
    double base2;
    double height;
};

int main() {
    Shape* shapes[] = {
        new Circle(5.0),
        new Rectangle(4.0, 6.0),
        new Trapezoid(3.0, 5.0, 4.0)
    };

    for (const auto& shape : shapes) {
        shape->display();
        std::cout << "Area: " << shape->area() << std::endl;
        delete shape;
        std::cout << "---------------------" << std::endl;
    }

    return 0;
}

