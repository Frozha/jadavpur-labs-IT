#include<iostream>
using namespace std;

int factorial(const int &a){
    int b =a;
    int fact = 1;
    for(;b!=1;b--){
        fact*=b;
    }
    return fact;
}

int main(){
    const int a=10;
    cout<<"10! = "<<factorial(a);
}