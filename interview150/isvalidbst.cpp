/**
 * xiebaoma
 * 2025-07-26
 */

#include <climits>
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
    bool helper(TreeNode *root, long long lower, long long upper)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val <= lower || root->val >= upper)
        {
            return false;
        }
        return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
    }
    bool isValidBST(TreeNode *root)
    {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};
