/**
 *xiebaoma
 *2025-11-25
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset;
        for (int num: nums)
        {
            numset.emplace(num);
        }
        int res=0;
        for (const int& num: numset)
        {
            if (!numset.count(num-1))
            {
                int curlen=1;
                int curnum= num;
                while (numset.count(curnum+1))
                {
                    curlen ++;
                    curnum++;
                }
                res=max(res,curlen);
            }
        }
        return res;
    }
};