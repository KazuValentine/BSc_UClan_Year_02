#include <iostream>
#include <vector>

class Solution {
public:
    static bool isValid(std::string s)
    {
        if(s.length() % 2 != 0)
        {
            return false;
        }
        char openPara[] = {'(', '{', '['};
        char closePara[] = {')', '}', ']'};
        int paraVarients = 3;
        bool isOpenPara = false;
        int len = s.length();
        std::vector<int> openParaOrder;
        for(int i = 0; i < len; i++)
        {
            isOpenPara = false;
            char stringIndex = s[i];
            for(int j = 0; j < paraVarients; j++)
            {
                if(stringIndex == openPara[j])
                {
                    isOpenPara = true;
                    openParaOrder.push_back(j);
                    break;
                }
            }
            if(isOpenPara)
            {
                continue;
            }
            else
            {
                if(openParaOrder.empty())
                {
                    return false;
                }
            }
            if(stringIndex == closePara[openParaOrder[openParaOrder.size() - 1]])
            {
                openParaOrder.pop_back();
            }
            else
            {
                return false;
            }
        }
        if(!openParaOrder.empty())
        {
            return false;
        }
        return true;
    }
};

int main()
{
    std::string input1 = "({[]})";
    std::string input2 = "((";
    std::string input3 = "{([])";

    if(Solution::isValid(input1))
    {
        std::cout << "Input1 valid\n";
    }
    if(Solution::isValid(input2))
    {
        std::cout << "Input2 valid\n";
    }
    if(Solution::isValid(input3))
    {
        std::cout << "Input3 valid\n";
    }

    return 0;
}