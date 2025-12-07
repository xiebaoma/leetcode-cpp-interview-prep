#include <vector>
#include <iostream>
using namespace std;

void backtrace(int n,vector<int>& cur, vector<bool>& used, vector<vector<int>>& res)
{
    if (cur.size()==n)
    {
        res.push_back(cur);
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (!used[i])
        {
            used[i]=true;
            cur.push_back(i);
            backtrace(n,cur,used,res);
            cur.pop_back();
            used[i]=false;
        }
    }
}

int main()
{
    int n=3;
    vector<bool> used(n+1,false);
    vector<vector<int>> res;
    vector<int> cur;

    backtrace(n,cur,used,res);
    for (int i=0;i<res.size();i++)
    {
        for (int j=0;j<res[i].size();j++)
        {
            cout<<res[i][j];
        }
        cout<<endl;
    }
    return 0;
}
