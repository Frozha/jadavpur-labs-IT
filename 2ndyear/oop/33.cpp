class INT {
    int i;
  public :
    INT(int a):i(a){}
    INT operator++(){i++;return *this;}
    INT operator++(int){INT temp = *this;i++;return temp;}
    operator int(){return i;}

};


#include<iostream>

int main() {
  int x = 3;
  INT y = x;
  y++ = ++y;
  x = y;
  std::cout<<x;
  return 0;
}
