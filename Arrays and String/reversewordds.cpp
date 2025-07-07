/**
 * xiebaoma
 * 2025-07-07
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int len = s.size();
        int slow = 0;
        int fast = 0;
        while (fast < len)
        {
            if (s[slow] != ' ' && s[fast] != ' ')
            {
                fast++;
            }
            else if (s[slow] != ' ' && s[fast] == ' ')
            {
                reverse(s.begin() + slow, s.begin() + fast);
                slow = fast;
            }
            else
            {
                slow++;
                fast++;
            }
        }
        reverse(s.begin() + slow, s.end());
        return s;
    }
};