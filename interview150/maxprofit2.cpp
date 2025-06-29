/**
 * xiebaoma
 * 2025-06-29
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        int cur = prices[0];
        int ret = 0;
        for (int i = 0; i < len; i++)
        {
            if (prices[i] > cur)
            {
                ret += prices[i] - cur;
                cur = prices[i];
            }
            else
            {
                cur = prices[i];
            }
        }
        return ret;
    }
};