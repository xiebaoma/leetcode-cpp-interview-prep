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
         TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };

class Solution {
    vector<int> dfs(TreeNode* root, int k) {
        vector<int> f(k + 1, 0);
        if (!root) return f;
        auto l = dfs(root->left, k);
        auto r = dfs(root->right, k);
        f[0] = *max_element(l.begin(), l.end()) + *max_element(r.begin(), r.end());
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < i; ++j) {
                f[i] = max(f[i], root->val + l[j] + r[i - j - 1]);
            }
        }
        return f;
    }
public:
    int maxValue(TreeNode* root, int k) {
        auto f = dfs(root, k);
        return *max_element(f.begin(), f.end());
    }
};
