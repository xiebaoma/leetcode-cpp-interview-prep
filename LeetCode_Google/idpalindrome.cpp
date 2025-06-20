/**
 * xiebaoma
 * 2025-06-20
 */

#include <climits>

// 121
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int y = x;
        int ret = 0;
        while (x > 0)
        {
            int temp = x % 10;
            if (ret > (INT_MAX - temp) / 10)
            {
                return false;
            }
            ret = ret * 10 + temp;
            x = x / 10;
        }
        return y == ret;
    }
};