/**
 * xiebaoma
 * 2025-009-21
 */

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        int left = -1;
        int right = 0;
        int n = nums.size();
        while (right < n)
        {
            if (nums[right] % 2 == 0)
            {
                left++;
                swap(nums[left], nums[right]);
            }
            right++;
        }
        return nums;
    }
};