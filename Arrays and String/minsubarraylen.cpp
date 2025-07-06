/**
 * xiebaoma
 * 2025-07-06
 */

#include <vector>
using namespace std;

// 7
//[2,3,1,2,4,3]
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int len = nums.size();
        int slow = 0;
        int fast = 0;
        int sum = 0;
        int ret = len;
        while (fast < len)
        {
            if (sum < target)
            {
                sum += nums[fast];
                fast++;
            }
            else
            {
                while (sum >= target)
                {
                    ret = min(ret, fast - slow);
                    sum -= nums[slow];
                    slow++;
                }
            }
        }
        while (sum >= target)
        {
            ret = min(ret, fast - slow);
            sum -= nums[slow];
            slow++;
        }
        if(slow==0 && sum<target){
            return 0;
        }
        return ret;
    }
};