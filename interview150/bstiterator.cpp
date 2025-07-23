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

class BSTIterator
{
public:
    vector<int> vec;
    int index = 0;
    void inorder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }

    BSTIterator(TreeNode *root)
    {
        inorder(root);
    }

    int next()
    {
        return vec[index++];
    }

    bool hasNext()
    {
        return index < vec.size();
    }
};
