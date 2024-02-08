#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Incorrect usage, will result in a compilation error
    // myVector.insert(2, 10);

    // Correct usage
    myVector.insert(myVector.begin() + 2, 10);

    // Displaying the modified vector
    for (const auto& element : myVector) {
        std::cout << element << " ";
    }

    return 0;
}
