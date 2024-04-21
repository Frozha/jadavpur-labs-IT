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

abstract class ShapeDecorator implements Shape{
    Shape decoratingthis;
    ShapeDecorator(Shape originalShape){
        decoratingthis = originalShape;
    }
    public void draw(){
        decoratingthis.draw();
    }
    public void newFunctionality(){
        System.out.println("new functionality");
    }
}

class NewShape extends ShapeDecorator{
    NewShape(Shape olderShape){
        super(olderShape);
    }
    public void draw(){
        super.decoratingthis.draw();
        super.newFunctionality();
    }
}

class Main{
    public static void main(String[] args){
        Shape oldshape = new Circle(1);
        Shape newshape = new NewShape(oldshape);

        oldshape.draw();
        System.out.println("--------------");
        newshape.draw();

    }
}