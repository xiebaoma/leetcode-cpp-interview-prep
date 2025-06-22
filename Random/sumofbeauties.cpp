/**
 * xiebaoma
 * 2025-06-22
 */

#include <vector>
#include <climits>
using namespace std;

// nums = [1,2,3]
class Solution
{
public:
    int sumOfBeauties(vector<int> &nums)
    {
        int ret = 0;
        int len = nums.size();
        vector<int> minvec(len, 1);
        minvec[len - 1] = INT_MAX;
        vector<int> maxvec(len, 1);
        maxvec[0] = 0;
        for (int i = 1; i < len; i++)
        {
            maxvec[i] = max(maxvec[i - 1], nums[i - 1]);
        }
        for (int i = len - 2; i >= 0; i--)
        {
            minvec[i] = min(minvec[i + 1], nums[i + 1]);
        }
        for (int i = 1; i <= len - 2; i++)
        {
            if (nums[i] > maxvec[i] && nums[i] < minvec[i])
            {
                ret += 2;
            }
            else if (nums[i] > nums[i - 1] && nums[i] < nums[i + 1])
            {
                ret += 1;
            }
            else
            {
                ret += 0;
            }
        }
        return ret;
    }
};
