/**
 * xiebaoma
 * 2025-12-07
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        if (prices.size()==0) return res;
        int minprice = prices[0];
        for (int price:prices)
        {
            minprice = min(minprice, price);
            res= max(res,price-minprice);
        }
        return res;
    }
};