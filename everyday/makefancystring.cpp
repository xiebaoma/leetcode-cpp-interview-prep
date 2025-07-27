/**
 * xiebaoma
 * 2025-07-21
 */

#include <string>
using namespace std;

class Solution
{
public:
    string makeFancyString(string s)
    {
        int slow = -1;
        int fast = 0;
        int count = 0;
        while (fast < s.size())
        {
            if (fast == 0)
            {
                slow++;
                s[slow] = s[fast];
                fast++;
                count++;
            }
            else
            {
                if (s[fast] == s[slow])
                {
                    if (count == 2)
                    {
                        fast++;
                    }
                    else
                    {
                        slow++;
                        s[slow] = s[fast];
                        count++;
                        fast++;
                    }
                }
                else
                {
                    count = 1;
                    slow++;
                    s[slow] = s[fast];
                    fast++;
                }
            }
        }
        return s.substr(0, slow + 1);
    }
};