/**
 * xiebaoma
 * 2025-07-08
 */

#include <vector>
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
    vector<int> ret;
    void preordered(TreeNode *root)
    {
        if (root != nullptr)
        {
            ret.push_back(root->val);
            preordered(root->left);
            preordered(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        preordered(root);
        return ret;
    }
};