/*
This is a really hard problem. Again nodes and lists are not the easiest way to go.
Just try to visualize what is happening and use pen and paper with some examples!
*/


#include <iostream>

using namespace std;

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode *prev = &dummy;

        for (int i = 1; i < left; i++)
        {
            prev = prev->next;
        }

        ListNode *leftNode = prev->next;
        ListNode *nextNode;

        for (int i = 0; i < right - left; i++)
        {
            nextNode = leftNode->next;
            leftNode->next = nextNode->next;
            nextNode->next = prev->next;
            prev->next = nextNode;
        }

        return dummy.next;
        
    }
};