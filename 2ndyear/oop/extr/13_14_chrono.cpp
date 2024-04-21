#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;
void init_stack(){
    cout<<"";
}
inline int sum(int a,int b,int c){
    return a+b+c;
}

int sum_(int a,int b,int c){
    return a+b+c;
}
int main(){
    int x=1,y=2,z=3;
    int inline_sum;
    int non_inline_sum;
    init_stack();
    high_resolution_clock::time_point time_1= high_resolution_clock::now();
    for(int i=0;i<100;i++){
	inline_sum=sum(x,y,z);
    }
    high_resolution_clock::time_point time_2= high_resolution_clock::now();
    for(int i=0;i<100;i++){
	non_inline_sum=sum_(x,y,z);
    }
    high_resolution_clock::time_point time_3= high_resolution_clock::now();

    duration<double> inline_sum_time = duration_cast<duration<double>>(time_2-time_1);
    duration<double> non_inline_sum_time = duration_cast<duration<double>>(time_3-time_2);
    
    cout<<"inline sum : "<<inline_sum<<"\ntime taken : "<<inline_sum_time.count()*1000<<"ms";
    cout<<"\nnon inline sum : "<<non_inline_sum<<"\ntime taken : "<<non_inline_sum_time.count()*1000<<"ms";
}
