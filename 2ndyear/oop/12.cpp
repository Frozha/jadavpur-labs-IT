#include<iostream>
#include<string>
using namespace std;

void strcpy(const string &src,string &target){
    target = src;
}

int main(){
    string source;
    cout<<"Enter string to copy : ";
    getline(cin, source);
    cout<<"Entered string is at address : "<<&source<<endl;
    string copy;
    strcpy(source,copy);
    cout<<"copied string : "<<copy<<"\nat address : "<<&copy;
    cout<<"\noriginal string value : "<<source<<" \naddress : "<<&source;
}
