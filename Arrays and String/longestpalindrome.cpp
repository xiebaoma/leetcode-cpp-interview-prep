/**
 * xiebaoma
 * 2025-07-05
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len <= 1)
            return s;

        vector<vector<bool>> dp(len, vector<bool>(len, false));
        string ret = s.substr(0, 1); // 至少是一个字符

        for (int i = 0; i < len; i++)
        {
            dp[i][i] = true;
        }

        // 注意：i 从大到小，j 从 i 向右
        for (int i = len - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < len; ++j)
            {
                if (s[i] == s[j])
                {
                    if (j - i == 1 || dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        if (j - i + 1 > ret.size())
                        {
                            ret = s.substr(i, j - i + 1);
                        }
                    }
                }
            }
        }

        return ret;
    }
};
