/**
 * Definition for a binary tree node.
 * 
 */

#include <utility>
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
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return res;
    }

int res = 0;
private:
    pair<int, int> postOrder(TreeNode* root) {
        if (!root) {
            return {0, 0};
        }

        auto lhs = postOrder(root->left);
        auto rhs = postOrder(root->right);
        auto total = lhs.first + rhs.first + root->val;
        auto count = lhs.second + rhs.second + 1;
        auto average = total / count;
        if (average == root->val) {
            res++;
        }

        return {total, count};
    }
};
