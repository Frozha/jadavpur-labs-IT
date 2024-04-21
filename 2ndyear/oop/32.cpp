#include"complex.h"


class Quardratic{
    private:
        Complex a,b,c;
    public:
        Quardratic():a(0),b(0),c(0){}
        Quardratic(Complex, Complex, Complex);
        Quardratic operator+(const Quardratic &)const;
        friend std::istream& operator>>(std::istream&, Quardratic&);
        friend std::ostream& operator<<(std::ostream&, Quardratic&);
        Complex evaluate(const Complex)const;
        void roots() const; 
};

std::ostream& operator<<(std::ostream &os, Quardratic &object){
    os<<"("<<object.a<<")x^2 +("<<object.b<<")x +("<<object.c<<")";
    return os;
}

std::istream& operator>>(std::istream& istr,Quardratic &obj){
    using std::cout;
    cout<<"Enter complex coefficients. enter 0 for imaginary part if purely real coefficient"<<std::endl;
    cout<<std::endl<<"Enter coefficent of x^2 term := ";
    istr>>obj.a;
    cout<<"Enter coefficent of x term := ";
    istr>>obj.b;
    cout<<"Enter constant term := ";
    istr>>obj.c;
    return istr;
}

Quardratic::Quardratic(Complex a, Complex b, Complex c){
    this->a= a;
    this->b = b;
    this->c = c;
}

Quardratic Quardratic::operator+(const Quardratic &other) const{
    return Quardratic(a+other.a, b+other.b, c+other.c);
}

Complex Quardratic::evaluate(const Complex x)const{
    Complex res = c;
    res = res + b*x;
    res = res + a*x*x;
    return res;
}

void Quardratic::roots() const {
    Complex discriminant = (b * b) - (a * c * 4.0);
    Complex root1 = (b*(-1.0) + discriminant.sqrt()) / (a);
    root1 = root1/2.0;
    Complex root2 = (b*(-1.0) - discriminant.sqrt()) / (a);
    root2= root2/2.0;

    std::cout << "Roots : " << root1 << std::endl << "\t" << root2;
}

int main(){
    Quardratic q1;
    std::cin >> q1;
    std::cout << "Quadratic Equation: " << q1 << std::endl;
    Complex x;
    std::cout<<"Enter value at which function is to be evaluated : ";
    std::cin>>x;
    Complex evalResult = q1.evaluate(x);
    std::cout << "Evaluation at "<<x<<": " << evalResult << std::endl;
    q1.roots();
    
}
