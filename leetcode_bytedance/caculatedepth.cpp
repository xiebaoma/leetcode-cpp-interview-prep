/**
 * xiebaoma
 * 2025-09-17
 */

#include <iostream>
#include <algorithm>
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
    int calculateDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(calculateDepth(root->left), calculateDepth(root->right)) + 1;
    }
};
