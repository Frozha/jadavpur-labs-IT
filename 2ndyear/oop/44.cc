#define pi 3.141592
#define toradians(n) n*pi/180.0
#define todegrees(k) k*180.0/pi
#include<cmath>
#include<iostream>
#include<vector>
#include<memory>

class Shape{
  public:
    virtual ~Shape(){}
    virtual double getArea() const =0;
    virtual double getVolume() const =0;
};

class Shape2D:public Shape{
  public:
    virtual ~Shape2D(){}
    virtual double getArea() const =0;
    double getVolume() const{ return 0.0; }
};

class Shape3D:public Shape{
  public:
    virtual ~Shape3D(){}
    virtual double getArea() const =0;
    virtual double getVolume() const=0;
};

class Circle:public Shape2D{
  private:
    double radius;
  public:
    Circle(const double Radius):radius(Radius){}
    double getArea()const{return pi*radius*radius;}
    void describe(){std::cout<<"Radius : "<<radius<<std::endl;}
};


class Triangle:public Shape2D{
  private:
    double a,b,c;
    float A,B,C;
    //a,b,c are sides opposites to vertices A,B,C
  public:
    Triangle(const double side1,const double side2,const double side3) : a(side1), b(side2), c(side3) {
        A = todegrees(acos((b * b + c * c - a * a) / (2 * b * c)));
        B = todegrees(acos((a * a + c * c - b * b) / (2 * a * c)));
        C = todegrees(acos((a * a + b * b - c * c) / (2 * a * b)));
        if(A+B+C>360.1 || A+B+C<359.9){
          std::cout<<"triangle cannot be formed.";
          this->~Triangle();
        }
    }

    Triangle(const double side1,const double side2,const float anglebetweensides):a(side1),b(side2),A(anglebetweensides){
        c = sqrt(a * a + b * b - 2 * a * b * cos(toradians(A)));
        B = todegrees(asin(b * sin(toradians(A)) / c));
        C = 180.0f - A - B;
    }
  
    Triangle(const double side1, const float angleoppositetoside2,const float angleoppositetoside3):a(side1),B(angleoppositetoside2),C(angleoppositetoside3){
        A = 180.0f - B - C;
        b = a * sin(toradians(B)) / sin(toradians(A));
        c = a * sin(toradians(C)) / sin(toradians(A));
    }

    void describe() const{
        std::cout << "Sides: " << a << ", " << b << ", " << c << std::endl;
        std::cout << "Angles(degrees): " << A << ", " << B << ", " << C << std::endl;
    }
    
    double getArea() const {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

};

class Ellipse: public Shape2D{
  private:
    double semi_majoraxis;
    double semi_minoraxis;
    double e;
  public:
    Ellipse(const double semi_majoraxis_length,const double semi_minoraxis_length) : semi_majoraxis(semi_majoraxis_length), semi_minoraxis(semi_minoraxis_length) {
      if(semi_majoraxis<semi_minoraxis){
        double temp = semi_minoraxis;
        semi_minoraxis = semi_majoraxis;
        semi_majoraxis = temp;
      }  
      e = sqrt(1 - pow(semi_minoraxis / semi_majoraxis, 2));
    }
  
    double getArea() const {
        return pi * semi_majoraxis * semi_minoraxis;
    }

};


class Sphere:public Shape3D{
  private:
    double radius;
  public:
    Sphere(const double radius){
      if(radius!=0){this->radius = radius;}
      else this->~Sphere();
    }
    double getArea() const{
      return 2*pi*radius*radius;
    }
    double getVolume() const{
      return 4*pi*radius*radius*radius/3.0;
    }
};

class Cube:public Shape3D{
  private:
    double side;
  public:
    Cube(const double sidelength){
      if(sidelength!=0)this->side = sidelength;
      else this->~Cube();
    }
    double getArea()const{return 6.0*side*side;}
    double getVolume()const{return side*side*side;}
};

int main() {
    // Create a vector of shape pointers
    std::vector<Shape*> shapes;
    Shape* temp = new Circle(5.0);
    // Add objects of each concrete class to the vector
    shapes.push_back(temp);
    temp = new Triangle(3.0,4.0,90.0f);
    shapes.push_back(temp);
    temp = new Ellipse(6.0,3.0);
    shapes.push_back(temp);
    temp = new Sphere(2.0);
    shapes.push_back(temp);
    temp = new Cube(3.0);
    shapes.push_back(temp);

    // Process shapes in the vector
    for ( auto shape : shapes) {
        // Check if the shape is a TwoDShape
        if (dynamic_cast<Shape2D*>(shape)) {
            std::cout << "2D Shape: ";
            // Use the virtual function getArea() to get the area
            std::cout << "Area: " << shape->getArea() << std::endl;
        }
        // Check if the shape is a ThreeDShape
        else if (dynamic_cast<Shape3D*>(shape)) {
            std::cout << "3D Shape: ";
            // Use the virtual function getArea() to get the area
            std::cout << "Area: " << shape->getArea() << " ";
            // Use the virtual function getVolume() to get the volume
            std::cout << "Volume: " << shape->getVolume() << std::endl;
        }
        delete shape;
    }

    return 0;
}
