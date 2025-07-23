/**
 * xiebaoma
 * 2025-07-23
 */

#include <vector>
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
    vector<int> vec;
    void findval(TreeNode *root, int origin)
    {
        int val = root->val;
        origin = origin * 10 + val;
        if (root->left == nullptr && root->right == nullptr)
        {
            vec.push_back(origin);
            return;
        }
        if (root->left)
        {
            findval(root->left, origin);
        }
        if (root->right)
        {
            findval(root->right, origin);
        }
    }
    int sumNumbers(TreeNode *root)
    {
        findval(root, 0);
        int ret = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            ret += vec[i];
        }
        return ret;
    }
};