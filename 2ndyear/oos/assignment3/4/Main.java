import java.lang.reflect.*;
class Test{
	public int field1;
	private int field2;
	
	public Test(int a, int b){
		field1 = a;
		field2 = b;
	}
	public void print(){
		System.out.println("field1 = "+field1);
		System.out.println("field2 = "+field2);
	}
	public void method1(){
		System.out.println("method1 called");
	}

	private void method2(){
		System.out.println("method2 called");
	}
}
class Main{
	public static void main(String[] a)throws Exception{
		Test obj = new Test(1,2);
		Class c = obj.getClass();
		System.out.println(c);
		System.out.println("-----------------------------------");	
	
		Method[] m = c.getMethods();
		for(Method meth:m){System.out.println(meth);}
		System.out.println("-----------------------------------");	
		
		Constructor[] cons = c.getConstructors();
		for(Constructor t:cons){System.out.println(t);}	
		System.out.println("-----------------------------------");
		
		Field[] f = c.getFields();
		for(Field z : f){System.out.println(z);}
		System.out.println("-----------------------------------");
		
		Method m2 = c.getDeclaredMethod("method2");
		System.out.println(m2);		
		m2.setAccessible(true);
		m2.invoke(obj);
		System.out.println("-----------------------------------");
		
		Field f2 = c.getDeclaredField("field2");
		f2.setAccessible(true);
		System.out.println(f2 + " = " + f2.get(obj));
		System.out.println("-----------------------------------");
	
	}
}

