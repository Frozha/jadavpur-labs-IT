class TestThread implements Runnable{
  Thread t;
  TestThread(String name){
    t = new Thread(this, name);
    t.start();
  }
  public void run(){
    System.out.println("In "+ t.getName() + " thread");
  }
}
public class Main{
  public static void main(String[] a){
    System.out.println("In main thread"); 
    TestThread child = new TestThread("Child");
  }
}
