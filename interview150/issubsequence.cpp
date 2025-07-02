/**
 * xiebaoma
 * 2025-07-02
 */

#include <string>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int si = 0;
        int ti = 0;
        int sl = s.size();
        int tl = t.size();
        while (ti < tl)
        {
            if (si == sl)
            {
                return true;
            }
            if (s[si] == t[ti])
            {
                si++;
            }
            ti++;
        }
        if (si == sl)
            return true;
        return false;
    }
};