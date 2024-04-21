#include<iostream>
using namespace std;

class base1{
    public:
        base1(){
            cout<<"base1 constructor"<<endl;
        }         
};

class base2{
    public:
        base2(){
            cout<<"base2 constructor"<<endl;
        }  
    
};

class derived: public base1, public base2{
    public:
        derived(){
            cout<<"derived constructor"<<endl;
        }  
};

int main(){
    derived obj;
}