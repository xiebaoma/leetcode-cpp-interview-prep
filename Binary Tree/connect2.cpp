/**
 * xiebaoma
 * 2025-07-10
 */

#include <cstddef>
#include <queue>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if(root==nullptr){
            return root;
        }
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<Node *> nodes;
            while (!q.empty())
            {
                Node *node = q.front();
                q.pop();
                nodes.push_back(node);
            }
            for (int i = 0; i < nodes.size(); i++)
            {
                if (i == nodes.size() - 1)
                {
                    nodes[i]->next = nullptr;
                }
                else
                {
                    nodes[i]->next = nodes[i + 1];
                }
                if (nodes[i]->left)
                {
                    q.push(nodes[i]->left);
                }
                if (nodes[i]->right)
                {
                    q.push(nodes[i]->right);
                }
            }
        }
        return root;
    }
};