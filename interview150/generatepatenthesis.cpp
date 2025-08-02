/**
 * xiebaoma
 * 2025-08-01
 */

#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    void dfs(vector<string>& ret, string s, int open , int close, int n){
        if(s.size()==n*2){
            ret.push_back(s);
        }
        if(open<n){
            s.push_back('(');
            dfs(ret,s,open+1,close,n);
            s.pop_back();
        }
        if(close<open){
            s.push_back(')');
            dfs(ret,s,open,close+1,n);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string s = "";
        vector<string> ret;
        dfs(ret, s, 0,0,n);
        return ret; 
    }
};