/**
 * xiebaoma
 * 2025-07-03
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int len = s.size();
        int slow = 0;
        int fast = 0;
        int ret = 0;
        vector<int> vec(256, 0);
        while (fast < len)
        {
            if (vec[s[fast]] == 0)
            {
                vec[s[fast]]++;
            }
            else
            {
                while (vec[s[fast]] > 0)
                {
                    vec[s[slow]]--;
                    slow++;
                }
                vec[s[fast]]++;
            }
            ret = max(ret, fast - slow + 1);
            fast++;
        }
        return ret;
    }
};