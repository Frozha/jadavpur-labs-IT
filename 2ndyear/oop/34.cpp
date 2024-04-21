#include<iostream>

class IndexOutOfBounds{
  public:
    IndexOutOfBounds(){std::cout<<"Index out of Bounds.";}
};

class IntArray{
    int *head;
    int size;
  public:
    IntArray(int length):size(length){
      head = new int[size];
    }
    int& operator[](int index){
      if (index<size&&index>=0)return head[index];
      else throw IndexOutOfBounds();
    }
    ~IntArray(){
      delete[] head;
    }
    friend std::ostream& operator<<(std::ostream &, IntArray &);
};

std::ostream& operator<<(std::ostream &os, IntArray &obj){
  for(int i=0;i<obj.size;i++){
    os<<obj.head[i]<<" ";
  }
  os<<std::endl;
  return os;
}


int main() {
  IntArray i(10);
  for(int k = 0; k < 10; k++){
    try{
      i[k] = k;
    }
    catch(IndexOutOfBounds &k){}
    std::cout << i;
  }
return 0;
}
