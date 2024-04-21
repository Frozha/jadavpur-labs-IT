#include<iostream>
using namespace std;
class base{
    protected:
        int a;
    public:
        base(){
           a  = 10;
        }
};

class derived:public base{
    public:
        void print(){
            cout<<"a : "<<a<<endl;
        }
};

int main(){
	derived obj;
	obj.print();
}
