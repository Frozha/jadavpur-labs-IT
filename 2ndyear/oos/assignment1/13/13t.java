class Automobile {
    String make;
    String type;
    float maxSpeed;
    float price;
    float mileage;
    int registrationNumber;

    // Appropriate constructor
    public Automobile(String make, String type, float maxSpeed, float price, float mileage, int registrationNumber) {
        this.make = make;
        this.type = type;
        this.maxSpeed = maxSpeed;
        this.price = price;
        this.mileage = mileage;
        this.registrationNumber = registrationNumber;
    }

    // Display function
    void display() {
        System.out.println("Make: " + make);
        System.out.println("Type: " + type);
        System.out.println("Max Speed: " + maxSpeed + " mph");
        System.out.println("Price: $" + price);
        System.out.println("Mileage: " + mileage + " mpg");
        System.out.println("Registration Number: " + registrationNumber);
    }
}

class Track extends Automobile {
    int capacity;
    String hoodType;
    int numberOfWheels;

    // Appropriate constructor
    public Track(String make, String type, float maxSpeed, float price, float mileage, int registrationNumber,
                 int capacity, String hoodType, int numberOfWheels) {
        super(make, type, maxSpeed, price, mileage, registrationNumber);
        this.capacity = capacity;
        this.hoodType = hoodType;
        this.numberOfWheels = numberOfWheels;
    }

    // Overridden display function
    @Override
    void display() {
        super.display();
        System.out.println("Capacity: " + capacity + " persons");
        System.out.println("Hood Type: " + hoodType);
        System.out.println("Number of Wheels: " + numberOfWheels);
    }
}

class Car extends Automobile {
    int noOfDoors;
    int seatingCapacity;

    // Appropriate constructor
    public Car(String make, String type, float maxSpeed, float price, float mileage, int registrationNumber,
               int noOfDoors, int seatingCapacity) {
        super(make, type, maxSpeed, price, mileage, registrationNumber);
        this.noOfDoors = noOfDoors;
        this.seatingCapacity = seatingCapacity;
    }

    // Overridden display function
    @Override
    void display() {
        super.display();
        System.out.println("Number of Doors: " + noOfDoors);
        System.out.println("Seating Capacity: " + seatingCapacity + " persons");
    }
}
class Main {
    public static void main(String[] args) {
        // Create car and track objects and display()
        Car myCar = new Car("Toyota", "Sedan", 120.0f, 25000.0f, 30.0f, 12345, 4, 5);
        Track myTrack = new Track("Ford", "Pickup", 100.0f, 35000.0f, 20.0f, 54321, 2, "Convertible", 6);

        System.out.println("Car Details:");
        myCar.display();

        System.out.println("\nTrack Details:");
        myTrack.display();
    }
}

