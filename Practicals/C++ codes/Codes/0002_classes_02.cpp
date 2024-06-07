#include <iostream>

using namespace std;

class people{

    private:

    string DOB;
    string bloodType;
    int age;
    string name;

    public:

    void setDOB(string dateOfBirth);
    void setBloodType(string typeOfBlood);
    void setAge(int ageAsInt);
    void setName(string theName);

    string getDOB();
    string getBloodType();
    int getAge();
    string getName();

};


int main(){

    people* peopleList[3];

    for(int i = 0; i < 3; i++){
        peopleList[i] = new people;
    }

    peopleList[0]->setAge(15);
    peopleList[0]->setBloodType("B+");
    peopleList[0]->setDOB("20/04/1998");
    peopleList[0]->setName("Pagaya");

    peopleList[1]->setAge(18);
    peopleList[1]->setBloodType("A-");
    peopleList[1]->setDOB("16/02/1555");
    peopleList[1]->setName("Http");

    peopleList[2]->setAge(19);
    peopleList[2]->setBloodType("AB+");
    peopleList[2]->setDOB("19/12/2000");
    peopleList[2]->setName("Ube Tatta");

    for(int i = 0; i < 3; i++){
        cout << "Name: " << peopleList[i]->getName() << endl;
        cout << "DOB: " << peopleList[i]->getDOB() << endl;
        cout << "Age: " << peopleList[i]->getAge() << endl;
        cout << "Blood Type: " << peopleList[i]->getBloodType() << endl << endl;
    }

    return 0;

}

void people::setDOB(string dateOfBirth){
    DOB = dateOfBirth;
}
void people::setBloodType(string typeOfBlood){
    bloodType = typeOfBlood;
}
void people::setAge(int ageAsInt){
    age = ageAsInt;
}
void people::setName(string theName){
    name = theName;
}

string people::getDOB(){
    return DOB;
}

string people::getBloodType(){
    return bloodType;
}

int people::getAge(){
    return age;
}

string people::getName(){
    return name;
}
