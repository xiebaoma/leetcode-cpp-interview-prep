/**
 * xiebaoma
 * 2025-07-22
 */

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
    bool check(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left == nullptr || right == nullptr)
        {
            return false;
        }
        if (left->val != right->val)
        {
            return false;
        }
        return check(left->left, right->right) && check(left->right, right->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root)
        {
            return check(root->left, root->right);
        }
        return false;
    }
};