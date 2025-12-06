/**
* xiebaoma
* 2025-12-01
*/

#include <vector>
#include <string>
using namespace std;

//s = "cbaebabacd", p = "abc"
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> scount(26);
        vector<int> pcount(26);
        int len = p.size();
        if (s.size()<p.size()){
            return res;
        }
        for(int i=0;i<p.size();i++){
            scount[s[i]-'a']++;
            pcount[p[i]-'a']++;
        }
        if (scount==pcount)
        {
            res.push_back(0);
        }
        for (int i=0;i<s.size()-len;i++)
        {
            scount[s[i]-'a']--;
            scount[s[i+len]-'a']++;
            if (scount==pcount)
            {
                res.push_back(i+1);
            }
        }
        return res;
    }
};