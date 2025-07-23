/**
 * xiebaoma
 * 2025-07-23
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

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int pleft, int pright, int ileft, int iright)
    {
        if (pleft > pright)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(preorder[pleft]);
        int rootindex = map[preorder[pleft]];
        int presize = rootindex - ileft;
        root->left = build(preorder, inorder, pleft+1, pleft + presize, ileft, rootindex - 1);
        root->right = build(preorder, inorder, pleft + presize + 1, pright, rootindex + 1, iright);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        for (int i = 0; i < inorder.size(); i++)
        {
            map[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};