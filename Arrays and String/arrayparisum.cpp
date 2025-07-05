/**
 * xiebaoma
 * 2025-07-05
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ret = 0;
        int len = nums.size();
        int i = 0;
        while (i < len)
        {
            ret += nums[i];
            i += 2;
        }
        return ret;
    }
};