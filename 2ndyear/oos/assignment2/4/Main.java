import java.io.*;

class ReaderThread implements Runnable {
    boolean[] end;
    boolean[] readerTurn;
    int[] buffer;
    BufferedReader br;

    ReaderThread(String path, boolean[] readerTurnBuffer, boolean[] endBuffer, int[] buffer) {
        try {
            br = new BufferedReader(new FileReader(path));
            end = endBuffer;
            end[0] = false;
            readerTurn = readerTurnBuffer;
            readerTurn[0] = true;
            this.buffer = buffer;
        } catch (FileNotFoundException f) {
            System.out.println("File was not found at " + path);
            end[0] = true;
        }
    }

    private int readInt() {
        try {
            String line = br.readLine();
            readerTurn[0] = true;
            if (line != null && !line.isEmpty()) {
                return Integer.parseInt(line);
            } else {
                end[0] = true;
                return 0;
            }
        } catch (IOException e) {
            e.printStackTrace();
            return 0;
        }
    }

    public synchronized void run() {
        while (!end[0]) {
            while (!readerTurn[0]) {
                try {
                    wait();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            buffer[0] = readInt();
            readerTurn[0] = false;
            notify();
        }
        try {
            br.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}

class Main {
    public static void main(String[] arg) {
        String path = "nums.txt";
        boolean[] endBuf = new boolean[1];
        boolean[] readerTurnBuf = new boolean[1];
        int[] resBuf = new int[1];
        int sum = 0;

        ReaderThread readerThread = new ReaderThread(path, readerTurnBuf, endBuf, resBuf);
        Thread child = new Thread(readerThread);
        child.start();

        synchronized (readerThread) {
            try {
                while (!endBuf[0]) {
                    while (readerTurnBuf[0]) {
                        readerThread.wait();
                    }
                    sum += resBuf[0];
                    readerTurnBuf[0] = true;
                    System.out.println("Current sum: " + sum + "  Last read: " + resBuf[0]);
                    readerThread.notify();
                }
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

