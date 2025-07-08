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
    void post(TreeNode *root)
    {
        if (root != nullptr)
        {
            post(root->left);
            post(root->right);
            ret.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        post(root);
        return ret;
    }
};