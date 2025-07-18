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
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ret;
        if (intervals.empty())
        {
            return ret;
        }
        int first = intervals[0][0];
        int second = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] > second)
            {
                vector<int> temp{first, second};
                ret.push_back(temp);
                first = intervals[i][0];
                second = intervals[i][1];
            }
            else
            {
                second = max(second, intervals[i][1]);
            }
        }
        vector<int> temp{first, second};
        ret.push_back(temp);
        return ret;
    }
};