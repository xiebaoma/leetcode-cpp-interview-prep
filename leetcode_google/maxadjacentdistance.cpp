/**
 * xiebaoma
 * 2025-06-25
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxAdjacentDistance(vector<int> &nums)
    {
        int ret = 0;
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            if (i == len - 1)
            {
                ret = max(ret, abs(nums[i] - nums[0]));
            }
            else
            {
                ret = max(ret, abs(nums[i + 1] - nums[i]));
            }
        }
        return ret;
    }
};