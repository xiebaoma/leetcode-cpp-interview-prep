/**
 * xiebaoma
 * 2025-07-18
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.empty())
        {
            return 0;
        }
        int ret = 1;
        sort(points.begin(), points.end());
        int right = points[0][1];
        for (auto &it : points)
        {
            if (it[0] > right)
            {
                ret++;
                right = it[1];
            }
            else
            {
                right = min(right, it[1]);
            }
        }
        return ret;
    }
};