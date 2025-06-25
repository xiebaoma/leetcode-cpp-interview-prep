/**
 * xiebaoma
 * 2025-06-25
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        vector<vector<int>> vec(n, {0, 0});
        for (int i = 0; i < n; i++)
        {
            vec[i][0] = ages[i];
            vec[i][1] = scores[i];
        }
        sort(vec.begin(), vec.end());
        int ret = 0;
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (vec[i][1] >= vec[j][1])
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += vec[i][1];
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};