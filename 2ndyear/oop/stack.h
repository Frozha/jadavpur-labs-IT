#include <algorithm>
#include<iostream>

class Stack {
private:
    int* elements;
    int top;
    const int maxSize;  // Define the maximum size of the stack

public:
    Stack(const int size):maxSize(size),elements(new int[size]), top(-1) {}
    ~Stack() {
        delete[] elements;
    }

    void push(int value) {
        if (top >= maxSize - 1) {
            throw std::string("Stack overflow: Cannot push more elements.");
        }

        elements[++top] = value;
        //std::cout << "Pushed element: " << value << std::endl;
    }

    int pop() {
        if (top < 0) {
            throw std::string("Stack underflow: Cannot pop from an empty stack.");
        }

        int topElement = elements[top--];
        //std::cout << "Popped element: " << topElement << std::endl;

        return topElement;
    }

    void display() const {
        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << elements[i] << " ";
        }
        std::cout << std::endl;
    }

    int size()const {return maxSize;}
    int top_index()const {return top;}
};

