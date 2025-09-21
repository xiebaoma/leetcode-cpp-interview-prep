/**
 * xiebaoma
 * 2025-09-21
 */

#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        // 检查基本情况。如果没有间隔，返回 0
        if (intervals.size() == 0)
        {
            return 0;
        }
        // 最小堆
        priority_queue<int, vector<int>, greater<int>> allocator;
        // 根据开始时间排序会议
        sort(intervals.begin(), intervals.end());
        allocator.emplace(intervals[0][1]);
        // 遍历剩余会议
        for (int i = 1; i < intervals.size(); i++)
        {
            // 如果最早应该腾出的房间是空闲的，则将该房间分配给本次会议。
            if (intervals[i][0] >= allocator.top())
            {
                allocator.pop();
            }
            // 如果要分配一个新房间，那么我们也要添加到堆中，
            // 如果分配了一个旧房间，那么我们还必须添加到具有更新的结束时间的堆中。
            allocator.emplace(intervals[i][1]);
        }
        // 堆的大小告诉我们所有会议所需的最小房间。
        return allocator.size();
    }
};
