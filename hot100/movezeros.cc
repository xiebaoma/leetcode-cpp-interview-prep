/**
 * xiebaoma
 * 2025-11-26
 */

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=-1;
        int j=0;
        while (j<nums.size())
        {
            if (nums[j]!=0)
            {
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
    }
};