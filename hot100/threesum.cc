/**
 * xiebaoma
 * 2025-11-29
 */

#include <vector>
using namespace std;

//[-1,0,1,2,-1,-4]
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for (int first= 0;first<n-2;first++)
        {
            if (first>0 && nums[first]==nums[first-1])
            {
                continue;
            }
            int val =nums[first];
            if (val>0) break;
            int third = n-1;
            for (int second =first+1;second<n-1;second++)
            {
                if (second>first+1 && nums[second]==nums[second-1]) continue;
                while (third>second && nums[third]+nums[second]>-val)
                {
                    third--;
                }
                if (third==second) break;
                if (nums[third]+nums[second]==-val)
                {
                    vector <int> cur={nums[first],nums[second],nums[third]};
                    res.push_back(cur);
                }
            }
        }
        return res;
    }
};
