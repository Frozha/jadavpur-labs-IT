import java.util.HashMap;
import java.util.Map;
class Main{
	public static <E> void dupl(E[] array){
		HashMap<E,Boolean> map = new HashMap<>();
		for(E elem:array){
			if(map.containsKey(elem)){
			map.replace(elem,true);
			}
			else{
			map.put(elem,false);
			}
		}
		System.out.print("Duplicate Elements : ");
		for(Map.Entry m:map.entrySet()){
			if((boolean)m.getValue()){System.out.print(m.getKey()+ " ");}
		}
	}

	public static void main(String[] args){
	Integer[] array = new Integer[]{2,1,4,2,3,4,5,1,2};
	dupl(array);

	
	}
}