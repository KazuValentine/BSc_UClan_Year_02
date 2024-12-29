#include <iostream>
#include <limits>

class Solution {
public:
    static int reverse(int x)
    {
        long long int num = 0;
        while(x > 0 || x < 0)
        {
            num *= 10;
            num += x % 10;
            if(num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
            {
                return 0;
            }
            x /= 10;
        }
        return num;
    }
};

int main()
{
    std::cout << Solution::reverse(123456) << std::endl;
    return 0;
}