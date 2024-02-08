#include <iostream>
#include <vector>

using namespace std;

class fruit{

    private:

    string variety;
    int seeds;
    string color;

    public:

    void setVariety(string var);
    void setSeeds(int seedCount);
    void setColor(string Color);
    string getVariety();
    int getSeedCount();
    string getColor();

    friend ostream& operator<<(ostream& Cout, fruit& theFruit);
    friend ostream& operator<<(ostream& Cout, fruit* theFruit);

    fruit(string var, int s, string clr) : variety(var), seeds(s), color(clr){}

};

class basket{

    private:

    vector<fruit> fruits;
    int findIndex(fruit& theFruit);

    public:

    friend ostream& operator<<(ostream& Cout, basket& fruitBasket);
    void operator+=(fruit& theFruit);
    void operator-=(fruit& theFruit);

};

int main(){

    fruit* frt = new fruit("Coconut", 1, "Brown");
    fruit frt1("Apple", 8, "Red");
    fruit frt2("Orange", 16, "orange");
    fruit frt3("Banana", 20, "Yellow");
    basket fruitBasket;

    cout << frt << '\n' << frt1 << '\n' << frt2 << '\n' << frt3 << "\n-------------------------------------\n";
    fruitBasket += frt1;
    fruitBasket += frt2;
    fruitBasket += frt3;

    cout << fruitBasket << "\n---------------------------------------\n";

    fruitBasket -= frt2;

    cout << fruitBasket;

    delete frt;

    return 0;

}

void fruit::setVariety(string var){
    variety = var;
}

void fruit::setSeeds(int seedCount){
    seeds = seedCount;
}

void fruit::setColor(string Color){
    color = Color;
}

string fruit::getVariety(){
    return variety;
}

int fruit::getSeedCount(){
    return seeds;
}

string fruit::getColor(){
    return color;
}

ostream& operator<<(ostream& Cout, fruit& theFruit){
    Cout << "Variety: " << theFruit.getVariety() << endl;
    Cout << "Number of seeds: " << theFruit.getSeedCount() << endl;
    Cout << "Color: " << theFruit.getColor() << endl;

    return Cout;

}

ostream& operator<<(ostream& Cout, fruit* theFruit){
    Cout << "Variety: " << theFruit->getVariety() << endl;
    Cout << "Number of seeds: " << theFruit->getSeedCount() << endl;
    Cout << "Color: " << theFruit->getColor() << endl;

    return Cout;

}

void basket::operator+=(fruit& theFruit){
    fruits.push_back(theFruit);
}

void basket::operator-=(fruit& theFruit){
    int index = findIndex(theFruit);
    if(index == -1){
        cerr << "No such fruit" << endl;
        return;
    }
    fruits.erase(fruits.begin() + index);
}

int basket::findIndex(fruit& theFruit){
    for(int i = 0; i < fruits.size(); i++){
        if(fruits[i].getColor() != theFruit.getColor()){
            continue;
        }
        if(fruits[i].getSeedCount() != theFruit.getSeedCount()){
            continue;
        }
        if(fruits[i].getVariety() != theFruit.getVariety()){
            continue;
        }
        return i;
    }
    return -1;
}

ostream& operator<<(ostream& Cout, basket& fruitBasket){
    for(int i = 0; i < fruitBasket.fruits.size(); i++){
        Cout << fruitBasket.fruits[i] << endl;
    }
    return Cout;
}