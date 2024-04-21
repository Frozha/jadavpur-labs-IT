#include<iostream>
using namespace std;

class complex{
	private:
		float real;
		float img;
		
	public:
		complex(float r=0, float i=0){
			real = r;
			img = i;
		}
		
		float getReal()const{
			return real;
		}
		
		float getImg()const{
			return img;
		}
		
		void setReal(float a){
			real = a;
		}
		
		void setImg(float b){
			img = b;
		}
		
		void disp()const{
			cout<<real<<"+ i"<<img;
		}
		
		complex sum(complex b){
			return complex(real+b.real,img+b.img);
		}
		
};

int main(){
	complex a(1,2);
	complex b(3,4);
	complex c = a.sum(b);
	
	cout<<"a: ";
	a.disp();
	
	cout<<"\nb: ";
	b.disp();
	
	cout<<"\nc: ";
	c.disp();
	
}
