/**
 * xiebaoma
 * 2025-07-06
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        int slow = -1;
        int fast = 0;
        while (fast < len)
        {
            if (nums[fast] != val)
            {
                slow++;
                swap(nums[slow], nums[fast]);
            }
            else
            {
            }
            fast++;
        }
        return slow + 1;
    }
};