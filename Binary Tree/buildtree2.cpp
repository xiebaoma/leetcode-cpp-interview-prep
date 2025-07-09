/**
 * xiebaoma
 * 2025-07-09
 */

#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> inmap;
    TreeNode *build(vector<int> &preorder, int prel, int prer, vector<int> &inorder, int inl, int inr)
    {
        if (prel > prer || inl > inr)
        {
            return nullptr;
        }

        int firstval = preorder[prel];
        TreeNode *root = new TreeNode(firstval);

        int inindex = inmap[firstval];
        int presize = inindex - inl;

        root->left = build(preorder, prel + 1, prel + presize, inorder, inl, inindex - 1);
        root->right = build(preorder, prel + 1 + presize, prer, inorder, inindex + 1, inr);
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inmap[inorder[i]] = i;
        }
        int prel = 0;
        int prer = preorder.size() - 1;
        int inl = 0;
        int inr = inorder.size() - 1;
        return build(preorder, prel, prer, inorder, inl, inr);
    }
};