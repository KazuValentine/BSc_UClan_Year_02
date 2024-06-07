/*
You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself/
*/


#include <iostream>
 //Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    static ListNode* addTwoNumbers(ListNode* pListOne, ListNode* pListTwo)
    {
        int carry = 0;
        ListNode* pCurrent = new ListNode();
        ListNode* pHead = pCurrent;
        while(pListOne || pListTwo || carry)
        {
            int sum = (pListOne ? pListOne->val : 0) + (pListTwo ? pListTwo->val : 0) + carry;
            carry = sum / 10;
            sum %= 10;
            if(pListOne)
            {
                pListOne = pListOne->next;
            }
            if(pListTwo)
            {
                pListTwo = pListTwo->next;
            }
            pCurrent->next = new ListNode(sum);
            pCurrent = pCurrent->next;
        }
        ListNode* pTemp = pHead;
        pHead = pHead->next;
        delete pTemp;
        return pHead;
    }
};

int main()
{
    ListNode l7(9);
    ListNode l6(9, &l7);
    ListNode l5(9, &l6);
    ListNode l4(9, &l5);
    ListNode l3(9, &l4);
    ListNode l2(9, &l3);
    ListNode l1(9, &l2);

    ListNode l14(9);
    ListNode l13(9, &l14);
    ListNode l12(9, &l13);
    ListNode l11(9, &l12);

    ListNode* ptr = Solution::addTwoNumbers(&l1,&l11);
    while(ptr)
    {
        std::cout << ptr->val << " ";
        ptr = ptr->next;
    }
    return 0;
}