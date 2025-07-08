/**
 * xiebaoma
 * 2025-07-08
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
            if (fast == 0)
            {
                slow++;
            }
            else if (nums[fast] != nums[slow])
            {
                slow++;
                swap(nums[slow], nums[fast]);
            }
            fast++;
        }
        return slow + 1;
    }
};