/**
 * xiebaoma
 * 2025-12-09
 */

#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for (int num:nums)
        {
            res^=num;
        }
        return res;
    }
};