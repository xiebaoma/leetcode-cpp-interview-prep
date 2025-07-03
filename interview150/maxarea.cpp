/**
 * xiebaoma
 * 2025-07-03
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0;
        int len = height.size();
        int right = len - 1;
        int ret = 0;
        while (left < right)
        {
            int temp = (right - left) * min(height[left], height[right]);
            ret = max(ret, temp);
            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return ret;
    }
};