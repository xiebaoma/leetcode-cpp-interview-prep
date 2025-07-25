/**
 * xiebaoma
 * 2025-07-25
 */

#include<vector>
#include<queue>
#include<algorithm>
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
    int getMinimumDifference(TreeNode *root)
    {
        if(!root) return 0;
        vector<int> vec;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int n= q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                vec.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
        }
        if(vec.size()==0){
            return 0;
        }
        sort(vec.begin(),vec.end());
        int ret = INT_MAX;
        for(int i=1;i<vec.size();i++){
            ret=min(ret,vec[i]-vec[i-1]); 
        }
        return ret;
    }
};