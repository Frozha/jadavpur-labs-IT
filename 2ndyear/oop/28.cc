#include <iostream>
#include <vector>
#include <algorithm>  // For std::max_element
#include<ctime>
#include<string>
class Subject {
public:
    int Id;
    std::string name;

    Subject(int id, const std::string& subjectName) : Id(id), name(subjectName) {}
};

class GradeCard {
private:
    std::string departmentName;
    std::string studentName;
    int rollNumber;
    int semester;
    std::vector<std::pair<Subject, int>> subjectMarks;  // pair of subject and marks
    float CGPA;

    void calculateCGPA() {
        float totalMarks = 0.0;
        int totalSubjects = subjectMarks.size();

        for (const auto& subjectMark : subjectMarks) {
            totalMarks += subjectMark.second;
        }

        CGPA = totalMarks / (totalSubjects * 10.0);
    }

public:
    GradeCard(const std::string& deptName, const std::string& studentName, int rollNum, int sem)
        : departmentName(deptName), studentName(studentName), rollNumber(rollNum), semester(sem) {
        std::vector<std::string> subjectNames = {"English", "Math", "Physics", "Chemistry", "Biology"};
        for (const auto& subjectName : subjectNames) {
            Subject subject(static_cast<int>(subjectMarks.size()) + 1, subjectName);
            int marks = rand() % 101;  // Generate a random number between 0 and 100

            subjectMarks.push_back(std::make_pair(subject, marks));
        }

        calculateCGPA();
    }

    void show() const {
        std::cout << "Department Name: " << departmentName << "\n";
        std::cout << "Student Name: " << studentName << "\n";
        std::cout << "Roll Number: " << rollNumber << "\n";
        std::cout << "Semester: " << semester << "\n";
        std::cout << "Subject-wise Marks:\n";
        std::cout << "SubjectID  SubjectName  Marks\n";
        std::cout << "--------------------------------\n";

        for (const auto& [subject, marks] : subjectMarks) {
            std::cout << subject.Id << "\t   " << subject.name << "\t   " << marks << "\n";
        }

        std::cout << "\nCGPA: " << CGPA << "\n";
    }

    float getCGPA() const {
        return CGPA;
    }
    std::string getDept()const{
      return departmentName;
    }
};

int main() {
    std::vector<GradeCard> gradeCards;
    std::srand((time(NULL))); 
    for (int i = 1; i <= 60; ++i) {
        std::string departmentName = "Department" + std::to_string(i % 2 + 1);
        std::string studentName = "Student" + std::to_string(i);
        int rollNumber = 1000 + i;

        gradeCards.emplace_back(departmentName, studentName, rollNumber, 3);
        //std::cout<<gradeCards[i-1].getCGPA()<<"\n";
    }
    
    auto maxGradeCard1 = gradeCards[0];
    auto maxGradeCard2 = gradeCards[1];
    for(auto curr : gradeCards){
      if(maxGradeCard1.getDept()==curr.getDept()){
        maxGradeCard1 = maxGradeCard1.getCGPA()<=curr.getCGPA()?curr:maxGradeCard1;}
      else{
        maxGradeCard2 =  maxGradeCard2.getCGPA()<=curr.getCGPA()?curr:maxGradeCard2;
      }
    }
        std::cout << "Student with the highest CGPA in "<<maxGradeCard1.getDept()<<":\n";
        maxGradeCard1.show();
        std::cout << "Student with the highest CGPA in "<<maxGradeCard2.getDept()<<":\n";
        maxGradeCard2.show();
}

