class Room{
  private float height, width, breadth;
  Room(float height, float width, float breadth){
    this.height = height;
    this.width = width;
    this.breadth = breadth;
  }
  public float volume(){
    return (height*width*breadth);
  }
}

class RoomDemo{
  public static void main(String[] args){
    Room obj1 = new Room(2,10,12);
    System.out.println("volume of room 1 = "+obj1.volume());
    Room obj2 = new Room(2,5,6);
    System.out.println("volume of room 2 = "+obj2.volume());
  }
}
