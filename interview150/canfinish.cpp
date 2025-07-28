/**
 * xiebaoma
 * 2025-07-27
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<int, vector<int>> map;
    vector<int> visit;
    bool valid;
    void dfs(int i)
    {
        visit[i] = 1;
        vector<int> nextcourses = map[i];
        for (int id : nextcourses)
        {
            if (visit[id] == 1)
            {
                valid = false;
                return;
            }
            if (visit[id] == 0)
            {
                dfs(id);
            }
        }
        visit[i] = 2;
    }
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        valid = true;
        for (auto vec : prerequisites)
        {
            map[vec[1]].push_back(vec[0]);
        }
        visit.resize(numCourses, 0);
        for (int i = 0; i < numCourses; i++)
        {
            if (visit[i] == 0)
            {
                dfs(i);
            }
        }
        return valid;
    }
};