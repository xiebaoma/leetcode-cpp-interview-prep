/**
 * xiebaoma
 * 2025-06-27
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> visited;
    Node *cloneGraph(Node *node)
    {
        if (node == nullptr)
        {
            return node;
        }
        if (visited.find(node) != visited.end())
        {
            return visited[node];
        }
        Node *newnode = new Node(node->val);
        visited[node] = newnode;
        for (Node *old : node->neighbors)
        {
            Node *nodenew = cloneGraph(old);
            newnode->neighbors.push_back(nodenew);
        }
        return newnode;
    }
};