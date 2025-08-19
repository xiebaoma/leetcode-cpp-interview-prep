/**
 * xiebaoma
 * 2025-08-19
 */

#include <vector>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long ans = 0;
        int last = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i])
            {
                last = i; // 记录上一个非 0 元素的位置
            }
            else
            {
                ans += i - last;
            }
        }
        return ans;
    }
};
