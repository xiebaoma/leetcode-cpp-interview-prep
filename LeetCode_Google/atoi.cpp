/**
 * xiebaoma
 * 2025-06-20
 */

#include <string>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        string str;
        int i = 0;
        bool pos = true;
        int ret = 0;
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        if (i < s.size() && s[i] == '-')
        {
            pos = false;
            i++;
        }
        else if (i < s.size() && s[i] == '+')
        {
            i++;
        }

        while (i < s.size() && s[i] == '0')
        {
            i++;
        }
        while (i < s.size() && (s[i] >= '0' && s[i] <= '9'))
        {
            int val = s[i] - '0';
            if (ret > (INT_MAX - val) / 10)
            {
                if (!pos)
                {
                    ret = INT_MIN;
                }
                else
                {
                    ret = INT_MAX;
                }
                return ret;
            }
            ret = ret * 10 + val;
            i++;
        }
        return pos ? ret : -ret;
    }
};