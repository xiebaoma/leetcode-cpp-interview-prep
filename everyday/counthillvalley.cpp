/**
 * xiebaoma
 * 2025-07-27
 */

#include <vector>
using namespace std;

//[6,6,5,5,4,1]
class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int i = 1;
        int count = 0;
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] == nums[i - 1])
                i++;
            if (i < n && nums[i] > nums[i - 1])
            {
                while (i < n && nums[i] >= nums[i - 1])
                {
                    i++;
                }
                if (i < n)
                    count++;
            }
            if (i < n && nums[i] < nums[i - 1])
            {
                while (i < n && nums[i] <= nums[i - 1])
                {
                    i++;
                }
                if (i < n)
                    count++;
            }
        }
        return count;
    }
};