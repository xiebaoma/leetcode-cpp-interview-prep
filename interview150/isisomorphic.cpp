/**
 * xiebaoma
 * 2025-07-10
 */

#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;
        for (int i = 0; i < s.size(); i++)
        {
            char sc = s[i];
            char tc = t[i];
            if (smap.find(sc) != smap.end() && tmap.find(tc) != tmap.end())
            {
                if (smap[sc] != tc || tmap[tc] != sc)
                {
                    return false;
                }
            }
            else if (smap.find(sc) == smap.end() && tmap.find(tc) == tmap.end())
            {
                smap[sc] = tc;
                tmap[tc] = sc;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};