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
    vector<double> averageOfLevels(TreeNode *root)
    {
        queue<TreeNode *> nodesQueue;
        vector<double> answersVector;

        if (root == NULL)
        {
            return answersVector;
        }

        int levelCounter = 0; // I start from one as this is the root level.
        nodesQueue.push(root);

        while (!nodesQueue.empty())
        {
            levelCounter++; // If we are in the loop means we are in a new level of the tree.
            int totalNodes = nodesQueue.size();
            double sumOfNodeValues = 0;

            for (int i = 0; i < totalNodes; i++)
            {
                TreeNode *currentNode = nodesQueue.front();
                nodesQueue.pop();
                sumOfNodeValues += currentNode->val;

                if (i == totalNodes - 1)
                {
                    double avg = sumOfNodeValues / totalNodes;
                    answersVector.push_back(avg);
                }
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

        return answersVector;
    }
};