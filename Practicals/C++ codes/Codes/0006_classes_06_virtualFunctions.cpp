#include <iostream>

using namespace std;

class instrument{

    public:

    virtual void makeSound();

};

class accordion : public instrument{

    public:

    void makeSound();

};

int main(){

    instrument* inst1 = new accordion;
    inst1->makeSound();

    return 0;

}

void instrument::makeSound(){
    cout << "Instrument playing..." << endl;
}

void accordion::makeSound(){
    cout << "Accordion playing..." << endl;
}