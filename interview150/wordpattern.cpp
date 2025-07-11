/**
 * xiebaoma
 * 2025-07-11
 */

#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        istringstream iss(s);
        vector<string> result;
        string word;
        while (iss >> word)
        {
            result.push_back(word);
        }

        if (pattern.size() != result.size())
        {
            return false;
        }
        unordered_map<char, string> pmap;
        unordered_map<string, char> smap;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (pmap.find(pattern[i]) == pmap.end() && smap.find(result[i]) == smap.end())
            {
                pmap[pattern[i]] = result[i];
                smap[result[i]] = pattern[i];
            }
            else if (pmap[pattern[i]] != result[i] || smap[result[i]] != pattern[i])
            {
                return false;
            }
        }
        return true;
    }
};