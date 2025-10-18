/**
 * xiebaoma
 * 2025-10-13
 */

#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)
        {
            return "";
        }
        vector<vector<bool>> vec(n, vector<bool>(n, false));
        int maxlen = 1;
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            vec[i][i] = true;
        }
        for (int len = 2; len <= n; len++)
        {
            for (int i = 0; i <= n - len; i++)
            {
                int j = i + len - 1;
                if (s[i] == s[j])
                {
                    if ((j == i + 1) || (vec[i + 1][j - 1]))
                    {
                        vec[i][j] = true;
                        if (maxlen < j - i + 1)
                        {
                            maxlen = j - i + 1;
                            index = i;
                        }
                    }
                }
            }
        }
        return s.substr(index, maxlen);
    }
};