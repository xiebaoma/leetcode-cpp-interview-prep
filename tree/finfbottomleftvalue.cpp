/**
 * xiebaoma
 * 2025-06-22
 */

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
    int findBottomLeftValue(TreeNode *root)
    {
        int ret = 0;
        queue<TreeNode *> que;
        vector<vector<TreeNode *>> vecs;
        que.push(root);
        while (!que.empty())
        {
            vector<TreeNode *> vec;
            while (!que.empty())
            {
                TreeNode *node = que.front();
                que.pop();
                vec.push_back(node);
            }
            vecs.push_back(vec);
            for (auto it : vec)
            {
                if (it->left)
                    que.push(it->left);
                if (it->right)
                    que.push(it->right);
            }
        }
        int len = vecs.size();
        return vecs[len - 1][0]->val;
    }
};