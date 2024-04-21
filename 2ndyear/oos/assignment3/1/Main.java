import java.util.Arrays;
class Main{
    public static <E extends Comparable<E>> void sort(E[] array){
        int length = array.length;
        E temp;
        //bubble sort
        for(int i=0;i<length;i++){
            for(int j=1;j<length-i;j++){
                if(array[j-1].compareTo(array[j])>0){
                    temp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = temp;
                }
            }
            System.out.println(Arrays.toString(array));
        }
    }

    public static void main(String[] args){
        Integer[] arr = new Integer[]{5,3,4,2,1};
        System.out.println(Arrays.toString(arr));
        sort(arr);
    }
}