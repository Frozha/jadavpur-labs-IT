#include <iostream>
#include"complex.h"
#include<string>
template<class T> class Stack {
private:
    T* elements;
    int top;
    const int maxSize;  // Define the maximum size of the stack

public:
    Stack(const int &size):maxSize(size),elements(new T[size]), top(-1) {}
    ~Stack() {
        delete[] elements;
    }

    void push(const T& value) {
        if (top >= maxSize - 1) {
            throw std::string("Stack overflow: Cannot push more elements.");
        }
        elements[++top] = value;

    }

    T& pop() {
        if (top < 0) {
            throw std::string("Stack underflow: Cannot pop from an empty stack.");
        }
        return elements[top--];
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

using std::cout;

int main(){
  try{
    Stack<Complex> stack(2);
    stack.push(Complex(1.0f,2.0f));
    stack.push(Complex(3.0f, 3.0f));
    stack.display();
    cout<<"pop<complex> : "<<stack.pop()<<std::endl;
    Stack<int> stack1(2);
    stack1.push(3);
    stack1.push(4);
    stack1.display();
    cout<<"pop<int> : "<<stack1.pop();
  }
  catch(std::string&a){
    std::cerr<<a<<std::endl;
  }
}
