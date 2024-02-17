#include <iostream>
#include <vector>

class test
{
private:
    std::vector<std::string> mNames;
public:
    void print();
    template<typename... names>
    test(names&...name);
    ~test();
};
template<typename... names>
test::test(names&...name)
{
    for (std::string& name : names) {
        mNames.push_back(name);
    }
    
}

test::~test()
{
}

void test::print()
{
    for (const std::string& name : mNames)
    {
        std::cout << name << '\t';
    }
    
}

int main() {
    
    test* pTest = new test("John", "Amara", "Sirimath");
    pTest->print();

    return 0;
}
