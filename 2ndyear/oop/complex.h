#include <iostream>
#include<cmath>
class Complex{	
		float real, img;
		static Complex origin;
	public:
		Complex(float a=0, float b=0):real(a), img(b){}
    
		float magnitude()const{return(std::sqrt(real*real+img*img));}
		Complex sqrt() const;

		Complex operator+(const Complex &)const;
		Complex operator-(const Complex &)const;
		Complex operator*(const Complex &)const;
		Complex operator/(const Complex &)const;
    
		friend std::ostream& operator<<(std::ostream&, Complex&);
		friend std::istream& operator>>(std::istream&, Complex&);		
    
    bool operator>=(const Complex &) const;
};	

std::ostream& operator<<(std::ostream& os, Complex &obj){
	os<<obj.real;
	if(obj.img!=0)os<<"+("<<obj.img<<")i";
	return os;
}

std::istream& operator>>(std::istream& is, Complex& obj){
	is>>obj.real;
	std::cout<<"+ i";
	is>>obj.img;
	return is;
}

Complex Complex::origin = Complex(0.0,0.0);

Complex Complex::operator+(const Complex &other)const{
	float real_part = this->real+other.real;
	float img_part = this->img+other.img;
return Complex(real_part, img_part);}

Complex Complex::operator-(const Complex &other)const{
	float real_part = this->real-other.real;
	float img_part = this->img-other.img;
return Complex(real_part,img_part);}

Complex Complex::operator*(const Complex &other)const{
	float real_prod1 = (this->real*other.real);
	float real_prod2 = this->img*other.img;
	float img_prod1 = this->real*other.img;
	float img_prod2 = this->img*other.real;
return Complex(real_prod1-real_prod2,img_prod1+img_prod2);}

Complex Complex::operator/(const Complex &other) const {
    float denominator = other.real * other.real + other.img * other.img;
    float real_part = (this->real * other.real + this->img * other.img) / denominator;
    float img_part = (this->img * other.real - this->real * other.img) / denominator;
return Complex(real_part, img_part);}


Complex Complex::sqrt() const{
    float temp1 = std::sqrt((real + std::sqrt(real * real + img * img)) / 2);
    float temp2 = (img >= 0 ? 1 : -1) * std::sqrt((-real + std::sqrt(real * real + img * img)) / 2);
return Complex(temp1, temp2);}

bool Complex::operator>=(const Complex& obj2)const{
  return this->magnitude()>=obj2.magnitude()?true:false;
}
