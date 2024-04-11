#include <iostream>

static auto fastio = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
public:
    int romanToInt(std::string input)
    {
        int endIndex = input.length() - 1;
        int num = 0;
        char prevRoman = ' ';
        for(int i = endIndex; i >= 0; i--)
        {
            char currentRoman = input[i];
            if(currentRoman == 'I')
            {
                if(prevRoman == 'V' || prevRoman == 'X')
                {
                    num -= 1;
                }
                else
                {
                    num += 1;
                }
            }
            else if(currentRoman == 'V')
            {
                num += 5;
            }
            else if(currentRoman == 'X')
            {
                if(prevRoman == 'L' || prevRoman == 'C')
                {
                    num -= 10;
                }
                else
                {
                    num += 10;
                }
            }
            else if(currentRoman == 'L')
            {
                num += 50;
            }
            else if(currentRoman == 'C')
            {
                if(prevRoman == 'D' || prevRoman == 'M')
                {
                    num -= 100;
                }
                else
                {
                    num += 100;
                }
            }
            else if(currentRoman == 'D')
            {
                num += 500;
            }
            else
            {
                num += 1000;
            }
            prevRoman = currentRoman;
        }
        return num;
    }
};

int main()
{
    std::string input = "MCMXCIV"; // 1994
    Solution* pSol = new Solution();
    std::cout << pSol->romanToInt(input);
    return 0;
}