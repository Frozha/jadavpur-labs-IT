import java.util.Arrays;
import java.util.Random;

class BinarySearch implements Runnable{
  int startIndex;
  int endIndex;
  int currentIndex;
  int[] array;
  int target;
  static boolean found = false;
  static int threadsExhausted = 0;
  BinarySearch(int[] searchArray,int startIndex, int endIndex, int target){
    array = searchArray;
    this.startIndex = startIndex;
    this.endIndex = endIndex;
    this.target = target;
    currentIndex = (startIndex+endIndex)/2;
  }
  private int updateCurrentIndex(){
    if(array[currentIndex]>target){
      endIndex = currentIndex;
      currentIndex = (endIndex+startIndex)/2;
    }
    else{
      startIndex = currentIndex;
      currentIndex = (endIndex+startIndex)/2;
    }
    return currentIndex;
  }
  public void run(){
    while(!found && currentIndex!=updateCurrentIndex()){
        if(array[currentIndex]==target){
          System.out.println("found "+target+" at index "+currentIndex+"\nby thread : "+ Thread.currentThread().getId());
          found = true;
        }
    }
    threadsExhausted++;
  }
}

class ThreadManager{
  int lastIndex;
  int[] array;
  int target;
  ThreadManager(int[] searchArray,int target){
    lastIndex = searchArray.length;
    array = searchArray;
    Arrays.sort(array);
    this.target = target;
    for(int i = 0;i<(lastIndex+1)/10;i++){
      Thread temp = new Thread(new BinarySearch(array,i*10,i*10+9,target));
      temp.start();
    }

    while(BinarySearch.threadsExhausted!=(lastIndex+1)/10){
      try{
        Thread.currentThread().sleep(1);
      }catch(InterruptedException e){
        e.printStackTrace();
      }
    }
    if(!BinarySearch.found){
      System.out.println(target +" is not in array.");
    }
  }
}



public class Main {
    public static void main(String[] args) {
        int[] searchArray = generateRandomArray(50);
        int target = searchArray[23];
        //int target = 43;
        ThreadManager threadManager = new ThreadManager(searchArray, target);
        System.out.println("Array: " + Arrays.toString(searchArray));
    }

    private static int[] generateRandomArray(int size) {
        int[] array = new int[size];
        Random random = new Random();
        for (int i = 0; i < size; i++) {
            array[i] = random.nextInt(100);
        }
        return array;
    }
}

