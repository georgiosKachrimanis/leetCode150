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
    int countNodes(TreeNode* root) {
        
        if (root == nullptr){
            return 0;
        }

        //I create a recursion checking left and right and returning the total number of nodes.
        int leftNodes = countNodes(root->left);
        int rightNodes = countNodes(root->right);

        return 1 + leftNodes + rightNodes;
    }
};

// This is the code of the fastest implementation what it does in sort is first to check if the tree is perfect.
// (both left and right children are of the same height) if this is true then uses this formula to return the total number of nodes
// Height^2 - 1
// If not then does the same as I did. The rest are functions to disable some basic io of C++

/*
class Solution {
public:
    static inline auto _ = [] {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::ofstream out("user.out", std::ios::out | std::ios::binary);
        out.rdbuf()->pubsetbuf(nullptr, 256);
        std::string s;
        std::noskipws(std::cin);
        while (std::getline(std::cin, s)) {
            int count = 0;
            bool inNum = false;
            for (char c : s) {
                if (std::isdigit(c) != 0) {
                    if (!inNum) {
                        ++count;
                        inNum = true;
                    }
                } else {
                    inNum = false;
                }
            }
            out << count << '\n';
        }
        std::skipws(std::cin);
        out.flush();
        exit(0);
        return 0;
    }();
    int getLeftHeight(TreeNode* root){
        int leftHeight = 0;
        TreeNode* temp = root;
        while(temp){
            leftHeight++;
            temp = temp -> left;
        }
        return leftHeight;
    }
    int getRightHeight(TreeNode* root){
        TreeNode* temp = root;
        int rightHeight = 0;
        while(temp){
            rightHeight++;
            temp = temp -> right;
        }
        return rightHeight;
    }
    int countNodes(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(!root){
            return 0;
        }
        int leftNodes = getLeftHeight(root);
        int rightNodes = getRightHeight(root);
        if(leftNodes == rightNodes){
            return pow(2, leftNodes) - 1;
        }
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};
*/