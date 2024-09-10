#include <iostream>

using namespace std;

// * Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        // exception if any of the roots has no children (then trees are the same).
        if (p == NULL && q==NULL)
        {
            return true;
        }

        // Now I check if any of the routes are empty or if the values are different.
        if (p == NULL || q==NULL || p->val != q->val)
        {
            return false;
        }

        // Now with recursive function we check the children of each tree
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};