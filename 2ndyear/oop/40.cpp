#include<iostream>
using namespace std;

class A{
    public:
        A(){
            cout<<"A constructor called!\n";
        }
};
class B{
    public:
        B(){
            cout<<"B constructor called!\n";
        }
};
class C{
    public:
        C(){
            cout<<"C constructor called!\n";
        }
};

class D:public A, public B{
    public:
        D(){
            cout<<"D constructor called!\n";
        }
};
class E:public B, public C{
    public:
        E(){
            cout<<"E constructor called!\n";
        }
};

class F:public D, public E{
    
    public:
        F(){
            cout<<"F constructor called!\n";
        }
};

int main(){
    F obj;
}