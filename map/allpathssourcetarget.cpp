/**
 * xiebaoma
 * 2025-06-28
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &ret, vector<int> &path, vector<vector<int>> &graph)
    {
        path.push_back(node);
        if (node == graph.size() - 1)
        {
            vector<int> temp(path);
            ret.push_back(temp);
            return;
        }
        vector<int> &nextvec = graph[node];
        for (int next : nextvec)
        {
            dfs(next, ret, path, graph);
            path.erase(path.end() - 1);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ret;
        if (graph.size() == 0)
        {
            return ret;
        }
        vector<int> path;
        dfs(0, ret, path, graph);
        return ret;
    }
};