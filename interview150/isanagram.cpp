/**
 * xiebaoma
 * 2025-07-11
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> smap;
        unordered_map<char, int> tmap;
        if (s.size() != t.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        for (auto &it : smap)
        {
            char c = it.first;
            int cnt = it.second;
            if (tmap[c] != cnt)
            {
                return false;
            }
        }
        return true;
    }
};