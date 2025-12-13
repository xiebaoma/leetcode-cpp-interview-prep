/**
 * xiebaoma
 * 2025-06-24
 * 超时
 */

#include <string>
#include <set>
#include <vector>
using namespace std;

// zab
class Solution
{
public:
    int findSubstringInWraproundString(string s)
    {
        set<string> mset;
        int n = s.size();
        vector<vector<bool>> vec(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++)
        {
            vec[i][i] = true;
            mset.emplace(string(1, s[i]));
        }
        int index = 0;
        while (index < n - 1)
        {
            int j = index + 1;
            int i = index;
            while (j < n)
            {
                if (s[j - 1] == 'z')
                {
                    if (s[j] == 'a' && vec[i][j - 1] == true)
                    {
                        vec[i][j] = true;
                        mset.emplace(s.substr(i, j - i + 1));
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    if (s[j] == s[j - 1] + 1 && vec[i][j - 1] == true)
                    {
                        vec[i][j] = true;
                        mset.emplace(s.substr(i, j - i + 1));
                    }
                    else
                    {
                        break;
                    }
                }
                j++;
            }
            index++;
        }
        return mset.size();
    }
};