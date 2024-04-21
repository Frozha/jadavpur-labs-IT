#include<iostream>
using namespace std;

const double PI = 3.141592;

double area(const double r){
	return PI*r*r;
}

int main(){
	cout<<"Enter radius of circle to find its area - ";
	double r;
	cin>>r;
	cout<<"Area = "<<area(r);
	return 0;
}

