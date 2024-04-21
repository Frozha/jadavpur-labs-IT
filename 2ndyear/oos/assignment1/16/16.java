interface Fruit{
  boolean hasAPeel();
  boolean hasARoot();
}

interface Vegetable{
  boolean hasAPeel();
  boolean hasARoot();
}

class Tomato implements Fruit, Vegetable{
  public boolean hasARoot(){
    return false;
  }
  public boolean hasAPeel(){
    return true;
  }
}

class Main {
  public static void main(String[] args) {
    Tomato tomato = new Tomato();
    System.out.println("Tomato has a peel: " + tomato.hasAPeel());
    System.out.println("Tomato has a root: " + tomato.hasARoot());
    }
}
