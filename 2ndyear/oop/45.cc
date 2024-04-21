#include<iostream>

class A{
  public:
    virtual ~A(){
      std::cout<<"destructor A called.\n";
    }
};
class BadA{
  public:
    ~BadA(){std::cout<<"destructor BadA called\n";}
};
class B:public A{
  public:
    ~B(){std::cout<<"destructor B called. \n";}
    
};
class BadB:public BadA{
  public:
    ~BadB(){std::cout<<"destructor BadB called.\n";}
};
int main(){
  A* baseptr= new B();
  delete baseptr;
  std::cout<<"virtual destructor in base class doesn't orphan child obj.\n";
  //this will not orphan the class B object
  BadB* temp = new BadB();
  BadA* badbaseptr;
  badbaseptr = temp;
  delete badbaseptr;
  std::cout<<"manually need to call destructor of BadB.\n";
  delete temp;
}
