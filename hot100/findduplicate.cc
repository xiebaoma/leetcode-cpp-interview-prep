/**
 * xiebaoma
 * 2025-12-06
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> numset;
        int res=0;
        for (int num:nums)
        {
            if (numset.find(num)!=numset.end())
            {
                res=num;
                break;
            }
            numset.emplace(num);
        }
        return res;
    }
};