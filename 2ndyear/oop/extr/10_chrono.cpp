#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;
void init_stack(){
    cout<<"\n";
}
void swap(int &a,int &b){
	int c = a;
	a = b;
	b =c;
}

void swap(int *a,int *b){
	int c = *a;
	*a = *b;
	*b=c;
}

int main(){
    int a=3,b=4;
    int c=3,d=4;
    init_stack();
    high_resolution_clock::time_point time_2 = high_resolution_clock::now();
    for(int i=0;i<500;i++){
	swap(a,b);
    }
    high_resolution_clock::time_point time_3 = high_resolution_clock::now();
    for(int i=0;i<500;i++){
	swap(&c,&d);
    }
    high_resolution_clock::time_point time_4 = high_resolution_clock::now();

    duration<double> reference =duration_cast<duration<double>>(time_3-time_2);
    duration<double> address =duration_cast<duration<double>>(time_4-time_3);
    
    cout<<"time taken when swapping by :\n";
    cout<<"reference : "<<reference.count()*1000<<" ms\n";
    cout<<"address : "<<address.count()*1000<<" ms\n";

    if(reference.count()>address.count()){
        cout<<"calling by address is faster than reference";
    }
    else{
        cout<<"calling by reference is faster than address";
    }

}
