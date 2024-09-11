#include <iostream>
#include <string>

using namespace std;

// Definition for singly-linked list.
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carryOn = 0;
        ListNode *summedNumbers = new ListNode();
        ListNode *currentNode = summedNumbers;

        while (l1 != nullptr || l2 != nullptr || carryOn != 0)
        {
            int sum = carryOn; // Add the value of carry on to the new Sum

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carryOn = sum / 10;

            ListNode *tempNode = new ListNode(sum % 10);
            currentNode->next = tempNode;
            currentNode = tempNode;
        }
        return summedNumbers->next;
    }
};