#include <iostream>

class Solution
{
public:
    static std::string addBinary(std::string a, std::string b)
    {
        if(a.length() < b.length())
        {
            std::string sTemp = a;
            a = b;
            b = sTemp;
        }
        short aEndIndex = a.length() - 1;
        short bEndIndex = b.length() - 1;
        short range = bEndIndex + 1;
        for(int i = 0; i < range; i++)
        {
            const char kOne = '1';
            const char kZero = '0';
            if(b[bEndIndex - i] == kOne)
            {
                for(int j = aEndIndex - i; j >= 0; j--)
                {
                    if(a[j] == kZero)
                    {
                        a[j] = kOne;
                        break;
                    }
                    else
                    {
                        a[j] = kZero;
                        if(j == 0)
                        {
                            a.insert(0, 1, kOne);
                            aEndIndex++;
                            break;
                        }
                    }
                }
            }
        }
        return a;
    }
};

int main()
{
    std::string a = "1111";
    std::string b = "11";
    std::string answer = Solution::addBinary(a, b);
    std::cout << ("10010" == answer ? "Correct" : "Wrong") << std::endl << answer;
    return 0;
}