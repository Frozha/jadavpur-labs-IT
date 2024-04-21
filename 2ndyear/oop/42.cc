#include <iostream>
#include <vector>
#include<string>
class Employee {
protected:
    std::string name;
    double salary;

public:
    Employee(const std::string& empName, double empSalary) : name(empName), salary(empSalary) {}


    std::string getName() const { return name; }
    double getSalary() const { return salary; }

    void setName(const std::string& empName) { name = empName; }
    void setSalary(double empSalary) { salary = empSalary; }

    virtual void printDetails() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Salary: $" << salary << "\n";
    }
};

class Manager : public Employee {
private:
    std::string type;
    double allowance;

public:
    Manager(const std::string& empName, double empSalary, const std::string& empType, double empAllowance)
        : Employee(empName, empSalary), type(empType), allowance(empAllowance) {}

    std::string getType() const { return type; }
    double getAllowance() const { return allowance; }

    void setType(const std::string& empType) { type = empType; }
    void setAllowance(double empAllowance) { allowance = empAllowance; }

    void printDetails() const {
        Employee::printDetails();
        std::cout << "Type: " << type << "\n";
        std::cout << "Allowance: $" << allowance << "\n";
    }
};

class Clerk : public Employee {
private:
    std::string type;
    double allowance;

public:
    Clerk(const std::string& empName, double empSalary, const std::string& empType, double empAllowance)
        : Employee(empName, empSalary), type(empType), allowance(empAllowance) {}

    std::string getType() const { return type; }
    double getAllowance() const { return allowance; }

    void setType(const std::string& empType) { type = empType; }
    void setAllowance(double empAllowance) { allowance = empAllowance; }

    void printDetails() const {
        Employee::printDetails();
        std::cout << "Type: " << type << "\n";
        std::cout << "Allowance: $" << allowance << "\n";
    }
};

int main() {
    std::vector<Employee*> emplist;
    //emplist.emplace_back("Alex Employee",7000.0);

    Manager manager("John Manager", 60000.0, "Senior", 5000.0);
    Clerk clerk("Alice Clerk", 35000.0, "Junior", 2000.0);

    emplist.push_back(static_cast<Employee*>(&manager));
    emplist.push_back(static_cast<Employee*>(&clerk));
    for(auto i : emplist){
      i->printDetails();
    }

    return 0;
}

