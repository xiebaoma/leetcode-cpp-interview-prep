/**
 * xiebaoma
 * 2025-06-19
 */

#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int ret = 0;
        int slow = 0;
        int fast = 0;
        unordered_set<char> set;
        while (fast < s.size())
        {
            if (set.find(s[fast]) != set.end())
            {
                while (s[slow] != s[fast])
                {
                    set.erase(s[slow]);
                    slow++;
                }
                slow++;
            }
            else
            {
                set.emplace(s[fast]);
                ret = max(fast - slow + 1, ret);
            }
            fast++;
        }
        return ret;
    }
};

int main()
{
    return 0;
}