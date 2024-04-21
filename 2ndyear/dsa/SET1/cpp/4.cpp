#include"polynomial.cpp"

int main(){
    int size;
    cout<<"for first polynomial enter number of elements -";
    cin>>size;
    polynomial poly1(size);
    poly1.init();
    double x;
    cout<<"Evaluate entered polynomial for x = ";
    cin>>x;
    printf("f(%.2lf) = %lf ",x,poly1.eval(x));
}