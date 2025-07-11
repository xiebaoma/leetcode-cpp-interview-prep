/**
 * xiebaoma
 * 2025-07-11
 */

#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string change(string s){
        sort(s.begin(),s.end());
        return s;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        if(strs.empty()){
            return ret;
        }
        unordered_map<string ,vector<string>> map;
        for(string& s: strs){
            string str= change(s);
            map[str].push_back(s);
        }
        for(auto& it: map)
        {
            ret.push_back(it.second);
        }
        return ret;
    }
};