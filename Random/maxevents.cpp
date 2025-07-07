/**
 * xiebaoma
 * 2025-07-07
 */

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // 按照会议开始时间排序
        sort(events.begin(), events.end());

        // 最小堆：维护当前可参加会议的 endDay
        priority_queue<int, vector<int>, greater<int>> minHeap;

        int day = 1;
        int i = 0;
        int n = events.size();
        int res = 0;

        // 遍历从 day = 1 到最后一天（最大 endDay）
        while (i < n || !minHeap.empty()) {
            // 如果堆为空，直接跳到下一个会议的 startDay
            if (minHeap.empty()) {
                day = events[i][0];
            }

            // 当前时间点加入所有可开始的会议（startDay <= day）
            while (i < n && events[i][0] <= day) {
                minHeap.push(events[i][1]);
                i++;
            }

            // 清除已经过期的会议（endDay < day）
            while (!minHeap.empty() && minHeap.top() < day) {
                minHeap.pop();
            }

            // 参加最早结束的会议
            if (!minHeap.empty()) {
                minHeap.pop();
                res++;
                day++; // 下一天
            }
        }

        return res;
    }
};
