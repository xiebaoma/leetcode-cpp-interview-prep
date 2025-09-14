/**
 * xiebaoma
 * 2025-09-14
 */

#include <iostream>
#include <cmath>
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
    int closestValue(TreeNode *root, double target)
    {
        int l = root->val, r = root->val;
        while (root)
        {
            if (target < root->val)
            {
                r = root->val;
                root = root->left;
            }
            else if (target > root->val)
            {
                l = root->val;
                root = root->right;
            }
            else
                return root->val;
        }
        return abs(target - l) <= abs(r - target) ? l : r;
    }
};
