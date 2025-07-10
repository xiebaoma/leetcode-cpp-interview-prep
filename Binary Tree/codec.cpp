/**
 * xiebaoma
 * 2025-07-10
 */

#include <string>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            if (!curr)
            {
                ans += '#';
                ans += ',';
                continue;
            }
            ans += to_string(curr->val);
            ans += ',';
            q.push(curr->left);
            q.push(curr->right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> ans;
        string res = "";
        for (auto c : data)
        {
            if (c == ',')
            {
                ans.push_back(res);
                res = "";
            }
            else
                res += c;
        }
        if (ans.size() == 0)
            return nullptr;
        TreeNode *root = new TreeNode(stoi(ans[0]));
        queue<TreeNode *> q;
        q.push(root);
        int rootInt = 0;
        while (rootInt * 2 + 1 < ans.size())
        {
            int childInt = rootInt * 2 + 1;
            string datain = ans[childInt];
            TreeNode *curr = q.front();
            q.pop();
            if (datain != "#")
            {
                curr->left = new TreeNode(stoi(datain));
                q.push(curr->left);
            }
            if (childInt + 1 < data.size())
            {
                datain = ans[childInt + 1];
                if (datain != "#")
                {
                    curr->right = new TreeNode(stoi(datain));
                    q.push(curr->right);
                }
            }
            rootInt++;
        }
        return root;
    }
};
