class NumberPrinter implements Runnable {
    private static Object lock = new Object();
    private static int last_printed;
    private int start;
    private int stop;
    private int step;
    private int current;

    NumberPrinter(int start, int stop, int step) {
        this.start = start;
        this.stop = stop;
        this.step = step;
        this.current = start;
    }

    public void run() {
        while (current < stop) {
            synchronized (lock) {
                while ((current != (last_printed+1))) {
                    try {
                        lock.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                System.out.print(current + " ");
                last_printed = current;
                current = current + step;
                lock.notifyAll();
            }
        }
    }
}

public class Main {
    public static void main(String[] a) {
        Thread odd = new Thread(new NumberPrinter(1, 9, 2));
        Thread even = new Thread(new NumberPrinter(2, 9, 2));
        odd.start();
        even.start();
    }
}

