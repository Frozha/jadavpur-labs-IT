#include<iostream>
using namespace std;

int max(const int &a,const int &b,const int &c){
    int max =a;
    max = (max<b)?b:max;
    max = (max<c)?c:max;
    return max;
}

int max(const int* num_arr,const int &length){
    int max=num_arr[0];
    for(int i=0;i<length;i++){
        max = (max<*(num_arr+i))?num_arr[i]:max;
    }
    return max;
}

int main(){
    int arr[]={1,2,5,3};
    int x(1),y(3),z(2);
    cout<<"max of variables  : "<<max(x,y,z);
    cout<<"\nmax of array : "<<max(arr,4);
}
