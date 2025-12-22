/**
 * xiebaoma
 * 2025-12-13
 */

#include <vector>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;

    void backtrace(vector<int>& nums,int first)
    {
        if (first==nums.size()-1)
        {
            res.push_back(nums);
            return;
        }
        for (int i=first;i<nums.size();i++)
        {
            swap(nums[i],nums[first]);
            backtrace(nums,first+1);
            swap(nums[i],nums[first]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrace(nums,0);
        return res;
    }
};