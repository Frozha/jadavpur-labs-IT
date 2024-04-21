#include<iostream>
#include<ctime>
using namespace std;

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
    clock_t time_2,time_3,time_4;
    time_2 = clock();
    for(int i=0;i<100000000;i++){
	swap(a,b);
    }
    time_3 = clock();
    for(int i=0;i<100000000;i++){
	swap(&c,&d);
    }
    time_4=clock();
    
    cout<<"time taken when swapping by :\n";
    cout<<"reference : "<<((double)(time_4-time_3))*1000/CLOCKS_PER_SEC<<" ms\n";
    cout<<"address : "<<((double)(time_3-time_2))*1000/CLOCKS_PER_SEC<<" ms\n";


}
