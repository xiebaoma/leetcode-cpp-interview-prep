/**
 * xiebaoma
 * 2025-07-23
 */

#include<vector>
#include<unordered_map>
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
    unordered_map<int,int> map;
    TreeNode* build(vector<int> &inorder, vector<int> &postorder,int ileft, int iright, int pleft, int pright)
    {
        if(ileft>iright){
            return nullptr;
        }
        TreeNode * root= new TreeNode(postorder[pright]);
        int rootindex= map[postorder[pright]];
        int size= rootindex- ileft;
        root->left=build(inorder, postorder, ileft,rootindex-1,pleft, pleft+size-1);
        root->right=build(inorder,postorder,rootindex+1,iright,pleft+size,pright-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n= inorder.size();
        for(int i=0;i<inorder.size();i++){
            map[inorder[i]]=i;
        }
        return build(inorder,postorder,0,n-1,0,n-1);
    }
};