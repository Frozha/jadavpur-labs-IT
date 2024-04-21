import java.util.HashMap;
import java.util.Map;
class Main{
	public static <E> void freq(E[] array){
		HashMap<E,Integer> map = new HashMap<>();
		for(E elem:array){
			if(map.containsKey(elem)){
			map.replace(elem,map.get(elem)+1);
			}
			else{
			map.put(elem,1);
			}
		}
		for(Map.Entry m:map.entrySet()){
			System.out.println(m.getKey()+" = "+m.getValue());
		}
	}

	public static void main(String[] args){
	Integer[] array = new Integer[]{2,1,4,2,3,4,5,1,2};
	freq(array);

	
	}
}
