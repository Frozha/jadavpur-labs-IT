#include<iostream>
#include<cmath>
namespace assignment{
  class Complex{
	float r,i;
     public:  
	Complex(float r, float i){
	  this->r = r;
	  this->i = i;
	  std::cout<<"constr called";
	}
  };
};

int main(){
 assignment::Complex c1(0.1, 0.2);
}
