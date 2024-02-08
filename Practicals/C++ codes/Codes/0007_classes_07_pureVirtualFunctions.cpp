#include <iostream>

using namespace std;

class instrument{

    public:

    virtual void makeSound() = 0;

};

class accordion : public instrument{

    public:

    void makeSound();

};

class piano : public instrument{

    public:

    void makeSound();

};

int main(){

    instrument* instruments[2] = {new accordion, new piano};

    for(int i = 0; i < 2; i++){
        instruments[i]->makeSound();
    }

    return 0;

}

void accordion::makeSound(){
    cout << "Accordion playing..." << endl;
}

void piano::makeSound(){
    cout << "Piano playing..." << endl;
}