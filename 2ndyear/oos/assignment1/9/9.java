import java.util.*;

abstract class Person {
    int age;
    float weightKG;
    float heightCM;
    Date dateOfBirth;
    String address;

    Person(int age, float weightKG, float heightCM, Date dateOfBirth, String address) {
        this.age = age;
        this.weightKG = weightKG;
        this.heightCM = heightCM;
        this.dateOfBirth = dateOfBirth;
        this.address = address;
    }
    abstract void display();
}

class Employee extends Person {
    float salary;
    Date dateOfJoining;
    int experience;

    Employee(int age, float weightKG, float heightCM, Date dateOfBirth, String address,
             float salary, Date dateOfJoining, int experience) {
        super(age, weightKG, heightCM, dateOfBirth, address);
        this.salary = salary;
        this.dateOfJoining = dateOfJoining;
        this.experience = experience;
    }
    void display() {
        System.out.println("Age: " + age);
        System.out.println("Weight: " + weightKG);
        System.out.println("Height: " + heightCM);
        System.out.println("Date of Birth: " + dateOfBirth);
        System.out.println("Address: " + address);
        System.out.println("Salary: " + salary);
        System.out.println("Date of Joining: " + dateOfJoining);
        System.out.println("Experience: " + experience + " years");
    }  
}

class Student extends Person {
    int roll;
    String[] listOfSubjects;
    float[] marks;

    Student(int age, float weightKG, float heightCM, Date dateOfBirth, String address,
            int roll, String[] listOfSubjects, float[] marks) {
        super(age, weightKG, heightCM, dateOfBirth, address);
        this.roll = roll;
        this.listOfSubjects = listOfSubjects;
        this.marks = marks;
    }

    float calculateGrade() {
        float sum = 0;
        for (float mark : marks) {
            sum += mark;
        }
        return sum / marks.length;
    }

    void display() {
        System.out.println("Student Roll: " + roll);
        System.out.println("List of Subjects: " + Arrays.toString(listOfSubjects));
        System.out.println("List of Grades: " + Arrays.toString(marks));
        System.out.println("Average Grade: " + calculateGrade());
    }
}

class Technician extends Employee {
    Technician(int age, float weightKG, float heightCM, Date dateOfBirth, String address,
               float salary, Date dateOfJoining, int experience) {
        super(age, weightKG, heightCM, dateOfBirth, address, salary, dateOfJoining, experience);
    }
}

class Professor extends Employee {
    String[] courses;
    String[] listOfAdvisee;

    Professor(int age, float weightKG, float heightCM, Date dateOfBirth, String address,
               float salary, Date dateOfJoining, int experience,
               String[] courses, String[] listOfAdvisee) {
        super(age, weightKG, heightCM, dateOfBirth, address, salary, dateOfJoining, experience);
        this.courses = courses;
        this.listOfAdvisee = listOfAdvisee;
    }

    @Override
    void display() {
        super.display();
        System.out.println("Courses: " + Arrays.toString(courses));
        System.out.println("List of Advisee: " + Arrays.toString(listOfAdvisee));
    }
}

class Main {
    public static void main(String[] args) {
        Person[] employees = new Person[]{
                new Technician(30, 75.5f, 175.0f, new Date(), "123 Tech Street",
                        50000.0f, new Date(), 5),
                new Professor(40, 80.0f, 180.0f, new Date(), "456 Prof Street",
                        80000.0f, new Date(), 10,
                        new String[]{"Computer Science", "Mathematics"},
                        new String[]{"John Doe", "Jane Smith"})
        };

        Person[] students = new Person[]{
                new Student(20, 65.0f, 170.0f, new Date(), "789 Student Street",
                        101, new String[]{"Math", "Physics", "Chemistry"},
                        new float[]{85.0f, 90.0f, 78.0f}),
                new Student(22, 70.0f, 175.0f, new Date(), "987 Student Street",
                        102, new String[]{"History", "English", "Biology"},
                        new float[]{75.0f, 88.0f, 92.0f}),
                new Student(21, 68.0f, 172.0f, new Date(), "654 Student Street",
                        103, new String[]{"Computer Science", "Statistics", "Economics"},
                        new float[]{80.0f, 85.0f, 88.0f})
        };

        for (Person employee : employees) {
            employee.display();
            System.out.println("--------------------");
        }

        for (Person student : students) {
            ((Student) student).display();
            System.out.println("--------------------");
        }
    }
}

