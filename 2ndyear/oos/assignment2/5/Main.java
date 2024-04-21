class Adder implements Runnable{
  int current;
  int end;
  int step;
  int[] buffer;
  Adder(int start, int stop, int step, int[] buffer){
    current = start;
    end = stop;
    this.step = step;
    this.buffer = buffer;
    buffer[0] = 0;
  }
  public void run(){
    synchronized(buffer){
      while(current<end){
        buffer[0] = buffer[0]+current;
        current = current + step;
      }
    }
  }
}

class Main{
  public static void main(String[] a){
    int[] bufferOdd = new int[1];
    int[] bufferEven = new int[1];

    Thread odd = new Thread(new Adder(1,101,2,bufferOdd));
    Thread even = new Thread(new Adder(2,101,2, bufferEven));

    odd.start();
    even.start();
   try{ 
      odd.join();
      even.join();
      int sum = bufferOdd[0]+bufferEven[0];
      System.out.println("Sum = "+sum);
    }catch(InterruptedException e){
      e.printStackTrace();
    } 
  }
}
