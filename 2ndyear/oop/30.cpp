#include<iostream>
#include<cmath>
using namespace std;

class Point{
    private:
        static Point origin;
        double x ;
        double y ;
        double z ; 
    public:
        Point(double,double, double);
        double distance(const Point = origin) const;
	double operator-(const Point &) const;

};

Point Point::origin(0.0,0.0,0.0);

Point::Point(double a, double b, double c){	
   x=a;
   y=b;
   z=c;
}

double Point::distance(const Point p2) const {
   double dist = sqrt(pow(x-p2.x,2)+pow(y-p2.y,2)+pow(z-p2.z,2));     
   return dist;
}

double Point::operator-(const Point &ob2)const{
	return (*this).distance(ob2);
}

int main(){
    double x,y,z;

    cout<<"Enter coordinates of first point : \nx = ";
    cin>>x;
    cout<<"y = ";
    cin>>y;
    cout<<"z = ";
    cin>>z;
    Point point1(x,y,z);
    
    cout<<"Enter coordinates of second point : \nx = ";
    cin>>x;
    cout<<"y = ";
    cin>>y;
    cout<<"z = ";
    cin>>z;
    Point point2(x,y,z);

    cout<<"distance between point 1 and point 2 : "<<point1 - point2;

}

