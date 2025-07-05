/**
 * xiebaoma
 * 2025-07-05
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
        int len = intervals.size();
        vector<vector<int>> ret;
        int first = intervals[0][0];
        int second = intervals[0][1];
        int i = 1;
        while (i < len)
        {
            int f = intervals[i][0];
            int s = intervals[i][1];
            if (f > second)
            {
                vector<int> temp{first, second};
                ret.push_back(temp);
                first = f;
                second = s;
            }
            else
            {
                second = max(second, s);
            }
            i++;
        }
        vector<int> temp{first, second};
        ret.push_back(temp);
        return ret;
    }
};