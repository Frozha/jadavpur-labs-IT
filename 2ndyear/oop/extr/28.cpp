#include<string>
#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>

using std::string;
using std::vector;

//-------------------------SUBJECTS-----------------------------------
typedef struct Subject{
  int Id;
	string name;
  void show(const int size){
    std::cout<<"SubjectID  SubjectName\n";
    std::cout<<"----------------------\n";
    for(int i=0;i<size;i++){
      std::cout<<this[i].Id<<"\t   "<<this[i].name<<std::endl;
    }
  } 
}Subject;

Subject Subjects[] = {{100,"English"},
                      {101,"Math"},
                      {102,"Physics"},
                      {103,"Chemistry"},
                      {104,"Biology"},
                      {105,"Computer Science"},
                      {106,"History"},
                      {107,"Civics"},
                      {108,"Political Science"},
                      {109,"Economics"},
                      {110,"German"},
                      {111,"Bengali"} ,
                      {112, "Geography"},
                      {113, "Psychology"},
                      {114, "Physical Education"},
                      {115, "Sociology"},
                       {116, "Art"},
                      {117, "Music"},
                      {118, "Statistics"},
                       {119, "French"},
                     {120, "Philosophy"}};

//-----------------------DEPARTMENTS------------------------------------
class Department; //fwd dedclaration for Departmentindx
class Student;//fwd dedclaration for friend of department

//index to search department objects by id
typedef struct Departmentindx{
  int ID;
  Department* objptr;
  Departmentindx(int id,Department* ob){
    ID = id;
    objptr = ob;
  }
}Departmentindx;

class Department{
public:
  static vector<Departmentindx> Created;
private:
  vector<Subject*> subjectlist;
	int ID;
public:
	string deptname;
  Department(int deptID, const std::string departmentName, std::vector<Subject*> subjects)
        : deptname(departmentName) {

  constrbegin:
    for (auto ids : Department::Created){
      if (ids.ID == deptID){
        std::cout<<"Department with this ID already exists.\n Enter new id - ";
        std::cin>>deptID;
        goto constrbegin;
      }
    }
    ID = deptID; 
    Created.push_back(Departmentindx(ID,this));

    std::cout << "Selected subjects for " << departmentName << " Department:\n";

    for (auto subject : subjects) {
      subjectlist.push_back(subject);
      std::cout<<subject->name<<" ";
    }
    std::cout<<"\n\n";
  }
  friend class GradeCard;
};

vector<Departmentindx> Department::Created;


//---------------------------STUDENT--------------------------------------
typedef struct Studentindx{
  int roll;
  Student* objptr;
  Studentindx(int roll, Student* obj){
    this->roll = roll;
    objptr = obj;
  }
}Studentindx;

class Student{
  public:
    static vector<Studentindx> Enrolled;
  protected:
	  string name;
	  int roll;
  public:
	  Department* department;
	  Student(const string name, const int roll_num,int dept_num){
      stdntconstr:
        this->name = name;
        this->roll = roll_num;
        int found =0;
        for(auto deptindx : Department::Created){
          if(deptindx.ID==dept_num){
            found =1;
            department = deptindx.objptr;
            break;
          }
        }
        if(found==0){
        std::cout<<"couldn't find department!\nEnter valid department number - ";
        std::cin>>dept_num;
        goto stdntconstr;
        }
        Enrolled.push_back(Studentindx(roll, this));
    }
    friend class GradeCard;
    void show(){
      std::cout<<roll<<"\t"<<name;
      return;
    }
};
vector<Studentindx> Student::Enrolled;

//-----------------------------GRADECARD-------------------------------------------
class GradeCard {
private:
    Student* studentObj;
    int semesterNum;
    std::vector<std::pair<Subject*, int>> subjectMarks;  // pair of subject pointer and marks
    float CGPA;

    void calculateCGPA() {
        float totalMarks = 0.0;
        int totalSubjects = subjectMarks.size();

        for (const auto& subjectMark : subjectMarks) {
            totalMarks += subjectMark.second;
        }

        // Assuming a simple conversion from total marks to CGPA
        CGPA = totalMarks / (totalSubjects * 10.0);
    }
public:
    static vector<std::pair<Student*, GradeCard*>> Created;
    GradeCard( int rollNum,  int semester) : semesterNum(semester) {
        // Find the student object with the given roll number
        Student* foundStudent = nullptr;
        for (const auto& studentIndex : Student::Enrolled) {
            if (studentIndex.roll == rollNum) {
                foundStudent = studentIndex.objptr;
                break;
            }
        }

        if (foundStudent == nullptr) {
            std::cout << "Student with roll number " << rollNum << " not found.\n";
            this->~GradeCard();
            return;
        }
        studentObj = foundStudent;

        
        std::srand(std::time(0));
        for (const auto& subject : studentObj->department->subjectlist) {
            int marks = rand() % 101;  // Generate a random number between 0 and 100

            subjectMarks.push_back(std::make_pair(subject, marks));
        }
        calculateCGPA();
        GradeCard::Created.push_back({studentObj,this});
    }

    void show() {
        std::cout << "Student Name: " << studentObj->name << "\n";
        std::cout << "Roll Number: " << studentObj->roll << "\n";
        std::cout << "Semester: " << semesterNum << "\n";
        std::cout << "Subject-wise Marks:\n";
        std::cout << "SubjectID  SubjectName  Marks\n";
        std::cout << "--------------------------------\n";

        for (const auto& mark : subjectMarks) {
            std::cout << mark.first->Id << "\t   " << mark.first->name << "\t   " << mark.second << "\n";
        }

        std::cout << "\nCGPA: " << CGPA << "\n";
    }
    float getCGPA(){return CGPA;}
};
vector<std::pair<Student*, GradeCard*>> GradeCard::Created;

int generateRandomRollNumber(int minRoll, int maxRoll) {
    return rand() % (maxRoll - minRoll + 1) + minRoll;
}

int main(){
  auto deptid = 1;
  auto deptname = "sample";
  srand(static_cast<unsigned>(time(NULL)));

      std::vector<Subject*> department1Subjects = {&Subjects[0], &Subjects[1], &Subjects[2], &Subjects[3], &Subjects[4]};
      deptname = "Computer Science";
    Department d1(1,deptname, department1Subjects);

    std::vector<Subject*> department2Subjects = {&Subjects[5], &Subjects[6], &Subjects[7], &Subjects[8], &Subjects[9]};
    deptname = "Social Science";
    Department d2(2, deptname, department2Subjects);

    std::vector<Subject*> department3Subjects = {&Subjects[10], &Subjects[11], &Subjects[12], &Subjects[13], &Subjects[14]};
    deptname = "Humanities";
    Department d3(3, deptname, department3Subjects);

    std::vector<Subject*> department4Subjects = {&Subjects[15], &Subjects[16], &Subjects[17], &Subjects[18], &Subjects[19]};
    deptname = "Arts";
    Department d4(4, deptname, department4Subjects);

    //just to keep anon objects in scope
        std::vector<Student> students;
    std::vector<GradeCard> gradeCards;
        // Create 60 students and generate 60 grade cards in the 3rd semester
    for(int i=1;i<=4;i++){
      students.emplace_back(string("Student"+std::to_string(i)), 1000+i, i);
      gradeCards.emplace_back(1000+i, 3);
    }
    for (int i = 5; i < 60; ++i) {
        std::string studentName = "Student" + std::to_string(i + 1);
        int rollNumber = generateRandomRollNumber(1005, 1999);
        int departmentNumber = generateRandomRollNumber(1, 4);
        
        students.emplace_back(studentName, 1000+i, departmentNumber);
        gradeCards.emplace_back(1000+i, 3);
        //gradeCards.end()->show();
       }


        // Find and display the name and roll number of the student with the highest CGPA in each department
    for (auto departmentIndex : Department::Created) {
      Student* maxStudentObject = nullptr;  
      float maxCGPA = -1.0;

        for (auto gradecardIndex : GradeCard::Created) {
            if (gradecardIndex.first->department == departmentIndex.objptr) {
                float studentCGPA = gradecardIndex.second->getCGPA();
                if (studentCGPA > maxCGPA) {
                    maxCGPA = studentCGPA;
                    maxStudentObject = gradecardIndex.first;
                }
            }
        }

        std::cout << "Department: " << departmentIndex.ID << " - " << departmentIndex.objptr->deptname << "\n";
        std::cout << "Student with the highest CGPA:\n";     
        maxStudentObject->show();
        std::cout<<"\t- CGPA:"<<maxCGPA<<"\n";
    }
    return 0;
  }
