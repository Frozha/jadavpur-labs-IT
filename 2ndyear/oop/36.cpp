#include<iostream>

class Table{
  int rows, columns;
  int* head;
  public:
    Table(int rows, int columns):rows(rows),columns(columns){
      head = new int[rows*columns];
    }
    ~Table(){
      delete[] head;
    }
    friend std::istream& operator>>(std::istream&, Table&);
    friend std::ostream& operator<<(std::ostream&, Table&);
    int* operator[](int row_index)const{
      return &head[row_index*columns];
    }
    Table(Table& obj):rows(obj.rows),columns(obj.rows){
      head = new int[rows*columns];
      for(int i;i<rows*columns;i++){
        this->head[i] = obj.head[i];
      }
    }
    Table& operator=(Table& obj){
      delete[] head;
      rows = obj.rows;
      columns = obj.columns;
      head = new int[rows*columns];
      for(int i=0;i<rows*columns;i++){
        head[i]=obj.head[i];
      }
      return *this;
    }
};

std::istream& operator>>(std::istream& is, Table& obj){
  std::cout<<"Enter table of dimensions "<<obj.rows<<" x "<<obj.columns<<std::endl;
  for(int i=0;i<obj.rows;i++){
    for(int j=0;j<obj.columns;j++){
      is>>obj.head[i*obj.columns+j];
    }
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, Table&obj){
  for(int i=0;i<obj.rows;i++){
    for(int j=0;j<obj.columns;j++){
      os<<obj.head[i*obj.columns+j]<<" ";
    }
    os<<std::endl;
  }
  return os;
}


int main(){
  Table t(4, 5), t1(4, 5);
  std::cin >> t;
  t[0][0] = 5;
  int x = t[2][3];
  t1 = t;
std::cout <<"x: "<<x<<std::endl<< t << std::endl << t1;
}
