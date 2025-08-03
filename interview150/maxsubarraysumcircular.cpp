/**
 * xiebaoma
 * 2025-08-03
 */

#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int total = 0;
        int maxSum = INT_MIN, curMax = 0;
        int minSum = INT_MAX, curMin = 0;

        for (int num : nums)
        {
            curMax = max(curMax + num, num);
            maxSum = max(maxSum, curMax);

            curMin = min(curMin + num, num);
            minSum = min(minSum, curMin);

            total += num;
        }

        // 全部是负数的情况：total == minSum，不能选择空子数组
        if (maxSum < 0)
            return maxSum;

        return max(maxSum, total - minSum);
    }
};
