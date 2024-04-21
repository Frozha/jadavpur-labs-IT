class Stack{
  int size;
  int[] array;
  int currenttopindex;

  Stack(int size){
    array = new int[size];
    currenttopindex = 0;
    this.size = size;
  }
  
  public Stack push(int element){
    if(currenttopindex==size){
      System.out.println("Overflow!");
    }
    else{
      array[currenttopindex++] = element;
    }
    return this;
  }

  public int pop(){
    if(currenttopindex == 0){
      System.out.println("Underflow!");
      return -1;
    }
    else{
      int popped = array[--currenttopindex];
      System.out.println("popped : "+popped);
      return popped;
    }
  }

  public void print(){
    System.out.println("stack : ");
    for(int i=currenttopindex-1;i>=0;i--){
      System.out.println("\t"+array[i]);
    }
    System.out.println("----------------");
  }
}


class Demo{
  public static void main(String[] args){
    //stack size in commandline argument
    int arg = Integer.parseInt(args[0]);
    Stack mystack = new Stack(arg);
    mystack.push(10);
    mystack.push(20);
    mystack.push(30);
    mystack.push(15).push(9);
    
    mystack.print();

    mystack.pop();
    mystack.pop();
    mystack.pop();

    mystack.print();

  }
}
