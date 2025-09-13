/**
 * xiebaoma
 * 2025-09-13
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return true;
        }

        // 注意：C++ 排序函数会自动首先按第一个元素对向量排序，然后按第二个元素排序，依此类推。
        sort(intervals.begin(), intervals.end());
        for (size_t i = 0; i < intervals.size() - 1; i++)
        {
            if (intervals[i][1] > intervals[i + 1][0])
            {
                return false;
            }
        }
        return true;
    }
};
