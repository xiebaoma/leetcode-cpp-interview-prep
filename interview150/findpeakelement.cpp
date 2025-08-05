/**
 * xiebaoma
 * 2025-08-05
 */

#include<vector>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=0;
        while(i < nums.size()-1){
            if(nums[i+1]> nums[i]){
                i++;
            }else{
                return i;
            }
        }
        if(i==nums.size()-1){
            return i;
        }
        return 0;
    }
};