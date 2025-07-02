/**
 * xiebaoma
 * 2025-07-02
 */

#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string ret = "";
        int n = strs.size();
        int m = strs[0].size();
        for (int j = 0; j < m; j++)
        {
            char c = strs[0][j];
            for (int i = 1; i < n; i++)
            {
                if (j >= strs[i].size() || strs[i][j] != c)
                {
                    return ret;
                }
            }
            ret += c;
        }
        return ret;
    }
};