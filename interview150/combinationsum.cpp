/**
 * xiebaoma
 * 2025-07-31
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void dfs(int index, vector<vector<int>> &ret, vector<int> &candidates, vector<int> &cur, int sum, int target)
    {
        if (sum == target)
        {
            ret.push_back(cur);
        }
        if (sum > target)
        {

            return;
        }
        for (int i = index; i < candidates.size(); i++)
        {
            cur.push_back(candidates[i]);
            sum += candidates[i];
            dfs(i, ret, candidates, cur, sum, target);
            sum -= candidates[i];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> cur;
        dfs(0, ret, candidates, cur, 0, target);
        return ret;
    }
};