/**
 * xiebaoma
 * 2025-07-06
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int len = nums.size();
        int slow = 0;
        int fast = 0;
        int ret = 0;
        while (fast < len)
        {
            if (nums[slow] == 0 && nums[fast] == 0)
            {
                slow++;
                fast++;
            }
            else if (nums[slow] == 1 && nums[fast] == 1)
            {
                fast++;
            }
            else
            {
                ret = max(ret, fast - slow);
                slow = fast;
            }
        }
        if (slow < fast)
        {
            ret = max(ret, fast - slow);
        }
        return ret;
    }
};