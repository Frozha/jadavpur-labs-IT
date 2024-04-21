#include<iostream>
#include<cstring>
using namespace std;

class person{
    protected:
        string name;
        int age;
        float cm_height;
    public:
        person(string &inpname, int &age, float &cm_height){
            this->age = age;
            name= inpname;
            this->cm_height = cm_height; 
        }
        person(person &c){
            this->age = c.age;
            this->name= c.name;
            this->cm_height = c.cm_height;
        }
        void print_details() const{
            cout<<"\nName : "<<name;
            cout<<"\nAge : "<<age;
            cout<<"\nHeight : "<<cm_height<<" cm";
        }
        void change_name(string &new_name){
            this->name=new_name;
        }
        void change_age(int new_age){
            this->age = new_age;
        }
        void change_height(float new_height){
            this->cm_height = new_height;
        }
};

class student:public person{
    private:

        static int current_roll;
        static int current_year;
        const int roll_number;
	    const int year_of_admission;
        string phone_number;

    public:
        student(string &name, int &age, float &cm_height, string &phone_number):person(name, age, cm_height), roll_number(current_roll++), year_of_admission(current_year){
            this->phone_number=phone_number;
        }
        student(person &p, string &phone_number):person(p),roll_number(current_roll++), year_of_admission(current_year){
            this->phone_number= phone_number;
        }
        void print_details() const {
            cout<<"\nName : "<<name;
            cout<<"\nAge : "<<age;
            cout<<"\nHeight : "<<cm_height<<" cm";
            cout<<"\nYear of admission : "<<year_of_admission;
            cout<<"\nRoll Number : "<<roll_number;
            cout<<"\nPhone number : "<<phone_number;
        }
        void change_phone_number(string &new_phone_number){
            this->phone_number = phone_number;
        }
};
int student::current_roll = 12340;
int student::current_year = 2023;
int main(){
    string name;
    cout<<"Enter Full Name : ";
    getline(cin, name);
    int age;
    cout<<"Enter age : ";
    cin>>age;

    float cm_height;
    cout<<"Enter height (in centimeter) : ";
    cin>>cm_height;

    person p1(name,age,cm_height);

    p1.print_details();
    
    string phone_number;
    cout<<"\n\nEnter Phone Number : ";
    cin.clear();
    cin.ignore(100,'\n');
    getline(cin, phone_number);
    student s1(p1,phone_number);

    s1.print_details();
}
