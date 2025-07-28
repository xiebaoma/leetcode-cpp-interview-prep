/**
 * xiebaoma
 * 2025-07-28
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    unordered_map<int, vector<int>> map;
    vector<int> visit;
    vector<int> ret;
    bool valid;

    void dfs(int i)
    {
        visit[i] = 1;
        vector<int> nextcouses = map[i];
        for (int nextid : nextcouses)
        {
            if (visit[nextid] == 1)
            {
                valid = false;
                return;
            }
            else if (visit[nextid] == 0)
            {
                dfs(nextid);
            } 
        }
        visit[i] = 2;
        ret.push_back(i);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
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
        if (!valid)
        {
            return vector<int>();
        }
        else
        {
            reverse(ret.begin(),ret.end());
            return ret;
        }
    }
};