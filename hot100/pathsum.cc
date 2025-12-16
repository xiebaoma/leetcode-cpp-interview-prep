/**
* Definition for a binary tree node.
 *
 */

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

    int rootsum(TreeNode* root, long long targetSum)
    {
        if (!root)
        {
            return 0;
        }
        int res=0;
        if (root->val==targetSum) res++;
        res+=rootsum(root->left,targetSum-root->val);
        res+=rootsum(root->right,targetSum-root->val);
        return res;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
        {
            return 0;
        }
        int ret=rootsum(root,targetSum);
        ret+=pathSum(root->left,targetSum);
        ret+=pathSum(root->right,targetSum);
        return ret;
    }
};