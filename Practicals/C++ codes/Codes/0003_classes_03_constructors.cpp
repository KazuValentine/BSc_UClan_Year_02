#include <iostream>

using namespace std;

class people{

    private:

    string name;
    int age;

    public:

    void setName(string n);
    void setAge(int a);
    string getName();
    int getAge();
    void printInfo();

    people(string NAME, int AGE){
        name = NAME;
        age = AGE;
    }

};

int main() {

    people* person1 = new people("Kasun Dodanwala", 20);
    person1->printInfo();
    cout << endl;
    people person2("Ube Tatta", 69);
    person2.printInfo();
    return 0;

}

void people::setName(string n){
    name = n;
}

void people::setAge(int a){
    age = a;
}

string people::getName(){
    return name;
}

int people::getAge(){
    return age;
}

void people::printInfo(){
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
}
