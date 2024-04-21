#include<iostream>
using namespace std;


int main(){
	for(int i =0;i<=100;i++){
		float celcius = i;
		float farenh = (9*celcius/5)+32;
		cout<<celcius<<"C = "<<farenh<<"F\n";
	}		
	return 0;
}
