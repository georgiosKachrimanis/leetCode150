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
    int maxDepth(TreeNode* root) {
        
        // exception if root has no children.
        if (root == NULL)
        {
            return 0;
        }

        //I create create a recursion checking left and right and returning the total depth.
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Return 1(current depth) + the maximum depth of left or right.
        return 1 + max(leftDepth, rightDepth);
    }
};