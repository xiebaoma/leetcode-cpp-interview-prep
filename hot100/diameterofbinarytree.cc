/**
* Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include <algorithm>
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

    int depth(TreeNode* root)
    {
        if (!root) return 0;
        return 1+max(depth(root->left),depth(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int hasroot= depth(root->left)+depth(root->right);

        int left = diameterOfBinaryTree(root->left);
        int right= diameterOfBinaryTree(root->right);

        int res= max(hasroot,max(left,right));
        return res;
    }
};