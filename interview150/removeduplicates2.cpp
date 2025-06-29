/**
 * xiebaoma
 * 2025-06-29
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
        bool issecond = false;
        while (fast < len)
        {
            if (slow == -1)
            {
                slow++;
                nums[slow] = nums[fast];
                issecond = false;
            }
            else
            {
                if (nums[fast] != nums[slow])
                {
                    slow++;
                    nums[slow] = nums[fast];
                    issecond = false;
                }
                else
                {
                    if (!issecond)
                    {
                        slow++;
                        nums[slow] = nums[fast];
                        issecond = true;
                    }
                }
            }
            fast++;
        }
        return slow + 1;
    }
};