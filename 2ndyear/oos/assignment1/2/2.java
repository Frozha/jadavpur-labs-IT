class Student{
  String name;
  float marks1, marks2, marks3;
  Student(String name){
    this.name = name;
  }
  public void setmarks(float m1, float m2, float m3){
    marks1 = m1;
    marks2 = m2;
    marks3 = m3;
  }
  private float average(){
    return (marks1+marks2+marks3)/3;
  }
  public void display(){
    System.out.println("Name  : "+name);
    System.out.println("\tPhysics : "+marks1);
    System.out.println("\tChemistry : "+marks2);
    System.out.println("\tMaths : "+marks3);
    System.out.println("\tAverage : "+ average());
    System.out.println("----------------------------");
  }
}

class Demo{
  public static void main(String[] args){
    String temp = new String("hrithvik kondalkar");
    Student s1 = new Student(temp);
    s1.setmarks(75.9f, 89.3f, 82.3f);
    s1.display();
  }
}
