/**
 * xiebaoma
 * 2025-07-02
 */

#include <string>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string ret = "";
        for (char c : s)
        {
            if (isalnum(c))
            {
                ret += tolower(c);
            }
        }
        string re(ret.rbegin(), ret.rend());
        return re == ret;
    }
};