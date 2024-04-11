#include <iostream>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* pList1, ListNode* pList2)
    {
        ListNode* pCombined = nullptr;
        if(pList1 && pList2)
        {
            if(pList1->val < pList2->val)
            {
                pCombined = new ListNode(pList1->val);
                pList1 = pList1->next;
            }
            else
            {
                pCombined = new ListNode(pList2->val);
                pList2 = pList2->next;
            }
        }
        ListNode* pStart = pCombined;
        while(pList1 && pList2)
        {
            if(pList1->val < pList2->val)
            {
                pCombined->next = new ListNode(pList1->val);
                pList1 = pList1->next;
            }
            else
            {
                pCombined->next = new ListNode(pList2->val);
                pList2 = pList2->next;
            }
            pCombined = pCombined->next;
        }
        while(pList1)
        {
            if(pCombined)
            {
                pCombined->next = new ListNode(pList1->val);
                pList1 = pList1->next;
                pCombined = pCombined->next;
            }
            else
            {
                pCombined = new ListNode(pList1->val);
                pList1 = pList1->next;
                pStart = pCombined;
            }
        }
        while(pList2)
        {
            if(pCombined)
            {
                pCombined->next = new ListNode(pList2->val);
                pList2 = pList2->next;
                pCombined = pCombined->next;
            }
            else
            {
                pCombined = new ListNode(pList2->val);
                pList2 = pList2->next;
                pStart = pCombined;
            }
        }
        return pStart;
    }
};

int main()
{
    Solution* pSol = new Solution();
    ListNode n10(25);
    ListNode n9(18, &n10);
    ListNode n8(10, &n9);
    ListNode n7(7, &n8);

    ListNode n6(24);
    ListNode n5(18, &n6);
    ListNode n4(9, &n5);
    ListNode n3(7, &n4);
    ListNode n2(5, &n3);
    ListNode n1(2, &n2);

    ListNode test(0);

    ListNode* pList = pSol->mergeTwoLists(nullptr, &test);
    while(pList)
    {
        std::cout << pList->val << ", ";
        pList = pList->next;
    }
    return 0;
}