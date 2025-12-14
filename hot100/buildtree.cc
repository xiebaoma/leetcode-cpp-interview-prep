/**
* Definition for a binary tree node.
 *
 */

#include <vector>
#include <unordered_map>
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
    unordered_map<int, int> premap;

    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pleft, int pright, int ileft, int iright)
    {
        if (pleft>pright)
        {
            return nullptr;
        }
        int val = preorder[pleft];
        TreeNode* root= new TreeNode(val);
        int rootindex= premap[val];
        int presize=rootindex-ileft;
        root->left=build(preorder,inorder,pleft+1,pleft+presize,ileft,rootindex-1);
        root->right=build(preorder,inorder,pleft+presize+1,pright,rootindex+1,iright);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0;i<inorder.size();i++)
        {
            premap[inorder[i]]=i;
        }
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};