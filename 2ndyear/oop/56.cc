#include <iostream>
#include"complex.h"
#include<string>
using std::cout;
using std::string;

template<class T> T& max(T& ob1, T& ob2){
  return ob1>=ob2?ob1:ob2; 
}

template<> string& max<string>(string& str1,string& str2){
  return str1.length()>=str2.length()?str1:str2;
}

int main(){
  //---string----
  /*
  string n = "Hrithvik";
  string m = "kondalkar";
  */
  //----Complex----
  //Complex n(1.0f,2.0f), m(1.1f, 2.0f);
  //====== int =====
  //int n =5, m=7;
  //cout<<max(n,m);
}
