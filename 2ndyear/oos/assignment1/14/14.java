import java.util.*;

class Coordinate {
    public double x, y;
   
    Coordinate(double x, double y) {
        this.x = x;
        this.y = y;
    }
    Coordinate() {
        this(0.0, 0.0);
    }

    public void rotate(double angleDegree) {
        double angleRadian = Math.toRadians(angleDegree);
        double[][] matx = {{Math.cos(angleRadian), -Math.sin(angleRadian)}, {Math.sin(angleRadian), Math.cos(angleRadian)}};
        double[] newCoords = new double[2];
        double[] oldCoords = {x, y};
        double temp = 0;

        for (int row = 0; row < 2; row++) {
            temp = 0;
            for (int col = 0; col < 2; col++) {
                temp = temp + matx[row][col] * oldCoords[col];
            }
            newCoords[row] = temp;
        }
        x = newCoords[0];
        y = newCoords[1];
    }

    public void move(double shiftXBy, double shiftYBy) {
        x = x + shiftXBy;
        y = y + shiftYBy;
    }

    public void display() {
        System.out.println("Coordinates: (" + x + ", " + y + ")");
    }
    public double distanceFrom(Coordinate other) {
        return Math.sqrt(Math.pow(this.x - other.x, 2) + Math.pow(this.y - other.y, 2));
    }
}

interface Shape {
    double area();
    void draw();
    void rotate(double angleDegree);
    void move(double x, double y);
}

class Circle implements Shape {
    double radius;
    Coordinate center;

    Circle(double xCenter, double yCenter, double radius) {
        center = new Coordinate(xCenter, yCenter);
        if (radius > 0) {
            this.radius = radius;
        } else {
            this.radius = -radius;
        }
    }

    Circle(double radius) {
        this(0.0, 0.0, radius);
    }

    public double area() {
        return Math.PI * radius * radius;
    }
    public void draw() {
        System.out.println("Coordinates of Circle for drawing");
        center.display();
    }

    public void rotate(double angleDegree) {
        center.rotate(angleDegree);
    }

    public void move(double shiftXBy, double shiftYBy) {
        center.move(shiftXBy, shiftYBy);
    }
}

class Rectangle implements Shape {
    Coordinate[] points = new Coordinate[4];

    Rectangle(double xCenter, double yCenter, double length, double breadth) {
        if (length > 0 && breadth > 0) {
            double halfLength = length / 2;
            double halfBreadth = breadth / 2;

            points[0] = new Coordinate(xCenter - halfLength, yCenter - halfBreadth);
            points[1] = new Coordinate(xCenter + halfLength, yCenter - halfBreadth);
            points[2] = new Coordinate(xCenter + halfLength, yCenter + halfBreadth);
            points[3] = new Coordinate(xCenter - halfLength, yCenter + halfBreadth);
        } else {
            for (int i = 0; i < 4; i++) {
                points[i] = new Coordinate();
            }
        }
    }

    Rectangle(double length, double breadth) {
        this(0.0, 0.0, length, breadth);
    }
    public double area() {
        double length = points[0].distanceFrom(points[1]);
        double width = points[1].distanceFrom(points[2]);

        return length * width;
    }

    public void draw() {
        System.out.println("Coordinates of Rectangle for drawing");
        for (Coordinate point : points) {
            point.display();
        }
    }

    public void rotate(double angleDegree) {
      double centerx = 0;
      double centery = 0;

      for (Coordinate point : points) {
        centerx = centerx + point.x;
        centery = centery + point.y;
      }
      centerx = centerx /4;
      centery = centery/4;
      
      for (Coordinate point : points) {
        point.move(-centerx,-centery);
      }
      for (Coordinate point : points) {
         point.rotate(angleDegree);
      }
      for (Coordinate point : points) {
         point.move(centerx,centery);
      } 
    }

    public void move(double shiftXBy, double shiftYBy) {
        for (Coordinate point : points) {
            point.move(shiftXBy, shiftYBy);
        }
    }
}

class Main {
    public static void main(String[] args) {
        Rectangle rectangle1 = new Rectangle(2.0, 4.0); 
        Rectangle rectangle2 = new Rectangle(1.5, 1.5, 3.0, 2.0); 
        Rectangle rectangle3 = new Rectangle(1.0,1.0,10.0, 5.0); 
        Circle circle1 = new Circle(5.0);
        Circle circle2 = new Circle(2.0, 2.0, 3.0);

        rectangle1.rotate(45.0);
        rectangle2.move(2.0, 1.0);
        rectangle3.rotate(30.0);
        rectangle3.move(-1.0,-1.0);

        circle2.rotate(30.0);
        circle1.move(1.0, 1.0);

        System.out.println("Details of Rectangle 1:");
        System.out.println("Area: " + rectangle1.area());
        rectangle1.draw();
        System.out.println("\nDetails of Rectangle 2:");
        System.out.println("Area: " + rectangle2.area());
        rectangle2.draw();
        System.out.println("\nDetails of Rectangle 3:");
        System.out.println("Area: " + rectangle3.area());
        rectangle3.draw();
 

        System.out.println("\nDetails of Circle 1:");
        System.out.println("Area: " + circle1.area());
        circle1.draw();
        System.out.println("\nDetails of Circle 2:");
        System.out.println("Area: " + circle2.area());
        circle2.draw();
    }
}

