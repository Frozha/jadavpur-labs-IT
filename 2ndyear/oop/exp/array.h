#pragma once
#ifndef ARRAY_H
#define ARRAY_H
template<class T> class Array{
    T* head;
    int size;
    int current_end;
    bool indexinbounds(int &index)const;
    void extendhead(int &bylength = 10);
  public:
    Array(int size = 1);
    void push_back(T value);  
    T& operator[](int index)const;
    void insert(T value,int index);
    int& length();
    //extern friend std::ostream& operator<<(std::ostream&,Array<T>&);
};


#endif
