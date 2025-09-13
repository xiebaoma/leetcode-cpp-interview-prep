/**
 * xiebaoma
 * 2025-09-13
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
            {
                return i;
            }
        }
        return n;
    }
};
