#include<iostream>
using namespace std;

class Rectangle{
    public:
        Rectangle(double, double);
        double area() const;

    private:
         double length;
         double breadth;
};

Rectangle::Rectangle(double l, double b):length(l),breadth(b){}

double Rectangle::area() const{
	return length*breadth;
}

int main(){
    Rectangle r1(1,2);
    Rectangle r2(2,3);
    Rectangle r3(3,4);
    Rectangle r4(4,5);
    cout<<"area of rectangle 1 : "<<r1.area();
    cout<<"\narea of rectangle 2 : "<<r2.area();     
    cout<<"\narea of rectangle 3 : "<<r3.area();
    cout<<"\narea of rectangle 4 : "<<r4.area();

}
