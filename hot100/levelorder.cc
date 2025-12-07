/**
 * xiebaoma
 * 2025-12-07
 */

#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if (!root) return res;
        q.push(root);
        while (!q.empty())
        {
            queue<TreeNode*> tmp;
            while (!q.empty())
            {
                tmp.push(q.front());
                q.pop();
            }
            vector<int> nums;
            while (!tmp.empty())
            {
                TreeNode* node=tmp.front();
                nums.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right)q.push(node->right);
                tmp.pop();
            }
            res.push_back(nums);
        }
        return res;
    }
};