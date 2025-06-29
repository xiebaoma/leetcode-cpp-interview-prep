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
        vector<int> minprice(len);
        minprice[0] = INT_MAX;
        int ret = 0;
        for (int i = 1; i < len; i++)
        {
            minprice[i] = min(prices[i - 1], minprice[i - 1]);
            ret = max(prices[i] - minprice[i], ret);
        }
        return ret;
    }
};