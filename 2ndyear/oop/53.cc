#include <iostream>
#include"stack.h"
#include<string>
int main() {
        Stack myStack(3);
    try{

        myStack.push(1);
        myStack.push(2);
        myStack.push(3);
        myStack.push(4);//expected exception.
        myStack.display();
    }catch(const std::string ex){
      std::cerr<<"Exception caught: "<<ex<< std::endl;
    }
    try{
        myStack.pop();
        myStack.pop();
        myStack.pop();
        myStack.pop();// Trying to pop from an empty stack (exception expected)
        myStack.display();
    } catch (const std::string ex) {
        std::cerr << "Exception caught: " << ex << std::endl;
    }

    return 0;
}

