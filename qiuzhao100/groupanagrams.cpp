#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> smap;
        for(string& s: strs){
            string str=s;
            sort(s.begin(),s.end());
            smap[s].push_back(str);
        }
        for(auto& it: smap){
            res.push_back(it.second);
        }
        return res;
    }
};