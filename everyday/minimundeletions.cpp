/**
 * xiebaoma
 * 2025-06-21
 */

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// word = "aabcaba", k = 0            124
// word = "dabdcbdcdcd", k = 2         1235   235   234
class Solution
{
public:
    int minimumDeletions(string word, int k)
    {
        unordered_map<char, int> map;
        int ret = word.size();
        for (char &c : word)
        {
            map[c]++;
        }
        for (auto &it : map)
        {
            int dnum = 0;
            int count = it.second;
            for (auto &ot : map)
            {
                int freq = ot.second;
                if (freq < count)
                    dnum += freq;
                if (freq > count + k)
                    dnum += (freq - count - k);
            }
            ret = min(ret, dnum);
        }
        return ret;
    }
};