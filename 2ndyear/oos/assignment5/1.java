interface Shape{
    void draw();
}

class Circle implements Shape{
    private int radius;
    Circle(int r){
        radius  = r; 
    }
    public void draw(){
        System.out.println("circle");
    }
}

class Square implements Shape{
    private int side;
    Square(int s){
        side = s; 
    }
    public void draw(){
        System.out.println("Square");
    }
}

class Rectangle implements Shape{
    private int length,breadth;
    Rectangle(int l,int b){
        length = l;
        breadth = b;
    }
    public void draw(){
        System.out.println("Rectangle");
    }
}

class ShapeFactory{
    Shape getShape(String type){
        if(type.equalsIgnoreCase("circle")){
            return new Circle(1);
        }
        else if(type.equalsIgnoreCase("square")){
            return new Square(1);
        }
        else if(type.equalsIgnoreCase("rectangle")){
            return new Rectangle(1,2);
        }
        else{
            System.out.println("invalid");
            return null;
        }
    }
}

class Main{
    public static void main(String[] args){
        ShapeFactory generator = new ShapeFactory();
        Shape shape1 = generator.getShape("circle");
        Shape shape2 = generator.getShape("rectangle");
        Shape shape3 = generator.getShape("Square");

        shape1.draw();
        shape2.draw();
        shape3.draw();
    }
}