#include<iostream>
using namespace std;
int add(int a,int b=0,int c=0){
    return a+b+c;
}

int main(){
    int x(1),y(2),z(3);
    cout<<"1+2+3 = "<<add(x,y,z);
    cout<<"\n1+2 = "<<add(x,y);
    cout<<"\n1 = "<<add(x);

}
