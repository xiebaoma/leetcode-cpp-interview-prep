/**
 * xiebaoma
 * 2025-06-21
 */

#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

// i i+1 [i+1]
//[1,2,3,4,5,6,7]
//[1,10,1,1]
class Solution
{
public:
    unordered_map<int, int> map;

    int dp(const vector<int> &prices, int index)
    {
        int len = prices.size();
        if ((index + 1) * 2 >= len)
        {
            return prices[index];
        }
        if (!map.count(index))
        {
            int minnum = INT_MAX;
            for (int i = index + 1; i <= (index + 1) * 2; i++)
            {
                minnum = min(minnum, prices[index] + dp(prices, i));
            }
            map[index] = minnum;
        }
        return map[index];
    }

    int minimumCoins(vector<int> &prices)
    {
        return dp(prices, 0);
    }
};