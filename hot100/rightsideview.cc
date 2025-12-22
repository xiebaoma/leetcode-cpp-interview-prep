/**
* Definition for a binary tree node.
 *
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<TreeNode*> cur;
            while (!q.empty())
            {
                cur.push_back(q.front());
                q.pop();
            }
            int val = cur[cur.size()-1]->val;
            res.push_back(val);
            for (int i=0;i<cur.size();i++)
            {
                if (cur[i]->left) q.push(cur[i]->left);
                if (cur[i]->right)q.push(cur[i]->right);
            }
        }
        return res;
    }
};