#include"complex.h"
#include"stack.h"
#include<iostream>
#include<string>

template<class T> void swap(T& variable1, T& variable2){
  const T temp = variable1;
  variable1 = variable2;
  variable2 = temp;
}

template<> void swap<Stack>(Stack& stack1, Stack& stack2){
 if(stack1.size()==stack2.size()){
    Stack tempstack1(stack1.size()), tempstack2(stack2.size());
    for(int i=0;i<=stack1.top_index()+1;i++){
      tempstack2.push(stack1.pop());
    }
    for(int i=0;i<=stack2.top_index()+1;i++){
      tempstack1.push(stack2.pop());
    }
    for(int i=0;i<=tempstack1.top_index()+1;i++){
      stack1.push(tempstack1.pop());
    }
    for(int i=0;i<=tempstack2.top_index()+1;i++){
      stack2.push(tempstack2.pop());
    }
 } 
 else{
   throw std::string("stack size not equal.");
 }
}

using std::cout;
int main(){
  //remove comment according to test.
 //----custom int ------
 /*
  int a = 10, b=2;
  cout<<a<<", "<<b<<std::endl;
  swap(a,b);
  cout<<a<<", "<<b<<std::endl;
  */
  //----custom stack------
  /*
  Stack s1(4), s2(4);
  s1.push(1);
  s1.push(4);
  s2.push(3);
  s1.display();
  s2.display();
  swap(s1,s2);
  s1.display();
  s2.display();
  */
  //-----custom complex-----
  
  Complex num1(1.0f,2.0f), num2(2.0f,3.0f);
  cout<<"num1 : "<<num1<<std::endl<<"num2 : "<<num2;
  swap<Complex>(num1, num2);
  cout<<"\nswapping\n";
  cout<<std::endl<<"num1 : "<<num1<<std::endl<<"num2 : "<<num2;
  
  }
