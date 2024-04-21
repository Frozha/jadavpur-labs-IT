package ipc;

public class Consumer extends Thread {

  double[] buffer; 
  private double currentSum;
  private int currentIteration;
  private int end;

  public Consumer(double[] buffer, int end) {
    currentSum = 0;
    this.buffer = buffer;
    currentIteration = 0;
    this.end = end;
  }

  private void consumerTask() {
    currentSum = currentSum + 1/buffer[0];
    buffer[0] = -1.0;
  }

  public void run() {
    while (currentIteration != end) {
      while (buffer[0] == -1.0){
        try{
          this.sleep(1);
        }catch(InterruptedException e){
          e.printStackTrace();
        }
      }
        currentIteration++;
        consumerTask();
    }
    System.out.println("sum of "+ end+" terms  : "+ currentSum);
  }
}

