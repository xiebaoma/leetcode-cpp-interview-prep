/**
 * xiebaoma
 * 2025-12-18
 */

#include <vector>
using namespace std;

//[2,0,2,1,1,0]
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=-1;
        int j=0;
        while (j<nums.size())
        {
            if (nums[j]==0)
            {
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
        j=i+1;
        while (j<nums.size())
        {
            if (nums[j]==1)
            {
                i++;
                swap(nums[i],nums[j]);
            }
            j++;
        }
    }
};