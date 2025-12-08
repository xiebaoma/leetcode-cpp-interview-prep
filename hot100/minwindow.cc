/**
 * xiebaoma
 * 2025-12-08
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char,int> tmap;
    unordered_map<char,int> cur;

    bool check()
    {
        for (auto it:tmap)
        {
            if (cur[it.first]<it.second) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        for (char c: t)
        {
            tmap[c]++;
        }
        int l=0;
        int r=0;
        int len =INT_MAX;
        int ansl=-1;
        while (r<s.size())
        {
            if (tmap.find(s[r])!=tmap.end())
            {
                cur[s[r]]++;
            }
            while (check())
            {
                if (r-l+1<len)
                {
                    ansl=l;
                    len =r-l+1;
                }
                if (tmap.find(s[l])!=tmap.end())
                {
                    cur[s[l]]--;
                }
                l++;
            }
            r++;
        }
        return len==INT_MAX ? "" : s.substr(ansl,len);
    }
};