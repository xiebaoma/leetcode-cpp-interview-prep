/**
 * xiebaoma
 * 2025-06-29
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int lastday = days[days.size() - 1];
        unordered_set<int> outdays;
        for (int i : days)
        {
            outdays.emplace(i);
        }
        vector<int> dp(lastday + 1);
        dp[0] = 0;
        int ret = 0;
        for (int i = 1; i <= lastday; i++)
        {
            if (outdays.find(i) == outdays.end())
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = dp[i - 1] + costs[0];
                dp[i] = min(dp[i], dp[max(0, i - 7)] + costs[1]);
                dp[i] = min(dp[i], dp[max(0, i - 30)] + costs[2]);
            }
        }
        return dp[lastday];
    }
};