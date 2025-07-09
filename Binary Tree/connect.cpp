/**
 * xiebaoma
 * 2025-07-09
 */

#include <cstddef>
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
    void dfs(Node *left, Node *right)
    {
        if (left == nullptr)
        {
            return;
        }
        left->next = right;
        right->next = nullptr;
        dfs(left->left, left->right);
        dfs(left->right, right->left);
        dfs(right->left, right->right);
    }
    Node *connect(Node *root)
    {
        if(root==nullptr){
            return nullptr;
        }
        dfs(root->left, root->right);
        return root;
    }
};