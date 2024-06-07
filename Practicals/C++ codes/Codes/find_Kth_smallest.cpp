/*
Kth Smallest Amount With Single Denomination Combination

You are given an integer array coins representing coins of different denominations
and an integer k.
You have an infinite number of coins of each denomination.
However, you are not allowed to combine coins of different denominations.

Return the kth smallest amount that can be made using these coins.

Example 1:

Input: coins = [3,6,9], k = 3

Output: 9

Explanation: The given coins can make the following amounts:

Coin 3 produces multiples of 3: 3, 6, 9, 12, 15, etc.
Coin 6 produces multiples of 6: 6, 12, 18, 24, etc.
Coin 9 produces multiples of 9: 9, 18, 27, 36, etc.

All of the coins combined produce: 3, 6, 9, 12, 15, etc.

Example 2:

Input: coins = [5,2], k = 7

Output: 12

Explanation: The given coins can make the following amounts:

Coin 5 produces multiples of 5: 5, 10, 15, 20, etc.
Coin 2 produces multiples of 2: 2, 4, 6, 8, 10, 12, etc.

All of the coins combined produce: 2, 4, 5, 6, 8, 10, 12, 14, 15, etc.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

static auto fastio = []()
{
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution
{
private:
    bool Contains(std::vector<int>& list, const int& kNum)
    {
        int start = 0;
        int end = list.size();
        while(start != end)
        {
            int mid = (start + end) / 2;
            int val = list[mid];
            if(val == kNum)
            {
                return true;
            }
            if(val > kNum)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        return false;
    }
    void OrganizeVec(std::vector<int>& list)
    {
        std::sort(list.begin(), list.end());
        for(int i = 0; i < list.size() - 1; i++)
        {
            int divisor = list[i];
            for(int j = i + 1; j < list.size(); j++)
            {
                if(list[j] % divisor == 0)
                {
                    list.erase(list.begin() + j--);
                }
            }
        }
    }
public:
    long long findKthSmallest(std::vector<int>& coins, int index)
    {
        OrganizeVec(coins);
        int len = coins.size();
        std::vector<int> indices;
        for(int i = 0; i < len; i++)
        {
            indices.push_back(0);
        }
        std::vector<int> vals;
        for(int i = 0; i < index; i++)
        {
            int j = 0;
            int smallest = coins[j] * (indices[j] + 1);
            for(int k = j; k < len; k++)
            {
                int currVal = coins[k] * (indices[k] + 1);
                if(currVal < smallest)
                {
                    smallest = currVal;
                    j = k;
                }
            }
            if(!Contains(vals, smallest))
            {
                vals.push_back(smallest);
            }
            else
            {
                i--;
            }
            indices[j]++;
        }
        return vals[vals.size() - 1];
    }
};

int main()
{
    Solution* pSol = new Solution();
    std::vector<int> list = {6, 5};
    std::cout << pSol->findKthSmallest(list, 14350) << std::endl;
    delete pSol;
    return 0;
}