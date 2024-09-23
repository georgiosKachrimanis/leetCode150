/*
Just to be clear the ListNodes are not my favorite and also if you find them difficult you are not alone!
The only thing to remember that will help you is if you think the ListNodes as a string of beads that are all connected with each other through the string.
If you need to manipulate the data or order, you must cut the string at one place and then glue it to another.
Not easy to imagine or do but with a lot of effort and work is a really good and powerful tool to know how to use.
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *tail = head;
        int numOfNodes = 1;

        // list empty, has one node or k=0
        if(!head || !head->next || k==0)
        {
            return head;
        }

        // First I will find the total number of nodes and the last node!
        while (tail->next)
        {
            tail = tail->next;
            numOfNodes++;
        }

        // Now I create a circular list
        tail->next = head;

        // Now will check and adjust k in case it is larger than the total number of nodes(we do not need to run around our own tails ;) )
        // Will also find out which one is the new tail of the circular list

        k = k % numOfNodes;
        int stepsToNewHead = numOfNodes - k;

        ListNode *newTail = head; 

        // now traverse the list of nodes until you find the node that points to the new Head
        for (int i = 1; i < stepsToNewHead; i++)
        {
            newTail = newTail->next;
        }

        // create a new node that is the new head
        ListNode *newHead = newTail->next;

        // cut the tail from the new head!
        newTail->next = nullptr;

        return newHead;
    }
};