/**
 * xiebaoma
 * 2025-07-23
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
    vector<int> vec;
    void preorder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        vec.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode *root)
    {
        if(root==nullptr){
            return;
        }
        preorder(root);
        TreeNode *node = root;
        node->left=nullptr;
        for (int i = 1; i < vec.size(); i++)
        {
            node->right = new TreeNode(vec[i]);
            node = node->right;
        }
    }
};