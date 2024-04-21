import java.io.*;
import java.util.Scanner;

class ReaderThread implements Runnable{
	boolean[] end;
	boolean[] readerTurn;
	int[] buffer;
	BufferedReader br;
	
	ReaderThread(String path, boolean[] readerTurnBuffer, boolean[] endBuffer, int[] buffer){
		try{
		br = new BufferedReader(new FileReader(path));
                end = endBuffer;
		end[0] = false;
		readerTurn = readerTurnBuffer;
		readerTurn[0] = true;
		this.buffer = buffer;
		}catch(FileNotFoundException f){
		System.out.println("file was not found at "+path);
		end[0] = true;
		}
		
	}

	private int readInt(){
	   try{
		String line = br.readLine();
		readerTurn[0] = true;
		if(line!=null){
		  if(line!=""){ return Integer.parseInt(line);}
		  else{return 0;}
		}
		else{
		  end[0] = true;
		  return 0;
		}
	   }catch(IOException e){e.printStackTrace();return 0;}
	}

	public void run(){
	  while(!end[0]){
	    while(!readerTurn[0]){
	      try{
		Thread.currentThread().sleep(1);
	      }catch(InterruptedException e){e.printStackTrace();}
	    }
	    buffer[0] = readInt();
           
          }try{
	  br.close();}catch(IOException e){e.printStackTrace();}
	}
}

class Main{
  public static void main(String[] arg){
    String path = "nums.txt";
    boolean[] endBuf = new boolean[1];
    boolean[] readerTurnBuf =  new boolean[1];
    int[] resBuf = new int[1];
    int sum = 0;
    
    Thread child = new Thread(new ReaderThread(path, readerTurnBuf, endBuf, resBuf));
   
    while(!endBuf[0]){
      while(readerTurnBuf[0]){
	 try{
           Thread.currentThread().sleep(1);
	 }catch(InterruptedException e){e.printStackTrace();}
      }
      sum = sum + resBuf[0];
      readerTurnBuf[0] = true;
      System.out.println("current sum: "+sum+"  last read : "+resBuf[0]);
    }
  }
}
