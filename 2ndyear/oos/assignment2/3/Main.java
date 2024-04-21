import ipc.Producer;
import ipc.Consumer;

public class Main {
  public static void main(String[] a) {
    double[] buffer = new double[1]; 
    Thread producer = new Thread(new Producer(buffer, 10));
    Thread consumer = new Thread(new Consumer(buffer, 10));
    producer.start();
    consumer.start();
  }
}

