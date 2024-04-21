#include <iostream>
#include <cmath>

class Vector {
private:
    int size;
    double* element;
    double magnitude;
    void updatemagnitude();

public:
    Vector(int , bool= false);
    Vector(const Vector&);
    ~Vector();
    Vector add(const Vector& ) const;
    Vector subtract(const Vector& ) const;
    bool isEqual(const Vector& ) const;
    bool isGreater(const Vector& ) const;
    bool isLess(const Vector& ) const;

    void print_Vector()const;
};


int main() {
    int n;
    std::cout << "Enter dimension of vector : ";
    std::cin >> n;
    std::cout << "First";
    Vector a(n);
    std::cout << "Second";
    Vector b(n);

    Vector sum = a.add(b);
    Vector diff = a.subtract(b);

    std::cout << "sum : ";
    sum.print_Vector();
    std::cout << "diff: ";
    diff.print_Vector();

    std::cout << "a == b ? " << a.isEqual(b);
    std::cout << "\na > b ? " << a.isGreater(b);
    std::cout << "\na < b ? " << a.isLess(b);

    return 0;
}

void Vector::updatemagnitude(){
    for (int i = 0; i < size; i++) {
        magnitude += element[i] * element[i];
    }
    magnitude = sqrt(magnitude);
}
Vector::Vector(int s, bool empty) : size(s) {
    element = new double[size];
    if (!empty) {
        std::cout << " vector : ";
        for (int i = 0; i < size; i++) {
            std::cin >> *(element + i);
        }
    } else {
        for (int i = 0; i < size; i++) {
            *(element + i) = 0;
        }
    }
    updatemagnitude();
}
Vector::Vector(const Vector& target) : size(target.size) {
    element = new double[size];
    for (int i = 0; i < size; i++) {
        *(element + i) = *(target.element + i);
    }
    magnitude = target.magnitude;
}
Vector::~Vector() {
    delete[] element;
}
Vector Vector::add(const Vector& other) const {
    if (size == other.size) {
        Vector result(size, true);
        for (int i = 0; i < size; i++) {
            result.element[i] = element[i] + other.element[i];
        }
        result.updatemagnitude();
        return result;
    } else {
        return Vector(0);
    }
}
Vector Vector::subtract(const Vector& other) const {
    if (size == other.size) {
        Vector result(size, true);
        for (int i = 0; i < size; i++) {
            result.element[i] = element[i] - other.element[i];
        }
        result.updatemagnitude();
        return result;
    } else {
        return Vector(0);
    }
}
bool Vector::isEqual(const Vector& other) const {
    if (size == other.size) {
        for (int i = 0; i < size; i++) {
            if (element[i] != other.element[i]) {
                return false;
            }
        }
        return true;
    } else {
        return false;
    }
}
bool Vector::isGreater(const Vector& other) const {
    return magnitude > other.magnitude;
}
bool Vector::isLess(const Vector& other) const {
    return magnitude < other.magnitude;
}
void Vector::print_Vector() const{
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << element[i] << " ";
    }
    std::cout << "]\n";
}