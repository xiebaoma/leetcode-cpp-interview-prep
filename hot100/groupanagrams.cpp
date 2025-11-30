/**
 * xiebaoma
 * 2025-11-24
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for (string s: strs)
        {
            string key=s;
            sort(s.begin(),s.end());
            map[s].push_back(key);
        }
        vector<vector<string>> res;
        for (auto it: map)
        {
            res.push_back(it.second);
        }
        return res;
    }
};