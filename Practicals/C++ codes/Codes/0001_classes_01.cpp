#include <iostream>

using namespace std;

class counter{

    private:

    int amount;

    public:

    void set(int number);
    int get();
    void increment();

};

int main(){

    counter* ok;
    ok = new counter;
    ok->set(10);
    ok->increment();
    int notOk = ok->get();
    cout << notOk << "\n\n";
    delete ok;

    counter okay;
    okay.set(20);
    okay.increment();
    int notOkay = okay.get();
    cout << notOkay << "\n\n";

    return 0;

}

void counter::set(int number){
    amount = number;
}

int counter::get(){
    return amount;
}

void counter::increment(){
    amount++;
}

/*
The choice between using a pointer to an object of a class or an object of a class depends on the specific
requirements and design of your program. Both approaches have their advantages and are suitable for different
scenarios:

Object of a Class:

Simplicity: Using an object directly is often simpler and easier to understand, especially for small,
short-lived objects that don't need dynamic memory management.
Automatic Memory Management: Objects created on the stack have automatic memory management.
They are automatically destroyed when they go out of scope, reducing the risk of memory leaks.

Pointer to an Object of a Class:

Dynamic Memory: Using a pointer allows you to allocate objects on the heap, which can be useful
for objects that have a longer lifetime or need to be shared among multiple parts of your program.
Control: Pointers provide more control over the object's lifetime and can be used to create objects
with dynamic storage duration.
Polymorphism: Pointers to base class objects can be used for polymorphism and to work with derived
class objects through base class pointers.

In summary, the choice depends on your program's requirements. Use an object directly when you need
simplicity and automatic memory management for short-lived objects. Use a pointer to an object when you
need dynamic memory allocation, more control over object lifetime, or polymorphism. Keep in mind that with
great power (pointers) comes greater responsibility (memory management), so be cautious when using pointers
to avoid memory leaks and other issues. Additionally, consider using smart pointers
(e.g., std::shared_ptr or std::unique_ptr) to manage the memory automatically and safely when appropriate.
*/