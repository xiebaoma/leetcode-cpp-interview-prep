/**
* Definition for a binary tree node.
 *
 */

#include <vector>
using namespace std;

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };

class Solution {
public:
    void inorder(vector<int>& res,TreeNode* root,int k)
    {
        if (!root) return;
        inorder(res,root->left,k);
        res.push_back(root->val);
        if (res.size()==k) return;
        inorder(res,root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        inorder(res, root,k);
        return res[k-1];
    }
};