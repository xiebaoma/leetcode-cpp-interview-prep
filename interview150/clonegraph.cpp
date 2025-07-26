/**
 * xiebaoma
 * 2025-07-26
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
    unordered_map<Node *, Node *> map;

    Node *cloneGraph(Node *node)
    {
        if (!node)
        {
            return nullptr;
        }
        if (!map.count(node))
        {
            Node *newnode = new Node(node->val);
            map[node] = newnode;
            for (Node *subnode : node->neighbors)
            {
                Node *newsubnode = cloneGraph(subnode);
                newnode->neighbors.push_back(newsubnode);
            }
        }
        return map[node];
    }
};