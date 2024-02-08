#include <iostream>

using namespace std;

class book{
    
    private:

    string bookName;
    int pages;

    public:

    book(string b, int p) : bookName(b), pages(p){}

    friend class librarian;
    friend void printBookInfo(book bk);

};

class librarian{
    public:
    
    void printInfo(book bk);

};

int main(){

    book book1("Bringing Tony Home", 250);
    book book2("Prince And the Pauper", 350);
    librarian pagaya;

    pagaya.printInfo(book1);
    printBookInfo(book2);

    return 0;

}

void librarian::printInfo(book bk){

    cout << "BookName: " << bk.bookName << endl;
    cout << "Pages: " << bk.pages << endl;

}

void printBookInfo(book bk){

    cout << "BookName: " << bk.bookName << endl;
    cout << "Pages: " << bk.pages << endl;

}

/*
1.  Use friendship concept sparingly and limitedly as having too much friendships can break
    the idea of data encapsulation

2.  Friendship is not mutual; meaning if class1 has a friend class called class2, class2 can
    access class1's private properties, however class1 cannot access class2's private properties.

3.  Friendship is not inherited; meaning if a base class has a friend function, the function
    will not be a friend function of the base class' derived classes by default.

4.  Friend functions are mostly used when overloading operators.
*/