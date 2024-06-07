#include <iostream>
#include <string>
// substr: Removes x number of indices from left and returns the rest
// erase: Keeps x number of indices from left and deletes the rest
class Solution {
public:
    static int myAtoi(std::string input)
    {
        int len = input.length();
        bool isPositive = true;
        for(int i = 0; i < len; i++)
        {
            if(input[i] == '+' || input[i] == '-' || (input[i] >= '0' && input[i] <= '9'))
            {
                if(input[i] == '+' || input[i] == '-')
                {
                    if(input[i] == '-')
                    {
                        isPositive = false;
                    }
                    i++;
                }
                input = input.substr(i);
                len = input.length();
                break;
            }
            else if(input[i] != ' ')
            {
                return 0;
            }
        }
        for(int i = 0; i < len; i++)
        {
            if(input[i] < '0' || input[i] > '9')
            {
                input.erase(i);
                len = i;
                break;
            }
        }
        long long int num = 0;
        for(int i = 0; i < len; i++)
        {
            num *= 10;
            num += input[i] - '0';
            if(num > std::numeric_limits<int>::max())
            {
                return isPositive ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
            }
        }
        return isPositive ? num : - num;
    }
};

int main()
{
    std::cout << Solution::myAtoi("words and 987") << std::endl;
    return 0;
}