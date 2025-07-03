/**
 * xiebaoma
 * 2025-07-03
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int len = nums.size();
        int slow = 0;
        int fast = 0;
        int ret = len;
        int sum = nums[0];
        bool valid = false;
        while (fast < len)
        {
            if (sum >= target)
            {
                valid = true;
                ret = min(ret, fast - slow + 1);
                sum -= nums[slow];
                slow++;
            }
            else if (sum < target)
            {
                fast++;
                if (fast >= len)
                {
                    break;
                }
                sum += nums[fast];
            }
        }
        if (valid)
        {
            return ret;
        }
        return 0;
    }
};