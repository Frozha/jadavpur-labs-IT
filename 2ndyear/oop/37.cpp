#include <iostream>

class Integer {
    int value;

public:
    Integer(int val = 0) : value(val) {}

    operator int() const {
        return value;
    }

};

class Index {
    int value;
  public:
    Index(int value) : value(value) {}
    operator Integer()const{
      return Integer(value);
    }
    Index operator+(Index&obj2)const{
      return Index(value+obj2.value);
    }
    Index& operator=(int num){
      value = num;
      return *this;
    }
    operator int() const{
      return value;
    }

    
};

int main(){
  Index in(4), out(10);
  int x = in;
  int y = in + out;
  in = 2;
  Integer i;
  i = in;
}
