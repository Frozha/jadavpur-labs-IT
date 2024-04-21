#include<iostream>
#include<cmath>
#define _USE_MATH_DEFINES
using namespace std;

class shape2d{
    public:
    virtual float area()const=0;
    virtual float perimeter()const=0;      
};

class circle:public shape2d{
    const float radius;
    public:
        circle(float &r):radius(r){}
        float area()const{
            return  M_PI*radius*radius;
        }
        circle(circle &c):radius(c.getradius()){}
        float perimeter()const{
            return M_PI*2*radius;
        }
        float getradius()const{
            return radius;
        }
};

class rectangle:public shape2d{
    const float length;
    const float breadth;
    public:
        rectangle(float &l, float &b):length(l),breadth(b){}
        float area()const{
            return  length*breadth;
        }
        rectangle(rectangle &r):length(r.getlength()),breadth(r.getbreadth()){}

        float perimeter()const{
            return 2*(length+breadth);
        }
        float getlength()const{
            return length;
        }
        float getbreadth()const{
            return breadth;
        }
};

int main(){
    float a = 10, b =5;
    circle c1(a);
    rectangle r1(b,a);
    shape2d *ptr = &c1;
    cout<<"area of circle : "<<ptr->area()<<" perimeter of circle : "<<ptr->perimeter();
    ptr = &r1;
    cout<<"\narea of rectangle : "<<ptr->area()<<" perimeter of rectangle : "<<ptr->perimeter() <<endl;
}

