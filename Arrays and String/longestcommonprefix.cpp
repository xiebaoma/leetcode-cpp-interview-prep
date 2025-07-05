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
    string longestCommonPrefix(vector<string> &strs)
    {
        string ret = "";
        int len = strs.size();
        int flen = strs[0].size();
        for (int j = 0; j < flen; j++)
        {
            char c = strs[0][j];
            for (int i = 0; i < len; i++)
            {
                if (strs[i][j] != c)
                {
                    return ret;
                }
            }
            ret += c;
        }
        return ret;
    }
};