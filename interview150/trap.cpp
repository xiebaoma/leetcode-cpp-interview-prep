/**
 * xiebaoma
 * 2025-07-01
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int len = height.size();
        vector<int> left(len);
        vector<int> right(len);
        int max = 0;
        for (int i = 0; i < len; i++)
        {
            if (i == 0)
            {
                left[i] = 0;
                max = height[i];
            }
            else
            {
                if (height[i] < max)
                {
                    left[i] = max - height[i];
                }
                else
                {
                    left[i] = 0;
                    max = height[i];
                }
            }
        }
        max = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            if (i == len - 1)
            {
                right[i] = 0;
                max = height[i];
            }
            else
            {
                if (height[i] > max)
                {
                    right[i] = 0;
                    max = height[i];
                }
                else
                {
                    right[i] = max - height[i];
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < len; i++)
        {
            ret += min(left[i], right[i]);
        }
        return ret;
    }
};