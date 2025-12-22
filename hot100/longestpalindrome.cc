/**
 * xiebaoma
 * 2025-12-18
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        vector<vector<bool>> isvalid(len, vector<bool>(len, false));
        for (int i=0;i<len;i++)
        {
            isvalid[i][i]=true;
        }
        int res=1;
        int maxi=0;
        for (int n=2;n<=len;n++)
        {
            for (int i=0;i<=len-n;i++)
            {
                int j=i+n-1;
                if (s[i]==s[j])
                {
                    if (i==j-1 || isvalid[i+1][j-1])
                    {
                        isvalid[i][j]=true;
                        if (j-i+1 > res)
                        {
                            res=j-i+1;
                            maxi= i;
                        }
                    }else
                    {
                        isvalid[i][j]=false;
                    }
                }else
                {
                    isvalid[i][j]=false;
                }
            }
        }
        return s.substr(maxi,res);
    }
};