#include <iostream>
#include <string>

class Solution
{

    std::string EraseTo(std::string& string, const int& kTo)
    {
        int len = string.length();
        if(kTo >= len)
            return string;
        std::string temp = "";
        for(int i = kTo + 1; i < len; i++)
        {
            temp += string[i];
        }
        return temp;
    }

public:

    bool isMatch(std::string s, std::string p)
    {
        if(s == p)
            return true;

        int i = 0;
        int j = 0;

        while(true)
        {
            if(s[i] == p[j])
            {
                i++;
                j++;
                continue;
            }
            if(p[j] == '.')
            {
                i++;
                j++;
            }
        }
    }
};

int main()
{
    Solution* pSol = new Solution();
    std::cout << (pSol->isMatch("aab", "c*a*b") ? "wada wada such a success" : "wada naha such a failure");
    return 0;
}

    // bool isMatch(std::string s, std::string p)
    // {
    //     bool anySingle = false;
    //     bool zeroOrMore = false;
    //     if(p.length() > 0)
    //     {
    //         if(p[p.length() - 1] == '*')
    //         {
    //             zeroOrMore = true;
    //             Erase(p, p.length() - 2);
    //         }
    //     }
    //     if(p.length() > 0)
    //     {
    //         if(p[p.length() - 1] == '.')
    //         {
    //             anySingle = true;
    //             Erase(p, p.length() - 2);
    //         }
    //     }
    //     if(p.length() > 0)
    //     {
    //         if(p[p.length() - 1] == '*')
    //         {
    //             zeroOrMore = true;
    //             Erase(p, p.length() - 2);
    //         }
    //     }
    //     if(anySingle && zeroOrMore)
    //     {
    //         return true;
    //     }
    //     if(p.length() == 1 && anySingle || zeroOrMore)
    //     {
    //         return std::string::npos != s.find(p);
    //     }
    //     return s == p;
    // }

