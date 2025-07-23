/**
 * xiebaoma
 * 2025-07-23
 */

#include <cstddef>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    bool hasnode(TreeNode *root, TreeNode *p)
    {
        if (root == p)
        {
            return true;
        }
        if (root == nullptr)
        {
            return false;
        }
        return hasnode(root->left, p) || hasnode(root->right, p);
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == p || root == q)
        {
            return root;
        }
        if (hasnode(root->left, p) && hasnode(root->left, q))
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (hasnode(root->right, p) && hasnode(root->right, q))
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        return root;
    }
};