/**
 * xiebaoma
 * 2025-07-25
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> set;
        int poscount = 0;
        int maxpos = INT_MIN;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0 && set.find(nums[i]) == set.end())
            {
                sum += nums[i];
                set.emplace(nums[i]);
            }
            if (nums[i] < 0)
            {
                poscount++;
                maxpos = max(nums[i], maxpos);
            }
        }
        if (poscount == n)
        {
            return maxpos;
        }
        return sum;
    }
};