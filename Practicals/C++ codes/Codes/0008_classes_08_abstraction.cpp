#include <iostream>
#include <vector>

using namespace std;

class list{

    private:

    string name;

    protected:

    vector<int> array;

    public:

    list(string n) : name(n){}

    void push(int i);
    void pop();
    int getFirst();
    int getLast();
    void printAll();

    virtual void sort() = 0;

};

class bubbleSortList : public list{

    public:

    void sort();

    bubbleSortList(string n) : list(n){}

};

class selectionSortList : public list{

    public:

    void sort();
  
    selectionSortList(string n) : list(n){}

};

int main(){

    list* listBubble = new bubbleSortList("Bubble");
    list* listSelection = new selectionSortList("Selection");

    listBubble->push(10);
    listBubble->push(9);
    listBubble->push(8);
    listBubble->push(7);
    listBubble->push(6);
    listBubble->push(5);
    listBubble->push(4);
    listBubble->push(3);
    listBubble->push(2);
    listBubble->push(7);
    listBubble->push(5);
    listBubble->push(1);

    listSelection->push(10);
    listSelection->push(9);
    listSelection->push(8);
    listSelection->push(7);
    listSelection->push(6);
    listSelection->push(5);
    listSelection->push(4);
    listSelection->push(3);
    listSelection->push(2);
    listSelection->push(7);
    listSelection->push(5);
    listSelection->push(1);

    cout << "Bubble(Before): ";
    listBubble->printAll();
    cout << endl;
    listBubble->sort();
    cout << "Bubble(After): ";
    listBubble->printAll();
    cout << endl << endl;

    cout << "Selection(Before): ";
    listSelection->printAll();
    cout << endl;
    listSelection->sort();
    cout << "Selection(After): ";
    listSelection->printAll();
    cout << endl << endl;

    return 0;

}

void list::push(int i){
    array.push_back(i);
}

void list::pop(){
    array.pop_back();
}

int list::getFirst(){
    if(!array.empty()){
        return array[0];
    }
    cout << "List empty\n";
}

int list::getLast(){
    if(!array.empty()){
        return array[array.size() - 1];
    }
    cout << "List empty\n";
}

void list::printAll(){
    for(int i = 0; i < array.size(); i++){
        cout << array[i];
        if(i != array.size() - 1){
            cout << ", ";
        }
    }
}

void bubbleSortList::sort(){
    for(int i = 0; i < array.size() - 1; i++){
        for(int j = 0; j < array.size() - 1 - i; j++){
            if(array[j] > array[j + 1]){
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void selectionSortList::sort(){
    for(int i = 0; i < array.size() - 1; i++){
        int pos = 0;
        int temp = array[pos];
        for(int j = 1; j < array.size() - i; j++){
            if(array[j] > temp){
                temp = array[j];
                pos = j;
            }
        }
        if(pos != array.size() - 1 - i){
            temp = array[array.size() - 1 - i];
            array[array.size() - 1 - i] = array[pos];
            array[pos] = temp;
        }
    }
}
