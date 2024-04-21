package ipc;

public class Producer extends Thread {
  double[] buffer;
  private double previousFactorial;
  private int currentIteration;
  private int end;
  public Producer(double[] buffer, int end) {
    this.buffer = buffer;
    this.buffer[0] = -1.0;
    this.end = end;
    currentIteration = 0;
    previousFactorial = 1.0;
  }
  private double nextFactorial() {
    previousFactorial = previousFactorial * currentIteration;
    return previousFactorial;
  }

  private void producerTask() {
    buffer[0] = nextFactorial();
  }

  public void run() {
    while (currentIteration != end) {
      while (buffer[0] != -1.0){
        try{
          this.sleep(1);
        }catch(InterruptedException e){
          e.printStackTrace();
        }
      }
      currentIteration++;
      producerTask();
    }
  }
}

