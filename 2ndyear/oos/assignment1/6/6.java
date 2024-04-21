class Employee{
  private static int currid = 1001;
  private String name;
  public int id;
  private String address;
  private float salary;

 
  Employee(String name, String address, float salary){
    id = (currid++);
    this.name = name;
    this.address = address;
    this.salary = salary;
  }


  public void show(){
    System.out.println("Name : "+name);
    System.out.println("ID : "+id);
    System.out.println("Address : "+address);
    System.out.println("Salary : $"+salary);
    System.out.println("----------------------------------");
  }
  public float getsal(){
    return salary; 
  }
}

 
class Dept{
  public Employee employees[];
  public String name;
  public String location;
  private int currentinsertionindex;
  private int maxemployees;

  Dept(String name, int numberofemployees, String location){
    this.name = name;
    employees = new Employee[numberofemployees];
    this.location = location;
    currentinsertionindex =0;
    maxemployees = numberofemployees;
  }

  public void add(String name, String address, float salary){
    if(currentinsertionindex==maxemployees){
     System.out.println("department is full!!");
    }
    else{
      employees[currentinsertionindex++] = new Employee(name, address, salary);
    }
  }

  public void remove(int id){
    if(currentinsertionindex==0){
      System.out.println("no employees in department!!");
    }
    else{
      for(int i = currentinsertionindex-1;i>=0;i--){
        if(employees[i].id == id){
          while(i!=currentinsertionindex-1){
            employees[i] = employees[i+1];
            i++;
          }
          employees[i] = null;
          currentinsertionindex--;
          break;
        }
      }
    }
  }


  public float annualexpenditure(){
    float temp = 0;
    for(int i=currentinsertionindex-1;i>=0;i--){
      temp+=employees[i].getsal();
      employees[i].show();
    }
    return temp;
  }

}

 
class Demo{
  public static void main(String[] args){
    Dept it = new Dept("Information Technology", 5, "Jadavpur University Salt Lake Campus");
    it.add("Rohini basak", "address1", 1500000);
    it.add("Palash kundu", "address2", 1300000);
    it.add("Bhaskar sardar","address3", 1700000);
    it.add("Bibhas Chandra Dhara", "address4", 2400000);
    it.add("tohida rehman", "address5", 1400000);
    float temp = it.annualexpenditure();
    System.out.println("annual expenditure : "+temp);
  }
}

