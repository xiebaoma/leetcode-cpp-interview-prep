/**
 * xiebaoma
 * 2025-06-27
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool valid = true;
    void dp(vector<int> &visit, unordered_map<int, vector<int>> &map, int id)
    {
        visit[id] = 1;
        vector<int> &nextcouses = map[id];
        for (int co : nextcouses)
        {
            if (visit[co] == 0)
            {
                dp(visit, map, co);
                if (!valid)
                    return;
            }
            else if (visit[co] == 1)
            {
                valid = false;
                return;
            }
        }
        visit[id] = 2;
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> map;
        for (auto &it : prerequisites)
        {
            map[it[1]].push_back(it[0]);
        }
        vector<int> visit(numCourses, 0);
        for (auto &pre : map)
        {
            if (visit[pre.first] != 2)
            {
                dp(visit, map, pre.first);
            }
        }
        return valid;
    }
};