/**
 * xiebaoma
 * 2025-07-30
 */

#include<vector>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& ret, int index, int n, int k, vector<int>& cur)
    {
        if(cur.size()==k)
        {
            ret.push_back(cur);
            return;
        }
        for(int i=index;i<=n;i++)
        {
            cur.push_back(i);
            dfs(ret,i+1,n,k,cur);
            cur.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(ret, 1, n, k,cur);
        return ret;
    }
};