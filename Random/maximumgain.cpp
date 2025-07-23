/**
 * xiebaoma
 * 2025-07-23
 */

#include <string>
using namespace std;

class Solution
{
public:
    int maximumGain(string s, int x, int y)
    {
        if (x < y)
        {
            swap(x, y);
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == 'a')
                {
                    s[i] = 'b';
                }
                else if (s[i] == 'b')
                {
                    s[i] = 'a';
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int cntA = 0, cntB = 0;
            while (i < s.size() && (s[i] == 'a' || s[i] == 'b'))
            {
                if (s[i] == 'a')
                {
                    cntA++;
                }
                else
                {
                    if (cntA > 0)
                    {
                        cntA--;
                        ans += x;
                    }
                    else
                    {
                        cntB++;
                    }
                }
                i++;
            }
            ans += min(cntA, cntB) * y;
        }
        return ans;
    }
};
