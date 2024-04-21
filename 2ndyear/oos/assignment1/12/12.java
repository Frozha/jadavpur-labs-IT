

class Student {
    String name;
    int roll;
    String[] subjects;
    Student(String name, int roll, String subject1, String subject2, String subject3, String subject4, String subject5) {
        this.name = name;
        this.roll = roll;
        subjects = new String[5];
        subjects[0] = subject1;
        subjects[1] = subject2;
        subjects[2] = subject3;
        subjects[3] = subject4;
        subjects[4] = subject5;
    }
    void display() {
        System.out.println("Student Details:");
        System.out.println("Name: " + name);
        System.out.println("Roll: " + roll);
        System.out.println("Subjects: " + String.join(", ", subjects));
    }
}
class Marksheet {
    Student studentdetails;
    float[] marks;
    Marksheet(Student student, float marks1, float marks2, float marks3, float marks4, float marks5) {
        studentdetails = student;
        marks = new float[5];
        marks[0] = marks1;
        marks[1] = marks2;
        marks[2] = marks3;
        marks[3] = marks4;
        marks[4] = marks5;
    }
    void display() {
        studentdetails.display();
        System.out.println("Marks:");
        for (int i = 0; i < marks.length; i++) {
            System.out.println(studentdetails.subjects[i] + ": " + marks[i]);
        }
        System.out.println("----------------------------------");
    }
}
class TabulationSheet {
    Marksheet[] marksheetreference;
    int nextemptyindex = 0;
    int maxelements;
    int subjectindex;
    float[] marks;
    TabulationSheet(int numberofstudents, int subjectindex) {
        marksheetreference = new Marksheet[numberofstudents];
        marks = new float[numberofstudents];
        maxelements = numberofstudents;
        this.subjectindex = subjectindex;
    }
    void append(Marksheet studentmarks) {
        if (nextemptyindex < maxelements) {
            marksheetreference[nextemptyindex] = studentmarks;
            marks[nextemptyindex] = studentmarks.marks[subjectindex];
            nextemptyindex += 1;
        } else {
            System.out.println("Tabulation sheet is full!");
        }
    }
    void display() {
        System.out.println("Tabulation Sheet for Subject " + marksheetreference[0].studentdetails.subjects[subjectindex] + ":");
        for (int i = 0; i < nextemptyindex; i++) {
            Student student = marksheetreference[i].studentdetails;
            System.out.println(  student.roll + " " + student.name + " " + marks[i]);
        }
        System.out.println("------------------------");
    }
}
class Main {
    public static void main(String[] args) {
        Student student1 = new Student("John Doe", 101, "Math", "Physics", "Chemistry", "Biology", "History");
        Student student2 = new Student("Jane Doe", 102, "Math", "Physics", "Chemistry", "Biology", "History");
        Student student3 = new Student("Bob Smith", 103, "Math", "Physics", "Chemistry", "Biology", "History");
        Marksheet marksheet1 = new Marksheet(student1, 90, 85, 78, 92, 88);
        Marksheet marksheet2 = new Marksheet(student2, 88, 92, 76, 89, 95);
        Marksheet marksheet3 = new Marksheet(student3, 94, 87, 91, 78, 84);
        TabulationSheet tabulationSheetMath = new TabulationSheet(3, 0);
        TabulationSheet tabulationSheetPhysics = new TabulationSheet(3, 1);
        TabulationSheet tabulationSheetChemistry = new TabulationSheet(3, 2);
        TabulationSheet tabulationSheetBiology = new TabulationSheet(3, 3);
        TabulationSheet tabulationSheetHistory = new TabulationSheet(3, 4);
        tabulationSheetMath.append(marksheet1);
        tabulationSheetMath.append(marksheet2);
        tabulationSheetMath.append(marksheet3);
        tabulationSheetPhysics.append(marksheet1);
        tabulationSheetPhysics.append(marksheet2);
        tabulationSheetPhysics.append(marksheet3);
        tabulationSheetChemistry.append(marksheet1);
        tabulationSheetChemistry.append(marksheet2);
        tabulationSheetChemistry.append(marksheet3);
        tabulationSheetBiology.append(marksheet1);
        tabulationSheetBiology.append(marksheet2);
        tabulationSheetBiology.append(marksheet3);
        tabulationSheetHistory.append(marksheet1);
        tabulationSheetHistory.append(marksheet2);
        tabulationSheetHistory.append(marksheet3);
        marksheet1.display();
        marksheet2.display();
        marksheet3.display();
        tabulationSheetMath.display();
        tabulationSheetPhysics.display();
        tabulationSheetChemistry.display();
        tabulationSheetBiology.display();
        tabulationSheetHistory.display();
    }
}

