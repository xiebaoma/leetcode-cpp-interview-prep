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
    unordered_map<int, int> map;
    TreeNode *build(vector<int> &inorder, int inl, int inr,
                    vector<int> &postorder, int posl, int posr)
    {
        if (inl > inr || posl > posr)
        {
            return nullptr;
        }

        int val = postorder[posr];
        TreeNode *root = new TreeNode(val);
        int i = map[val];
        int leftsize = i - inl;

        root->left = build(inorder, inl, i - 1, postorder, posl, posl + leftsize - 1);
        root->right = build(inorder, i + 1, inr, postorder, posl + leftsize, posr - 1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }
        int inl = inorder.size() - 1;
        int posl = postorder.size() - 1;
        return build(inorder, 0, inl, postorder, 0, posl);
    }
};