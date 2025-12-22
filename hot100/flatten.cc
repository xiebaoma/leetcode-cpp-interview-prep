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

    void inorder(vector<TreeNode*>& nodes, TreeNode* root)
    {
        if (!root) return;
        nodes.push_back(root);
        inorder(nodes,root->left);
        inorder(nodes,root->right);
    }

    void flatten(TreeNode* root) {
        vector<TreeNode*> nodes;
        if (!root) return;
        inorder(nodes,root);
        TreeNode* pre = root;
        for (int i=1;i<nodes.size();i++)
        {
            pre->right=nodes[i];
            pre->left=nullptr;
            pre=pre->right;
        }
        pre->left=nullptr;
    }
};