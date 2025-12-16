/**
* Definition for a binary tree node.
 *
 */

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class Solution {
public:

    bool check(TreeNode* root, TreeNode* node)
    {
        if (!root) return false;
        if (root==node) return true;
        return check(root->left,node) || check(root->right,node);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==p || root==q) return root;
        if (!check(root->left,p) && !check(root->left,q))
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        if (!check(root->right,p) && !check(root->right,q))
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};