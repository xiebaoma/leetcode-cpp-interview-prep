/**
 * xiebaoma
 * 2025-09-09
 */

#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Solution
{
public:
    void dfs(string &s, int pos, vector<string> &res)
    {
        while (pos < s.size() && isdigit(s[pos]))
        {
            pos++;
        }
        if (pos == s.size())
        {
            res.emplace_back(s);
            return;
        }
        s[pos] ^= 32;
        dfs(s, pos + 1, res);
        s[pos] ^= 32;
        dfs(s, pos + 1, res);
    }

    vector<string> letterCasePermutation(string s)
    {
        vector<string> ans;
        dfs(s, 0, ans);
        return ans;
    }
};
