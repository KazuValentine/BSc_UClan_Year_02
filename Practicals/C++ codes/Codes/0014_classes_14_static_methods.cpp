#include <iostream>

class Game {
    int mA = 0;
    int mB = 0;
public:
    static int Start() {
        Game* pGame = new Game(3, 5);
        pGame->Print();
        delete pGame;
        return 0;
    }
    void Print()
    {
        std::cout << "a: " << mA << '\n';
        std::cout << "b: " << mB << '\n';
    }
    Game(int a, int b)
    {
        mA = a;
        mB = b;
    }
};

int main() {
    return Game::Start();
}
