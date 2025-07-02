/**
 * xiebaoma
 * 2025-07-02
 */

#include <string>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int len = s.size();
        int left = len - 1;
        int right = len - 1;
        while (s[right] == ' ')
        {
            right--;
        }
        left = right;
        while (left>=0 && s[left] != ' ')
        {
            left--;
        }
        return right - left;
    }
};