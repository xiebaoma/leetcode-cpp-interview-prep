/**
 * xiebaoma
 * 2025-07-08
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        if (root == nullptr)
        {
            return ret;
        }
        q.push(root);
        while (!q.empty())
        {
            vector<int> vec;
            queue<TreeNode *> temp;
            while (!q.empty())
            {
                TreeNode *node = q.front();
                temp.push(node);
                q.pop();
                vec.push_back(node->val);
            }
            while (!temp.empty())
            {
                TreeNode *node = temp.front();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
                temp.pop();
            }
            ret.push_back(vec);
        }
        return ret;
    }
};