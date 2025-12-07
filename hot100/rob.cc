/**
 * xiebaoma
 * 2025-12-07
 */

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int res=0;
        int n =nums.size();
        vector<int> counts(n);
        if (nums.size()==0)
        {
            return 0;
        }
        counts[0]=nums[0];
        if (nums.size()==1)
        {
            return nums[0];
        }
        counts[1]=max(nums[0],nums[1]);
        for (int i=2;i<n;i++)
        {
            counts[i]=max(counts[i-1],counts[i-2]+nums[i]);
        }
        return counts[n-1];
    }
};