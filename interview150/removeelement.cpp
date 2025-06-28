/**
 * xiebaoma
 * 2025-06-28
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int len = nums.size();
        int isindex = -1;
        int notindex = 0;
        while (notindex < len)
        {
            if (nums[notindex] != val)
            {
                isindex++;
                swap(nums[isindex], nums[notindex]);
            }
            notindex++;
        }
        return isindex + 1;
    }
};