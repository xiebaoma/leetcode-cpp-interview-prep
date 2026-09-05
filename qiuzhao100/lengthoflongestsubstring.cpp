#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s==""){
            return 0;
        }
        int res=1;
        unordered_set<int> substr;
        int i=0;
        int j=1;
        substr.emplace(s[i]);
        while(j<s.size()){
            if(substr.find(s[j])==substr.end()){
                substr.emplace(s[j]);
            }else{
                while(substr.find(s[j])!=substr.end()){
                    substr.erase(s[i]);
                    i++;
                }
                substr.emplace(s[j]);
            }
            j++;
            res= max(res,j-i);
        }
        return res;
    }
};