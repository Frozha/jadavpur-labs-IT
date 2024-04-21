#include<iostream>
using namespace std;

int factorial(const int num){
	int f=1;
	for(int i=1;i<=num;i++){
		f*=i;
	}
	return f;
}

int main(){
	int fact = factorial(10);
	cout<<"10! = "<<fact;
	return 0;
}
