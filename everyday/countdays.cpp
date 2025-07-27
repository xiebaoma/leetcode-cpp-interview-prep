/**
 * xiebaoma
 * 2025-07-11
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        if (meetings.empty())
            return days;

        // 先按起始时间排序
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> merged;
        int start = meetings[0][0], end = meetings[0][1];

        for (int i = 1; i < meetings.size(); i++)
        {
            if (meetings[i][0] <= end)
            {
                // 有重叠，更新end
                end = max(end, meetings[i][1]);
            }
            else
            {
                // 没有重叠，保存之前的区间，更新start和end
                merged.push_back({start, end});
                start = meetings[i][0];
                end = meetings[i][1];
            }
        }
        // 最后一个区间别忘记加进去
        merged.push_back({start, end});

        // 统计会议占据的天数
        int occupied = 0;
        for (auto &interval : merged)
        {
            occupied += interval[1] - interval[0] + 1; // 包含首尾
        }

        return days - occupied;
    }
};