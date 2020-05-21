#pragma once
#include <iostream>

namespace addTwoNumbers
{
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto pcurr1 = l1;
        auto pcurr2 = l2;
        auto phead = new ListNode(0);
        auto presultCurr = phead;

        int factor = 0;
        while (pcurr1 != NULL || pcurr2 != NULL)
        {
            int val1 = 0;
            int val2 = 0;
            if (pcurr1 != NULL)
            {
                val1 = pcurr1->val;
                pcurr1 = pcurr1->next;
            }
            if (pcurr2 != NULL)
            {
                val2 = pcurr2->val;
                pcurr2 = pcurr2->next;
            }
            int tempAdd = val1 + val2 + factor;
            factor = tempAdd / 10;
            int val = tempAdd % 10;
            ListNode *newNode = new ListNode(val);
            presultCurr->next = newNode;
            presultCurr = newNode;
        }
        if (factor != 0)
        {
            ListNode *newNode = new ListNode(factor);
            presultCurr->next = newNode;
        }
        
        phead = phead->next;
        return reserveList(phead);
        
    }
    ListNode* reserveList(ListNode* phead)
    {
        if (phead == NULL || phead->next ==NULL)
        {
            return phead;
        }
        ListNode *prev = phead;
        ListNode *pcurr = phead->next;
        ListNode *pnext = NULL;
        while(pcurr != NULL)
        {
            pnext = pcurr->next;
            pcurr->next = prev;
            prev = pcurr;
            pcurr = pnext;
        }
        phead->next = NULL;
        return prev;
    }
};
}
