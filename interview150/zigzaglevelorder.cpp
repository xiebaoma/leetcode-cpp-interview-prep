/**
 * xiebaoma
 * 2025-07-25
 */

#include <vector>
#include <queue>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        queue<TreeNode *> q;
        q.push(root);
        int count = 0;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> vec;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                vec.push_back(node->val);
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (count % 2 == 1)
                reverse(vec.begin(), vec.end());
            ret.push_back(vec);
            count++;
        }
        return ret;
    }
};