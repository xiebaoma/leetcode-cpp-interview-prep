/**
 * xiebaoma
 * 2025-11-30
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int i=0;
        int j=0;
        unordered_map<char,int> smap;
        while (j<s.size())
        {
            if (smap[s[j]]==0)
            {
                smap[s[j]]++;
                j++;
                res=max(res,j-i);
            }else
            {
                while (smap[s[j]]!=0)
                {
                    smap[s[i]]--;
                    i++;
                }
                smap[s[j]]++;
                j++;
            }
        }
        return res;
    }
};