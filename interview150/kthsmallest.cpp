/**
 * xiebaoma
 * 2025-07-26
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
    int count = 0;
    int ret;
    void indfs(TreeNode *root, int k)
    {
        if (!root)
        {
            return;
        }
        indfs(root->left,k);
        count++;
        if (count == k)
        {
            ret = root->val;
        }
        indfs(root->right,k);
    }
    int kthSmallest(TreeNode *root, int k)
    {
        indfs(root, k);
        return ret;
    }
};