/**
 * xiebaoma
 * 2025-06-29
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int slow = 0;
        int fast = 0;
        int len = nums.size();
        while (fast < len)
        {
            if (nums[fast] != nums[slow])
            {
                int n = fast - slow;
                if (n > len / 2)
                {
                    return nums[slow];
                }
                else
                {
                    slow = fast;
                }
            }
            fast++;
        }
        return nums[slow];
    }
};