#include"polynomial.cpp"

int main(){
    int size;
    cout<<"for first polynomial enter number of elements -";
    cin>>size;
    polynomial poly1(size);
    poly1.init();
    cout<<"for second polynomial enter number of elements -";
    cin>>size;
    polynomial poly2(size);
    poly2.init();

    polynomial prod{prod.product(poly1,poly2)};

    prod.display();

}