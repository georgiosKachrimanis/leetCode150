#include <iostream>

using namespace std;

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
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        // exception if root has no children.
        if (root == nullptr)
        {
            return false;
        }

        // if root is a leaf then we need to check the value and compare it to the target sum!
        // There is one of the solutions that only check for this condition to be true. 
        // But this is only if we are trying to find out if one of the paths to a leaf(final node) is a solution
        
        if (root->left == nullptr && root->right==nullptr)
        {
            return targetSum == root->val;
        }

        int remainingSum = targetSum - root->val;
        bool hasLeftPathSum = hasPathSum(root->left, remainingSum);
        bool hasRightPathSum = hasPathSum(root->right, remainingSum);


        return hasLeftPathSum || hasRightPathSum;
    }
};