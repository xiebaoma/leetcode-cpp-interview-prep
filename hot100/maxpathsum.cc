/**
 * xiebaoma
 * 2025-12-09
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
    int maxsum=INT_MIN;
    int maxgain(TreeNode* root)
    {
        if (root==nullptr) return 0;
        int leftsum = max(maxgain(root->left),0);
        int rightsum= max(maxgain(root->right),0);
        maxsum = max(maxsum, root->val + leftsum + rightsum);
        return root->val + max(leftsum,rightsum);
    }
    int maxPathSum(TreeNode* root) {
        if (root== nullptr)
        {
            return 0;
        }
        maxgain(root);
        return maxsum;
    }
};