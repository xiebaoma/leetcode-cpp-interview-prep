/**
 * xiebaoma
 * 2025-06-28
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int slow = -1;
        int fast = 0;
        int len = nums.size();
        while (fast < len)
        {
            if (slow == -1)
            {
                slow++;
                nums[slow] = nums[fast];
            }
            else
            {
                if (nums[fast] != nums[slow])
                {
                    slow++;
                    nums[slow] = nums[fast];
                }
            }
            fast++;
        }
        return slow + 1;
    }
};