class Complex{
  private float real, imaginary;
  Complex(float real, float imaginary){
    this.real = real;
    this.imaginary = imaginary;
  }
  Complex(float real){
    this.real = real;
    this.imaginary = 0.0f;
  }
  Complex(){
    real =0;
    imaginary = 0;
  }
  public Complex add(Complex other){
    Complex ret = new Complex(real+other.real, imaginary+other.imaginary);
    return ret;
  }

  public Complex multiply(Complex other){
    Complex ret = new Complex(((real*other.real)-(imaginary*other.imaginary)), ((real*other.imaginary)+(imaginary*other.real)));
    return ret;
  }
  
  public void show(){
    System.out.println(real+" + "+imaginary+"i");
  }
}

class Main{
  public static void main(String[] arg){
    Complex c1=new Complex(3,2);
    Complex c2=new Complex(4,-2);

    Complex sum = c1.add(c2);
    Complex prod = c1.multiply(c2);
    
    System.out.print("Sum : ");
    sum.show();
    System.out.print("Product : ");
    prod.show();
  } 
}
