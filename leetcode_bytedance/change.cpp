/**
 * xiebaoma
 * 2025-09-10
 */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1), valid(amount + 1);
        dp[0] = 1;
        valid[0] = 1;
        for (int &coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                valid[i] |= valid[i - coin];
            }
        }
        if (!valid[amount])
            return 0;
        for (int &coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
