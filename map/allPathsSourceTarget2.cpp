/**
 * xiebaoma
 * 2025-06-28
 */

#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ret;
        vector<int> path;
        queue<vector<int>> que;
        if (graph.size() == 0)
        {
            return ret;
        }
        path.push_back(0);
        que.push(path);
        while (!que.empty())
        {
            path = que.front();
            que.pop();
            int node = path[path.size() - 1];
            if (node == graph.size() - 1)
            {
                ret.push_back(path);
                continue;
            }
            for (int n : graph[node])
            {
                vector<int> newpath(path);
                newpath.push_back(n);
                que.push(newpath);
            }
        }
        return ret;
    }
};