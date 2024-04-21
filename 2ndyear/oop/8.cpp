#include<iostream>
using namespace std;


void swap(int &a,int &b){
	cout<<"\nSwapping by reference\n";
	int c = a;
	a = b;
	b =c;
}

int main(){
	int a = 10;
	int b = 21;
	cout<<"a = "<<a<<" b = "<<b;
	swap(a,b);
	cout<<"a = "<<a<<" b = "<<b<<endl;
	return 0;

}


