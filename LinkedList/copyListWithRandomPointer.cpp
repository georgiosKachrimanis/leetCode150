# include <iostream>


class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Create a copy of each node and link them side by side in the original list
        Node* curr = head;
        while (curr) {
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }

        // Step 2: Assign random pointers for the new nodes
        curr = head;
        while (curr) {
            if (curr->random) {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        // Step 3: Separate the original and copied nodes to form the copied list
        curr = head;
        Node* copiedHead = head->next;
        Node* copy = copiedHead;
        while (curr) {
            curr->next = curr->next->next;
            if (copy->next) {
                copy->next = copy->next->next;
            }
            curr = curr->next;
            copy = copy->next;
        }

        return copiedHead;
    }
};