/**
 * xiebaoma
 * 2025-06-21
 */

#include <vector>
using namespace std;

/*
numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]  0123 0213
*/

class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> result;
    bool valid = true;

    void dfs(int i)
    {
        visited[i] = 1;
        for (int v : edges[i])
        {
            if (visited[v] == 0)
            {
                dfs(v);
                if (!valid)
                {
                    return;
                }
            }
            else if (visited[v] == 1)
            {
                valid = false;
                return;
            }
        }
        visited[i] = 2;
        result.push_back(i);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (auto &it : prerequisites)
        {
            edges[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < numCourses && valid; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        if (!valid)
        {
            return {};
        }
        reverse(result.begin(), result.end());
        return result;
    }
};