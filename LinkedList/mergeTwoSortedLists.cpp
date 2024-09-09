#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        // create a new node to be used for merging the given lists.
        ListNode* mergedListHead = new ListNode(-1);
        ListNode* currentNode = mergedListHead;

        // traverse the lists until one of them is empty
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                currentNode->next = list1;
                list1 = list1->next;
            }
            else
            {
                currentNode->next = list2;
                list2 = list2->next;
            }
            currentNode = currentNode->next; // move to the next node and check again the lists
        }

        // Now append the remaining nodes from either list1 or list2
        if(list1!= nullptr)
        {
            currentNode->next = list1;
        }
        else{
             currentNode->next = list2;
        }

        // The merged list begins after the mergedListHead.
        return mergedListHead->next;
    }
};

/* This is the fastest solution on Leetcode. 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *l1=list1;
        ListNode *l2=list2;
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        while(l1!=NULL && l2!=NULL)
        {
            if(l1->val<l2->val)
            {
                temp->next=l1;
                temp=l1;
                l1=l1->next;

            }
            else
            {
                temp->next=l2;
                temp=l2;
                l2=l2->next;
            }
        }
        if(l1)
        {
            temp->next=l1;
        }
        else
        {
            temp->next=l2;
        }
        return dummy->next;


        
    }
};
*/