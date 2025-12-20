/**
 * xiebaoma
 * 2025-12-19
 */

#include <vector>
using namespace std;

//1 5 8 4 7 6 5 3 1
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=nums.size()-2;
        while (i>=0 && nums[i]>=nums[i+1])
        {
            i--;
        }
        if (i>=0)
        {
            int j = nums.size()-1;
            while (j>=0 && nums[i]>=nums[j])
            {
                j--;
            }
            swap(nums[i],nums[j]);
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};