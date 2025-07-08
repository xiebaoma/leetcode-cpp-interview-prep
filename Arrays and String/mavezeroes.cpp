/**
 * xiebaoma
 * 2025-07-08
 */

#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int len = nums.size();
        int slow = -1;
        int fast = 0;
        while (fast < len)
        {
            if (nums[fast] != 0)
            {
                slow++;
                swap(nums[slow], nums[fast]);
            }
            fast++;
        }
    }
};