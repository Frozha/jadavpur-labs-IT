#include<iostream>
#include<ctime>
using namespace std;

inline void sum(int &inline_sum,const int &a,const int &b,const int &c){
     inline_sum = a + b + c;
}

int sum_(int a,int b,int c){
    return a+b+c;
}
int main(){
    int x=1,y=2,z=3;
    int inline_sum;
    int non_inline_sum;
    clock_t time_1,time_2,time_3;
    time_1=clock();
    for(int i=0;i<10000000;i++){
	sum(inline_sum,x,y,z);
    }
    time_2= clock();
    for(int i=0;i<10000000;i++){
	non_inline_sum=sum_(x,y,z);
    }
    time_3= clock();

	time_3=time_3-time_2;
	time_2=time_2-time_1;
   
    
    cout<<"inline sum : "<<inline_sum<<"\ntime taken : "<<((float)time_2)*1000/CLOCKS_PER_SEC<<"ms";
    cout<<"\nnon inline sum : "<<non_inline_sum<<"\ntime taken : "<<((float)time_3)*1000/CLOCKS_PER_SEC<<"ms";
}
