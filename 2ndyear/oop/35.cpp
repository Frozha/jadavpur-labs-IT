#include<iostream>

class Integer{
  int value;
  public:
  Integer(int value=0):value(value){}
    operator int(){return value;}
    Integer operator++(int){Integer temp(value++);return temp;}
    Integer operator+(Integer &obj){return Integer(value+obj.value);}
};

int main() {
  Integer a = 4, b = a, c;
  c = a+b++;
  int i = a;
  std::cout << a << b << c;
  return 0;
}
