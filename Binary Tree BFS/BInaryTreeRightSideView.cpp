#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> rightViewNodes;

        if (root == NULL)
        {
            return rightViewNodes;
        }

        queue<TreeNode *> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty())
        {
            int sizeOfLevel = nodesQueue.size();

            for (int i = 0; i < sizeOfLevel; i++)
            {
                TreeNode *currentNode = nodesQueue.front();
                nodesQueue.pop();

                // here is were the magic is happening
                // if this is the last node of the level means that is the rightmost
                // then we push the value of the node inside the return vector

                if (i == sizeOfLevel - 1)
                {
                    rightViewNodes.push_back(currentNode->val);
                }

                // now we check if the current Node has children left and right and we add the to the queue
                // from leftmost to -> rightmost. Remember queue is FIFO structure

                if (currentNode->left != nullptr)
                {
                    nodesQueue.push(currentNode->left);
                }

                if (currentNode->right != nullptr)
                {
                    nodesQueue.push(currentNode->right);
                }
            }
        }

        return rightViewNodes;
    }
};