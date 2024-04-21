#include<iostream>
using namespace std;

class IntArray{
private:
    int size;
    int* element;
public:
    IntArray(const IntArray &);
    IntArray(int ,bool =false);
    ~IntArray();
    IntArray join(IntArray &);
    IntArray add(IntArray &);
    void reverse();
    void sort(bool= true);
    void print()const;
};

int main(){
    IntArray a(3);
    cout<<"a : ";
    a.print();

    IntArray copya(a);
    cout<<"copy a :";
    copya.print();

    cout<<"a + a : ";
    IntArray sum(a.add(a));
    sum.print();

    cout<<"a join a : ";
    IntArray j(a.join(a));
    j.print();

    cout<<"rev a : ";
    a.reverse();
    a.print();

    cout<<"sort asc a: ";
    a.sort();
    a.print();

    copya.reverse();
    cout<<"copy a reverse : ";
    copya.print();
}


IntArray::IntArray(const IntArray &target):size(target.size){
    element = new int[size];
    for(int i=0;i<size;i++){
        element[i] = target.element[i];
    }
}
IntArray::IntArray(int s,bool empty):size(s){
    element = new int[size];
    
    if(!empty){
        cout<<"enter array : ";
        for(int i=0;i<size;i++){
            cin>>element[i];
        }
    }
    else{
        for(int i=0;i<size;i++){
            element[i] = 0;
        }
    }
}
IntArray::~IntArray(){
    delete element;
}
IntArray IntArray::join(IntArray &other){
    int joinsize = size + other.size;
    IntArray joined(joinsize,true);
    int i;
    for(i=0;i<size;i++){
        joined.element[i] = element[i];
    }
    for(;i<size+other.size;i++){
        joined.element[i] = other.element[i-size];
    }
    return joined;
}
IntArray IntArray::add(IntArray &other){
    if(size==other.size){
        IntArray sum(size,true);
        for(int i=0;i<size;i++){
            sum.element[i] = element[i]+other.element[i];
        }
        return sum;
    }
    else return IntArray(0);
}
void IntArray::reverse(){
    int temp;
    for(int i=0;i<size/2;i++){
        temp = element[i];
        element[i] = element[size - 1 - i];
        element[size - 1 - i] = temp;
    }
}
void IntArray::sort(bool ascending ){
    if(ascending){
        int min = element[0],min_index=0;
        for(int i=0;i<size;i++){
            min = element[i];
            min_index=i;
            for(int j=i;j<size;j++){
                if(min>element[j]){
                    min = element[j];
                    min_index = j;
                }
            }
            element[min_index] = element[i];
            element[i] = min;
        }
    }
    else{
        this->sort();
        this->reverse();
    }
}
void IntArray::print()const{
    for(int i=0;i<size; i++){
        cout<<element[i]<<" ";
    }
    cout<<endl;
}