import java.util.Date;

 class ChatRoom {
   public static void showMessage(User user, String message){
      System.out.println(new Date().toString() + " [" + user.getName() + "] : " + message);
   }
}

 class User {
   private String name;
   public User(String name){
      this.name  = name;
   }
   public String getName(){return name;}
   public void sendMessage(String message){
      ChatRoom.showMessage(this,message);
   }
}

 class Main {
   public static void main(String[] args) {
      User u1 = new User("user1");
      User u2 = new User("user2");

      u1.sendMessage("Hi!");
      u2.sendMessage("Hello!");
   }
}