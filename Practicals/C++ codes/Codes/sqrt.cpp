#include <iostream>
#include <vector>

class Solution
{
public:
    static int mySqrt(long long int num)
    {
        if(num < 0)
        {
            return 0;
        }
        std::vector<int> periods;
        while(num > 0)
        {
            periods.push_back(num % 100);
            num /= 100;
        }
        int divisor = 0;
        int remainder = 0;
        while(!periods.empty())
        {
            int period = periods[periods.size() - 1];
            remainder += period;
            int sqrtApprox = divisor * 10;
            int quotient = 0;
            while(true)
            {
                quotient = (sqrtApprox % 10);
                int sqr = sqrtApprox * quotient;
                if(remainder == sqr)
                {
                    break;
                }
                else if(remainder < sqr)
                {
                    sqrtApprox--;
                    break;
                }
                if(quotient == 9)
                {
                    break;
                }
                sqrtApprox++;
            }
            quotient = (sqrtApprox % 10);
            divisor = 2 * sqrtApprox - divisor * 10;
            remainder -= sqrtApprox * quotient;
            periods.pop_back();
            if(periods.size() >= 1)
            {
                remainder *= 100;
            }
            else
            {
                break;
            }
        }
        return divisor / 2;
    }
};

int main()
{
    for(long long int i = 0; i < 5000; i ++)
    {
        if(i != Solution::mySqrt(i * i + 2 * i))
        {
            break;
        }
        std::cout << i << " ";
    }
    return 0;
}