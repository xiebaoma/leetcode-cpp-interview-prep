/**
 * xiebaoma
 * 2025-07-01
 */

#include <string>
using namespace std;

class Solution
{
public:
    int possibleStringCount(string word)
    {
        int ret = 0;
        int slow = 0;
        int fast = 0;
        int len = word.length();
        while (fast < len)
        {
            if (word[fast] == word[slow])
            {
                fast++;
            }
            else
            {
                if (fast - slow >= 2)
                {
                    ret += fast - slow - 1;
                }
                slow = fast;
            }
        }
        if (fast - slow >= 2)
        {
            ret += fast - slow-1;
        }
        return ret + 1;
    }
};