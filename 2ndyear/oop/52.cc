#include <iostream>
#include<string>

class MyClass {
public:
    class MyException {
    public:
        explicit MyException(const std::string& description) : description(description) {}
        const char* what() const   {
            return description.c_str();
        }

    private:
        std::string description;
    };

    // Member function that throws MyException
    void throwError() const noexcept(false) {
        throw MyException("This is a custom exception from MyClass.");
    }
};

int main() {
    try {
        MyClass myObject;
        myObject.throwError();
    } catch (const MyClass::MyException& ex) {
        // Catch and handle the custom exception
        std::cerr << "Caught exception: " << ex.what() << std::endl;
    }  
}

