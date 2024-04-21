#include <iostream>
#include <string>

class Student {
public:
    Student(const std::string& name, int id) : name(name), studentId(id) {}

    virtual void display() const = 0;  // Pure virtual function, making Student an abstract class
    virtual ~Student(){};
protected:
    std::string name;
    int studentId;
};

class Engineering : public Student {
public:
    Engineering(const std::string& name, int id, const std::string& major) : Student(name, id), engineeringMajor(major) {}

    void display() const {
        std::cout << "Engineering Student:" << std::endl;
        std::cout << "Name: " << name << ", ID: " << studentId << ", Major: " << engineeringMajor << std::endl;
    }

private:
    std::string engineeringMajor;
};

class Medicine : public Student {
public:
    Medicine(const std::string& name, int id, const std::string& specialization)
        : Student(name, id), medicineSpecialization(specialization) {}

    void display() const {
        std::cout << "Medicine Student:" << std::endl;
        std::cout << "Name: " << name << ", ID: " << studentId << ", Specialization: " << medicineSpecialization << std::endl;
    }

private:
    std::string medicineSpecialization;
};

class Science : public Student {
public:
    Science(const std::string& name, int id, const std::string& field) : Student(name, id), scienceField(field) {}

    void display() const {
        std::cout << "Science Student:" << std::endl;
        std::cout << "Name: " << name << ", ID: " << studentId << ", Field: " << scienceField << std::endl;
    }

private:
    std::string scienceField;
};

int main() {
    const int numStudents = 3;
    Student* students[numStudents];

    students[0] = new Engineering("John Doe", 101, "Computer Science");
    students[1] = new Medicine("Jane Smith", 102, "Cardiology");
    students[2] = new Science("Alice Johnson", 103, "Physics");

    for (int i = 0; i < numStudents; ++i) {
        students[i]->display();
        std::cout << "---------------------" << std::endl;
        delete students[i];
    }

    return 0;
}

