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
    vector<vector<int>> edges;
    vector<int> ret;
    vector<int> visit;
    bool valid = true;

    void dp(int index)
    {
        visit[index] = 1;
        vector<int> &next = edges[index];
        for (int i : next)
        {
            if (visit[i] == 1)
            {
                valid = false;
                return;
            }
            else if (visit[i] == 0)
            {
                dp(i);
                if (valid == false)
                    return;
            }
        }
        visit[index] = 2;
        ret.push_back(index);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visit.resize(numCourses);
        for (auto &it : prerequisites)
        {
            edges[it[1]].push_back(it[0]);
        }
        for (int i = 0; i < numCourses && valid; i++)
        {
            if (visit[i]==0)
            {
                dp(i);
            }
        }
        if (!valid)
            return {};
        reverse(ret.begin(), ret.end());
        return ret;
    }
};