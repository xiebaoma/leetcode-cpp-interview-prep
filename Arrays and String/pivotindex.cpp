/**
 * xiebaoma
 * 2025-07-05
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> left(len);
        left[0] = 0;
        vector<int> right(len);
        right[len - 1] = 0;
        for (int i = 1; i < len; i++)
        {
            left[i] = left[i - 1] + nums[i - 1];
        }
        for (int i = len - 2; i >= 0; i--)
        {
            right[i] = right[i + 1] + nums[i + 1];
        }
        int ret = -1;
        int i = 0;
        while (i < len)
        {
            if (left[i] == right[i])
            {
                ret = i;
                break;
            }
            i++;
        }
        return ret;
    }
};