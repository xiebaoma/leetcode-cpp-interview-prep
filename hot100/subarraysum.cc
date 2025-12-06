/**
 * xiebaoma
 * 2025-12-01
 */

#include <vector>
#include <unordered_map>
using namespace std;

//nums = [1,1,1], k = 2
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res=0;
        unordered_map<int,int> pre;
        pre[0]=1;
        int sum=0;
        for (int num:nums)
        {
            sum+=num;
            if (pre[sum-k]!=0)
            {
                res+=pre[sum-k];
            }
            pre[sum]++;
        }
        return res;
    }
};