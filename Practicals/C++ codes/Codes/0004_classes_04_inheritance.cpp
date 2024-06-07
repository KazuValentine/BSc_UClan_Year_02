#include <iostream>

using namespace std;

class people{

    private:

    string name;
    int age;

    protected: //These can be accessed in derived classes,
    //however they can't be accessed outside any of the classes
    string hobby;

    public:

    void setName(string Name);
    void setAge(int Age);
    string getName();
    int getAge();

    people(string Name, int Age) : name(Name), age(Age){}

};

class student : public people{

    private:

    string course;
    int studentID;

    public:

    void setCourse(string Course);
    void setStudentID(int SID);
    string getCourse();
    int getStudentID();

    student(string Name, int Age, string Course, int SID) : people(Name, Age), course(Course), studentID(SID){}

};


int main(){

    people* person1 = new people("Pagaya", 66);
    student* schooler = new student("Kasun Dodanwala", 20, "Software Engineering", 2114232);

    cout << "Person1:" << endl;
    cout << "Name: " << person1->getName() << endl;
    cout << "Age: " << person1->getAge() << endl << endl;
    cout << "Schooler:" << endl;
    cout << "Name: " << schooler->getName() << endl;
    cout << "Age: " << schooler->getAge() << endl;
    cout << "Course: " << schooler->getCourse() << endl;
    cout << "Student ID: " << schooler->getStudentID() << endl; 

    return 0;

}

void people::setName(string Name){
    name = Name;
}

void people::setAge(int Age){
    age = Age;
}

string people::getName(){
    return name;
}

int people::getAge(){
    return age;
}

void student::setCourse(string Course){
    course = Course;
}

void student::setStudentID(int SID){
    studentID = SID;
}

string student::getCourse(){
    return course;
}

int student::getStudentID(){
    return studentID;
}
