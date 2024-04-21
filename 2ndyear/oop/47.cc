#include <iostream>
#include <string>

class Person {
public:
    Person(const std::string& name) : name(name) {}

    void display() const {
        std::cout << "Person: " << name << std::endl;
    }

private:
    std::string name;
};

class Employee : virtual public Person {
public:
    Employee(const std::string& name, int employeeId) : Person(name), employeeId(employeeId) {}

    void displayEmployee() const {
        std::cout << "Employee ID: " << employeeId << std::endl;
    }

private:
    int employeeId;
};

class Student : virtual public Person {
public:
    Student(const std::string& name, int studentId) : Person(name), studentId(studentId) {}

    void displayStudent() const {
        std::cout << "Student ID: " << studentId << std::endl;
    }

private:
    int studentId;
};

class Manager : public Employee, public Student {
public:
    Manager(const std::string& name, int employeeId, int studentId, const std::string& department)
        : Person(name), Employee(name, employeeId), Student(name, studentId), department(department) {}

    void displayManager() const {
        display();  
        displayEmployee();
        displayStudent();  
        std::cout << "Department: " << department << std::endl;
    }

private:
    std::string department;
};

int main() {
    Manager manager("John Doe", 123, 456, "IT");
    manager.displayManager();

    return 0;
}
