/**
 * xiebaoma
 * 2025-07-28
 */

#include<vector>
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int> &nums)
    {
        int n = nums.size(), maxValue = 0, cnt = 0, stateNumber = 1 << n;
        for (int i = 0; i < stateNumber; i++)
        {
            int cur = 0;
            for (int j = 0; j < n; j++)
            {
                if (((i >> j) & 1) == 1)
                {
                    cur |= nums[j];
                }
            }
            if (cur == maxValue)
            {
                cnt++;
            }
            else if (cur > maxValue)
            {
                maxValue = cur;
                cnt = 1;
            }
        }
        return cnt;
    }
};
